# Ghost Hunter

An experiment in creating a Game State Engine in C++

"Ghost Hunter" is the name I gave the first game I ever made, back when I was just a wee lad, so the legacy has carried on here.

## Setup

### Prerequisites:

* [SDL2](https://www.libsdl.org/download-2.0.php)
  * [SDL prerequisites](https://wiki.libsdl.org/Installation)
* [SDL_Image 2.0](https://www.libsdl.org/projects/SDL_image/)
* [SDL_TTF 2.0](https://www.libsdl.org/projects/SDL_ttf/)
* [CMake](https://cmake.org/)

### Build

The project uses cmake to generate a makefile that builds and links the executable. You can run cmake directly to provide environment specific settings for your system, otherwise, I've created linux (possibly mac) compatible make commands in the root directory that will build the project (i.e. `make build` or `make build-release`)

### Running

Depending on the build type, you'll find the executable in `build/<buildtype>/GhostHunter`

There's also make targets to run the releases:

`make run`
`make run-release`

### Clean

Wipe the debug and release builds with:

`make clean`
`make clean-release`

### Advanced
By default, it will try to compile with clang, you can override this by calling cmake with `-DCMAKE_CXX_COMPILER=<C++ compiler of your choice>` set. 

For example: `cmake -DCMAKE_CXX_COMPILER=/usr/bin/g++ -DCMAKE_BUILD_TYPE=Release ../../src`