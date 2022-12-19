#include "CaesarCipher.hpp"

#include <iostream>
#include <string>

// Converts any given key into the correct range with % function:
CaesarCipher::CaesarCipher(const std::size_t key) : key_{key % ALPHABETSIZE_}
{
}

//Converts from string to useful numerical variable:
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

            key_ = stoul(key) % ALPHABETSIZE_;
        }
    }
    std::cout << "The Cipher Key is " << key_ << std::endl;
}

// Applies Ciphering:
std::string CaesarCipher::applyCipher(const std::string& inputText,
                                      const bool encrypt) const
{
    std::string output_string{};
    int shift_pos{};

    // For each loop, for each member of array inputText do a thing to orgionalChar:
    for (const auto& origionalChar : inputText) {
        // Find Position in the Alphabet container:
        for (size_t i{0}; i < ALPHABETSIZE_; ++i) {
            if (origionalChar == ALPHABET_[i]) {
                // Apply the chosen shift, and determine new character.
                // Then break out of alphabet loop.
                if (encrypt) {
                    shift_pos = (i + key_) % ALPHABETSIZE_;
                } else if (!encrypt) {
                    shift_pos =
                        (i + ALPHABETSIZE_ - key_) %
                        ALPHABETSIZE_;    // +SIZE deals with negative wrapping nicely.
                } else {
                    std::cout
                        << "Encrypt/decrypt not set, defaulting to decryption.";
                    shift_pos = (i + ALPHABETSIZE_ - key_) % ALPHABETSIZE_;
                }
                break;
            }
        }

        //Add Ciphered Result to Ouput:
        output_string += ALPHABET_[shift_pos];
    }

    // Finally, return the output string
    return output_string;
}