#include "CaesarCipher.hpp"

#include <string>
#include <iostream>

CaesarCipher::CaesarCipher(const std::size_t key) : key_{key}
{
}

CaesarCipher::CaesarCipher(const std::string& key) : key_{0}
{
    //Need to convert key from string to std::size_t and handle unsupplied key.    
    if (!key.empty()) {
        // Check input string IS a valid positive int then convert:
        for (const auto& elem : key) {
            if (!std::isdigit(elem)) {
                std::cerr
                    << "[error] cipher key must be unsigned long integer for Caeser cipher, \n"
                    << "     the supplied key of " << key
                    << " cannot be converted." << std::endl;
                return;
            }

            key_ = stoul(key);
        }
    }
}