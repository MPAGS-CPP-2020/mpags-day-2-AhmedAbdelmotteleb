#- Set CMake requirements then declare project
cmake_minimum_required (VERSION 3.2)
project (MPAGSCipher VERSION 0.1.0)

#- When MakeFiles are generated, output all command lines by default
set(CMAKE_VERBOSE_MAKEFILE ON)

#- Set the C++ standard directly
set(CMAKE_CXX_STANDARD 14)

#-Declare the build of mpags-cipher main program
add_executable(mpags-cipher 
mpags-cipher.cpp
MPAGSCipher/TransformChar.cpp
)

#-Use our standard set of flags
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Werror -Wfatal-errors -Wshadow -pedantic")

target_compile_features(mpags-cipher
PRIVATE cxx_auto_type cxx_range_for cxx_uniform_initialization
)