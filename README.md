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

The project uses cmake to generate a makefile that builds and links the executable. You can run cmake directly to provide environment specific settings for your system, otherwise, I've created linux (possible mac) compatible make commands in the root directory that will build the project (i.e. `make build` or `make build-release`)

### Running

Depending on the build type, you'll find the executable in `build/<buildtype>/GhostHunter`