# Contributing to μOS 🥳

Welcome! And thanks for taking the time to contribute to MuOS. MuOS is an operating system, and as such, is composed of several components, suited for different types and
levels of developer's expertice. The main languages being used are C, C++ and the different Assembly flavors. However, for userspace applications, any language is ok as
long as it complies with the runtime constraints imposed by the system.

## μOS structure

MuOS is based on the microkernel model of operating system architecture, and it is characterized for being a multiserver operating system. OS services are provided by 
different servers that reside in different address spaces each. Communication between components is based on synchronous message passing with asynchronous notification.
The current components in the system are:

- The *Mel* μkernel
- The Anchor C Runtime Library (libanchor)

## Licenses and other legal issues

μOS is, and will always be, **free software**. The majority of the components are released under the *GNU-GPL* license and it is licensed as such as a whole. However, certain
components of the project may use less restrictive licenses, such as the **GNU-LGPL** and the **MIT-License**. Every component (be it executable, libraries, scripts, what
have you) must be released under GPL compatible licenses. This applies for software that *belongs* to the project itself, it does not restrain third party implementations
from adding proprietary programs to the system. However, all the code within this repository must be *GPL-Compatible* free software.

## A final piece of advice

Operating system's development is not easy, and its not hard... it's really hard; but be rather not discouraged by this perspective. The first attempts are always shocking,
but with proper design and following the right implementation techniques, it is not a problem impossible to solve. We would like all implementations to be quality code without
bugs and the highest throughput possible, but this should not discourage any newcomer to provide software for μOS: we are here to learn! 🧐 So... what do you say 😉? You in?
