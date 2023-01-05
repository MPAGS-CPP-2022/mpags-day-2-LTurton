#include "VigenereCipher.hpp"

#include <algorithm>
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
    // Store the original key
    key_ = key;

    // Loop through the key

    // - Find the position of the letter in the alphabet

    // - Construct a Caesar cipher object using the position as the key

    // - Store the Caesar cipher object so that it can be retrieved based on the character in the key
}

// Applies the Vigenere Cipher
std::string VigenereCipher::applyCipher(const std::string& input_string,
                                        const CipherMode /*cipherMode*/) const
{
    // Create the output string, initially a copy of the input text
    std::string out_string{input_string};

    // Loop through the text

    // - Determine the corresponding character in the key based on the position
    //   (repeating the key if necessary)

    // - Find the corresponding Caesar cipher

    // - Use it to encrypt/decrypt the character of the text

    // - Put the new character into the output

    // Return the output text
    return out_string;
}