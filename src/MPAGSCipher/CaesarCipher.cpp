#include "CaesarCipher.hpp"
#include "CipherMode.hpp"
#include "Alphabet.hpp"

#include <iostream>
#include <string>

// Converts any given key into the correct range with % function:
CaesarCipher::CaesarCipher(const std::size_t key) : key_{key % Alphabet::size}
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

            key_ = stoul(key) % Alphabet::size;
        }
    }
    std::cout << "The Cipher Key is " << key_ << std::endl;
}

// Applies Ciphering:
std::string CaesarCipher::applyCipher(const std::string& inputText,
                                      const CipherMode encrypt) const
{
    std::string output_string{};
    int shift_pos{};

    // For each loop, for each member of array inputText do a thing to orgionalChar:
    for (const auto& origionalChar : inputText) {
        // Find Position in the Alphabet container:
        for (size_t i{0}; i < Alphabet::size; ++i) {
            if (origionalChar == Alphabet::alphabet[i]) {
                // Apply the chosen shift, and determine new character.
                // Then break out of alphabet loop.
                switch (encrypt) {
                    case CipherMode::Encrypt:
                        shift_pos = (i + key_) % Alphabet::size;
                        break;
                    case CipherMode::Decrypt:
                        shift_pos =
                            (i + Alphabet::size- key_) %
                            Alphabet::size;    // +SIZE deals with negative wrapping nicely.
                        break;
                }
                break;
            }
        }

        //Add Ciphered Result to Ouput:
        output_string += Alphabet::alphabet[shift_pos];
    }

    // Finally, return the output string
    return output_string;
}