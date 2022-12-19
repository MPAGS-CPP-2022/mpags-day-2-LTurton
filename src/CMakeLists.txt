# - Set CMake requirements, then declare project:
cmake_minimum_required(VERSION 3.2)
project(MPAGSCipher VERSION 0.10.0)

# - When MakeFiles are generated, output all command lines by default
# Do this so it is easy to see what compiler command/flags are used. 
# This can also be done by removing the following 'set' and running make as 'make VERBOSE=1'
set(CMAKE_VERBOSE_MAKEFILE ON)

# - Set C++ Standard
set (CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 20)

# - Add the MPAGSCipher subdirectory to the build
add_subdirectory(MPAGSCipher)

# - Declare the build of mpags-cipher main program
add_executable(mpags-cipher mpags-cipher.cpp)

# - Set Debug Flags
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Werror -Wfatal-errors -Wshadow -pedantic")

# - Enable Testing & Include Testing Subdirectory
enable_testing()
add_subdirectory(Testing)

#Link the  build to the MPAGSCipher Library
target_link_libraries(mpags-cipher PRIVATE MPAGSCipher)