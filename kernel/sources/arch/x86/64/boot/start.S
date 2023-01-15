/*
 * Copyright (C) 2023 Javier Marrero
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
.file "start.S"
.section KTEXT32, "ax", @progbits
.align 4
.code32

#include <kernel/arch/x86/32/cpuid.h>
#include <kernel/arch/x86/32/pm.h>
#include <kernel/arch/x86/64/mm/globals.h>
#include <kernel/arch/x86/64/cpu.h>
#include <kernel/arch/asm.h>

.macro print msg
    movl    \msg, %esi
    call    _puts32
.endm

.macro error msg
    movl    \msg, %esi
    call    _puts32
.endm

FUNCTION(multiboot_image_start):
    cld
    cli

    // Set up the initial stack
    movl    $stack32_top, %esp

    // Print the initial status
    print   $status_begin

    // Load the GDT and the IDT
    lgdt    boot_gdt_ptr
    lidt    boot_idt_ptr

    # Kernel data and stack
	movw $IA32_GDT_SELECTOR(IA32_KDATA_DES), %cx
	movw %cx, %es
	movw %cx, %ds
	movw %cx, %ss

	# Simics seems to remove hidden part of GS on entering user mode
	# when _visible_ part of GS does not point to user-mode segment.
	movw $IA32_GDT_SELECTOR(IA32_UDATA_DES), %cx
	movw %cx, %fs
	movw %cx, %gs

	jmpl $IA32_GDT_SELECTOR(IA32_KTEXT32_DES), $.rendezvous
.rendezvous:

    print   $status_safe_pm

    # Save the eax and ebx registers
    movl    %eax, multiboot_eax
    movl    %ebx, multiboot_ebx

    # ===== Test CPUID availability =====
    pushf
    popl    %eax
    movl    %eax, %ecx
    xorl    $(1 << 21), %eax
    pushl   %eax
    popf
    pushf
    popl    %eax
    pushl   %ecx
    popf
    xorl    %eax, %ecx
    jnz     .cpuid_supported

    error   $err_cpuid

.cpuid_supported:
    # ===== Test CPUID extended information availability =====
    movl    $(INTEL_CPUID_EXTENDED), %eax
    cpuid
    cmpl    $(AMD_CPUID_EXTENDED), %eax
    jnb     .cpuid_extended_supported

    error   $err_cpuid_extended

.cpuid_extended_supported:
    # ===== Test Long mode availability =====
    movl    $(AMD_CPUID_EXTENDED), %eax
    cpuid
    test    $(1 << AMD_EXT_LONG_MODE), %edx
    jnz     .long_mode_supported

    error   $err_no_long_mode

.long_mode_supported:
    # ===== Test No-Execute bit =====
    test    $(1 << AMD_EXT_NOEXECUTE), %edx
    jnz     .noexecute_supported

    error   $err_no_execute

.noexecute_supported:
    # ===== Test FXSAVE/FXRESTORE =====
    movl    $(INTEL_CPUID_STANDARD), %eax
    cpuid
    bt      $(INTEL_FXSAVE), %edx
    jc      .fx_supported

    error   $err_fx

.fx_supported:

.init_longmode:
    print   $status_lm_supported
    call    muOS_BootMapVSpace

    # Enable 64-bit translation entries
    movl    %cr4, %eax
	orl     $CR4_PAE, %eax
	movl    %eax, %cr4

    # Load the PML4 table
    leal    VA2PA(ptl_0), %eax
    movl    %eax, %cr3

    # Switch to long mode
    movl    $AMD_MSR_EFER, %ecx
    rdmsr
    orl     $AMD_LME, %eax
    wrmsr

    print   $status_paging

    # Enable paging to activate long mode (set CR0.PG = 1)
	movl    %cr0, %eax
	orl     $CR0_PG, %eax
	movl    %eax, %cr0

    # Set the code segment and jump
    print   $status_ready

    jmpl    $IA32_GDT_SELECTOR(IA32_KTEXT_DES), $_start64

    # Control flow should not reach here
    error   $err_fall_through

    // Halt the kernel. Reaching this statement indicates a boot failure.
    // So, we probably would have to print an error message.
.epilogue:
    hlt
    jmp .epilogue

// ==================
//      MESSAGES
// ==================

err_no_cpuid:       .string "Error: Hardware does not supports CPUID instruction."
err_cpuid:          .string "Error: Hardware does not support cpuid instruction. System halted."
err_cpuid_extended: .string "Error: Hardware does not support cpuid extended functions. System halted."
err_fx:             .string "Error: FXSAVE/FXRESTORE instructions not available. System halt."
err_no_execute:     .string "Error: Hardware does not support NE bit. System halted."
err_no_long_mode:   .string "Error: Hardware is not 64 bit compatible. System halted."
err_fall_through:   .string "Error: Unexpected termination. System halted."

status_begin:           .string "[x86_64] Loading kernel...\r\n"
status_safe_pm:         .string "[x86_64] Entered protected mode...\r\n"
status_lm_supported:    .string "[x86_64] Long mode is available. Performing initialization.\r\n"
status_paging:          .string "[x86_64] Enabling paging and virtual address space...\r\n"
status_ready:           .string "[x86_64] calling C initialization routine.\r\n"

.section KDATA32, "aw", @progbits
.align 4

boot_gdt_ptr:
    .word   (IA32_GDT_NUM_ENTRIES * 8) - 1;
    .long   VA2PA(muOS_x86_GlobalDescriptorTable)

boot_idt_ptr:
    .word   0
    .long   0

multiboot_eax:
    .long 0

multiboot_ebx:
    .long 0

// =====================
//      64-bit code
// =====================
.code64
_start64:

    // Set up long mode stack
	movabsq $stack64_top, %rsp

	// Create the first stack frame
	pushq   $0
	movq    %rsp, %rbp

    // Pass the arguments
	movl multiboot_ebx, %edi
	movl multiboot_eax, %esi

    # Call the main function
    call   _main64

    movl    $.final_mistake, %esi
    movw    $0x3F8, %dx

1:

    lodsb
    cmpb    $0, %al
    je      halt

    outb    %al, %dx
    jmp     1b

halt:

    hlt
    jmp halt

.final_mistake: .string "[x86-64] Unexpected exception!"
