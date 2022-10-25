# Compiler & Generator

## Compiler

- Ref: https://zhuanlan.zhihu.com/p/357803433

- Compiling system has 3 main parties:
  - Front end: Words/grammar analysis, code->Abstract Syntax Tree
  - Optimizer: 
  - Back end: ->byte code/machine code, IR->ARM

### GCC, LLVM, CLang
- LLVM (by Chris Lattner from Apple) can be used as Back end
  - LLVM-GCC: GCC is front end
  - LLVM-Clang: CLang is front end 

- Clang is front end of LLVM

### GDB

- GNU debugger
  - if compiler supports DWARF format, then it can use GDB to debug


## CMake/Ninja

- 如何评价 CMake？ https://www.zhihu.com/question/276415476/answer/557715322

- CMake 
  - is not a build system but rather it's a build-system generator. It supports directory hierarchies and applications that depend on multiple libraries. It is used in conjunction with native build environments such as Make, Qt Creator, Ninja, Android Studio, Apple's Xcode, and Microsoft Visual Studio.

- Make

- Ninja

- Conan
  - C/C++ Open Source Pacakge Manager (MIT license) to create and share all your native binaries
  - https://conan.io/

- ConanCenter 
  - is the central repository where you can search and discover all of the available open source Conan packages created by the community. It includes recipe and configuration information, and makes it easy to see package metadata in the UI.

- JFrog Artifactory Community Edition C/C++
  - which is completely free to use, allows you to host your private packages on your own server. This solution delivers all the power and flexibility of JFrog Artifactory for Conan to the C/C++ world.


## CMake












