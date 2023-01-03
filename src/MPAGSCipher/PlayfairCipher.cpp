#include "PlayfairCipher.hpp"

#include <algorithm>
#include <iostream>
#include <string>

// Holds a string assigned by the setKey function
PlayfairCipher::PlayfairCipher(const std::string& key)
{
    this->setKey(key);
};

// Takes the std::string key, and calls setKey
void PlayfairCipher::setKey(const std::string& key)
{
    // store the original key
    key_ = key;

    // Append the alphabet
    key_ += "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    // Make sure the key is upper case
    std::transform(
        std::begin(key_), std::end(key_), std::begin(key_),
        ::toupper);    //--> (input_start, input_end, output_start, operator)

    // Remove non-alpha characters
    key_.erase(std::remove_if(key_.begin(), key_.end(),
                              [](unsigned char c) { return !std::isalpha(c); }),
               key_.end());

    // Change J -> I

    // Remove duplicated letters

    // Store the coords of each letter

    // Store the playfair cihper key map
}

// Applies the Playfair Cipher
std::string PlayfairCipher::applyCipher(const std::string& inputText,
                                        const CipherMode cipherMode) const
{
    // Create the output string, initially a copy of the input text
    std::string outputText{inputText};

    // Change J -> I

    // Find repeated characters and add an X (or a Q for repeated X's)

    // If the size of the input is odd, add a trailing Z

    // Loop over the input digraphs

    // - Find the coordinates in the grid for each digraph

    // - Apply the rules to these coords to get new coords

    // - Find the letters associated with the new coords

    // - Make the replacements

    // Return the output text
    std::cout << "Playfair Cipher has not yet been implemented" << std::endl;
    return outputText;
}