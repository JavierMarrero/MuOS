![](https://img.shields.io/github/contributors/JavierMarrero/MuOS?style=for-the-badge)
![](https://img.shields.io/github/forks/JavierMarrero/MuOS?style=for-the-badge)
![](https://img.shields.io/github/stars/JavierMarrero/MuOS?style=for-the-badge)
![](https://img.shields.io/github/license/JavierMarrero/MuOS?style=for-the-badge)
![](https://img.shields.io/github/issues/JavierMarrero/MuOS?style=for-the-badge)

# μOS :computer::cuba:
> General purpose POSIX compatible operating system based on the ideas of Jochen Liedtke and the L4 microkernel family

Welcome to the MuOS project repository. MuOS *-also stylized, and rather preferred, μOS-* is a general purpose **POSIX** compliant operating systems designed for portability,
security, efficiency and a high degree of decomposition between components. μOS is *free sofware*, meaning that you are free to toy with the system and learn from it. The
system is designed around the concept of μ-kernel stablished in 1995 by the german computation scientist **Jochen Liedtke**, which states:

> A concept is tolerated inside the microkernel only if moving it outside the kernel, i.e., permitting competing implementations, would prevent the implementation of the 
> system's required functionality.

The μ-kernel is named Mel, after my best friend :white_heart:, and is a minimal microkernel providing only few abstactions and system calls. The bulk of the job is performed
by the several user space servers. The μ-kernel also offers support for orthogonal persistency and real-time operations.

## Table of contents

1. [How to?](#howto)
    1. [...build anything on the system?](#build)
    2. [...test the system?](#test)
2. [Credits](#credits)
3. [License](#license)
4. [Contributing](#contributing)

<a name="howto" />

## How to...?

μOS is not a small project, nor it produces a single monolithic binary. It is rather an umbrella of different projects, that coexist and need each other in order to work.
The compilation environment for operating systems is particularly fragile: the minimal desconfiguration may break up a perfectly well written code; so, if you find a bug
when attempting to try, compile or debug any of the code here, please submit an issue in our issues section. Without further ado, here are some how to's:

<a name="build" />  

### ...build anything on the system?

In order to compile software for a particular target, you are going to need a compatible compiler that compiles and links binaries for the target architecture. Currently,
only **GCC** is officially supported, but *clang* may also work at some extent. Not all the binaries within the system have the same build configuration, nor they are all
built in freestanding or hosted mode. The μ-kernel, for example, supports the bare ***-elf** targets of GCC, but also supports the custom μOS target, which builds software
both in freestanding and hosted mode. Please, check each package's individual instructions to perform successful builds.

<a name="test" />  

### ... test the system?

If you plan to test the system on real hardware, please have in mind that this software is provided as is, and we are not liable for any damage derived from the use of
this software whatsoever. For testing we use *QEMU* instead. QEMU is a hardware emulator and lets us try different hardware and software configurations based on how we
want to test the system. Also QEMU keeps us from burning our boxes, which is a big plus :wink:. You may click on [this](https://github.com/qemu/qemu) link to access to the
QEMU source mirror hosted on GitHub.

<a name="credits" />  

## Credits

The following list contains all the contributors to the project. Feel free to add yourself to the list of contributors if you did some cool change, but please,
keep the list alphabetically sorted so it gets easy to look for names. The following block describes what does all the letters means:

> **C**: country  
> **E**: e-mail     
> **D**: description  
> **GH**: GitHub account :octocat:  

### Authors:

- Javier Marrero
    - **C**: Cuba :cuba:
    - **D**: Founder and father of this project :monocle_face:
    - **E**: jv.freelancerdevteam.qba@gmail.com
    - **GH**: [JavierMarrero](https://github.com/JavierMarrero)    
    
<a name="license" />    
    
## License

μOS is, and **always will be** free software. The system as a whole is licensed under the **GNU-GPL** version 3. There are several other components licensed under less
restrictive license agreements but they are all compatible with the GNU-GPL. This will ensure the total freedom from the users of the system. Take a look at our license
[here](LICENSE.md).

<a name="contributing" />

## Contributing to the project

Congratulations! :clap::partying_face:, we are always in the need for contributors. Please, read our [contributor's guidelines](CONTRIBUTING.md) first. Then you're free to make shiny new super duper packages that integrate seamlessly with the code and philosophy of μOS. Please, also take a look to the [Code of Conduct](CODE_OF_CONDUCT.md),
it is always good to know what to do and what not to do.
