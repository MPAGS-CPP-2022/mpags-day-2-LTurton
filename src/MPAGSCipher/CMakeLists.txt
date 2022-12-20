# - Build sub-script for the MPAGSCipher Library

# - Declare The Build of the static MPAGSCipher Library
add_library(MPAGSCipher STATIC
        CipherMode.hpp
        CipherType.hpp
        CaesarCipher.hpp
        CaesarCipher.cpp
        ProcessCommandLine.hpp
        ProcessCommandLine.cpp
        TransformChar.hpp
        TransformChar.cpp
)

target_include_directories(MPAGSCipher
PUBLIC ${CMAKE_CURRENT_LIST_DIR}
)

target_compile_features(MPAGSCipher    
    PRIVATE cxx_std_11 cxx_auto_type cxx_constexpr cxx_range_for cxx_uniform_initialization
)