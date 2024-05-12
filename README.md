![C++ Logo](https://upload.wikimedia.org/wikipedia/commons/thumb/1/18/ISO_C%2B%2B_Logo.svg/213px-ISO_C%2B%2B_Logo.svg.png)

# cplings C++❤️

Greetings and welcome to `cplings`. This project contains small exercises to get you used to reading and writing C++ code. This includes reading and responding to compiler messages!

Alternatively, for a first-time C++ learner, there are several other resources:

- [learncpp.com](https://www.learncpp.com/) - The most comprehensive resource for learning C++, but a bit theoretical sometimes. You will be using this along with cplings!
- [A Tour of C++, from Bjarne Stroustrup](https://isocpp.org/tour) - Learn C++ by solving little exercises! It's almost like `cplings`, but online
- [The C++ FAQ](https://isocpp.org/wiki/faq)
- [C++ Core guidelines](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines)

*cplings got its inspiration from the magnificient [rustlings repository](https://github.com/rust-lang/rustlings), which aims at familiarizing newcomers to the Rust language. This repository is a sort of a fork of it but for the C++ language*


## Getting Started

You will need to have a C++ Compiler installed. You can get it by following the instructions below.

Install and Usage Demo video:

[![Install and Usage Demo](https://img.youtube.com/vi/18vNfxwU5n4/0.jpg)](https://youtu.be/18vNfxwU5n4)

## Windows
Visit https://visualstudio.microsoft.com/vs/community/ and download Visual Studio Community. 
When, installing it make sure to select Desktop development with C++ and then, in the "Installation details" menu enable support for the C++ CMake Tools for Windows

## Linux

Under Ubuntu, just run:

```bash
# Install the GNU C++ compiler, git and vscode
sudo apt install g++ cmake make gdb git
sudo snap install vscode
```

```bash
# Clone this repository
git clone https://github.com/rdjondo/cplings
cd cplings
mkdir build && cd build
cmake ..
make
```

You should expect the build to fail : your task is to fix each exercise for the build to succed.

## Windows
Install Visual Studio Community Edition and Git.

```cmd
# Clone this repository
git clone https://github.com/rdjondo/cplings

```

Open the folder cplings in Visual Studio. Add support for CMake and run a build. You should expect the build to fail : your task is to fix each exercise for the build to succed.


## Doing exercises

The exercises are sorted by topic and can be found in the subdirectory `cplings/exercises/<topic>`. For every topic there is an additional README file with some resources to get you started on the topic. We really recommend that you have a look at them before you start.

The task is simple. Most exercises contain an error that keeps them from compiling, and it's up to you to fix it! Some exercises are also run as tests, but cplings handles them all the same. To run the exercises in the recommended order, execute:

### In Linux
To run all exercises in predetermined order:

```bash
make
```

This will try to verify the completion of every exercise in a predetermined order (what we think is best for newcomers).

OR, to run a specific exercise, tell make with exercise to run. For example:

```bash
make variable2
```

### In Windows
Visual Studio will let you choose the specific exercise you would like to solve. 

## Hints
You will find some help for specific exercises in the hints directory. Please note that this is work in progress.

## Continuing On

Once you've completed cplings, put your new knowledge to good use! Continue practicing your C++ skills by building your own projects, contributing to cplings, or finding other open-source projects to contribute to.


## Uninstalling cplings

If you'd like to uninstall cplings, you can do so by simply deleting the cplings directory.

Now you should be done!


## Completion

cplings isn't done and could still be improved.
- More hints
- Structs and Classes
- Better ownership stuff
- Better safer programming, security stuff
- Threads
- Metaprogramming
- ??? probably more

If you are interested in improving or adding new ones, please feel free to contribute!

## Contributing

Contributions of any kind welcome!

Instructions : ... work in progress ...

## Some technical notes

The cpling build system based on CMake and [CPM.make](https://github.com/cpm-cmake/CPM.cmake) for package management

### How to use cmake
https://cliutils.gitlab.io/modern-cmake/

