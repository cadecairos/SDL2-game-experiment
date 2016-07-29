cmake_minimum_required(VERSION 2.6)
project(GhostHunter)

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3 -DNDEBUG")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++14")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -lSDL2 -lSDL2_image -lSDL2_ttf")

add_executable(GhostHunter main.cpp engine/StateEngine.cpp
               states/TitleState.cpp states/AreaState.cpp 
               lib/Util.cpp lib/Timer.cpp engine/StateEngine.h 
               lib/Util.h lib/Timer.h)
