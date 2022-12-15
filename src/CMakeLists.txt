# - Set CMake requirements, then declare project:
cmake_minimum_required(VERSION 3.2)
project(MPAGSCipher VERSION 0.6.0)

# - When MakeFiles are generated, output all command lines by default
# Do this so it is easy to see what compiler command/flags are used. 
# This can also be done by removing the following 'set' and running make as 'make VERBOSE=1'
set(CMAKE_VERBOSE_MAKEFILE ON)

# - Set C++ Standard
set (CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 20)

# - Declare the build of mpags-cipher main program
add_executable(mpags-cipher 
        mpags-cipher.cpp
        MPAGSCipher/TransformChar.cpp)

# - Set Debug Flags
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Werror -Wfatal-errors -Wshadow -pedantic")

target_compile_features(mpags-cipher    
    PRIVATE cxx_std_11 cxx_auto_type cxx_constexpr cxx_range_for cxx_uniform_initialization
)

#Ensure CMAKE can find our custom headers:
target_include_directories(mpags-cipher
PRIVATE MPAGSCipher
)