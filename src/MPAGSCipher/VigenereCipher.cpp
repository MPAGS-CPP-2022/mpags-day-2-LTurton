#include "VigenereCipher.hpp"
#include "Alphabet.hpp"
#include "TransformChar.hpp"

#include <algorithm>
#include <iostream>
#include <string>

// Holds a string assigned by the setKey function
VigenereCipher::VigenereCipher(const std::string& key)
{
    // Set the given key
    this->setKey(key);
}

// Takes the std::string key, and calls setKey
void VigenereCipher::setKey(const std::string& key)
{
    // Store the key
    key_ = key;

    // Transliterate, capitalising and removing non-alpha chars:
    std::string transliterated_key_;
    for (std::size_t i{0}; i < key_.size(); ++i) {
        transliterated_key_ += transformChar(key_[i]);
    }
    key_.swap(transliterated_key_);

    // Check if the key is empty and replace with default if so
    if (key_.empty()) {
        key_ = "DEFAULTKEY";
        std::cerr
            << "[warning] key provided to VigenereCipher is empty, setting it to the default: "
            << key_ << std::endl;
    }

    // loop over the key
    for (const char letter : key_) {
        // Check if this letter already exists:
        if (charLookup_.find(letter) != charLookup_.end()) {
            continue;
        }

        // Find the letter position in the alphabet
        const std::size_t letter_pos = Alphabet::alphabet.find(letter);

        // Create a CaesarCipher using this position as a key
        std::pair<char, CaesarCipher> cipher_pair{letter,
                                                  CaesarCipher(letter_pos)};
        // Insert a std::pair of the letter and CaesarCipher into the lookup
        charLookup_.insert(cipher_pair);

        //More efficient option from solutions:
        charLookup_.emplace(std::piecewise_construct, std::make_tuple(letter),
                            std::make_tuple(letter_pos));
    }
}

// Applies the Vigenere Cipher
std::string VigenereCipher::applyCipher(const std::string& input_string,
                                        const CipherMode encrypt) const
{
    // Create the output string, initially a copy of the input text:
    std::string out_string{input_string};

    //Create a temporary variable to store the ciphered string:
    std::string ciphered_string{};
    ciphered_string.reserve(out_string.size());

    // Loop through the text
    for (std::size_t i{0}; i < out_string.size(); ++i) {
        // - Determine the corresponding character in the key based on the position
        //   (repeating the key if necessary)
        const char key_char = key_[i % key_.size()];

        // - Find the corresponding Caesar cipher
        const CaesarCipher& cipher{charLookup_.at(key_char)};

        // - Use it to encrypt/decrypt the character of the text and
        // - Put the new character into the output
        const std::string unencrypted_char{out_string[i]};
        ciphered_string += cipher.applyCipher(unencrypted_char, encrypt);
    }
    // Return the output text
    out_string.swap(ciphered_string);
    return out_string;
}
