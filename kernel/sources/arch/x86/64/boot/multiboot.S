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
.file "multiboot.S"
.section MULTIBOOT_HEADER, "ax", @progbits
.align 4


#define MULTIBOOT_HEADER_MAGIC          0x1BADB002

#define MULTIBOOT_INFO_MODS_ALIGN       0x1
#define MULTIBOOT_INFO_MMAP_AVAILABLE   0x2
#define MULTIBOOT_INFO_VIDEO_AVAILABLE  0x4
#define MULTIBOOT_INFO_FLAGS_SYMS1      0x10
#define MULTIBOOT_INFO_FLAGS_SYMS2      0x20
#define MULTIBOOT_INFO_FLAGS_MMAP       0x40
#define MULTIBOOT_INFO_AOUT_KLUDGE      0x10000

#define MULTIBOOT_HEADER_FLAGS          0x00010003

#define MULTIBOOT_CHECKSUM  -(MULTIBOOT_MAGIC_VALUE | MULTIBOOT_LOADER_FLAGS)

multiboot_header:
    .long   MULTIBOOT_HEADER_MAGIC
	.long   MULTIBOOT_HEADER_FLAGS
	.long   -(MULTIBOOT_HEADER_MAGIC + MULTIBOOT_HEADER_FLAGS)
	.long   multiboot_header
	.long   unmapped_start
	.long   0
	.long   0
	.long   multiboot_image_start
    .long   0
    .long   0
    .long   0
    .long   0

