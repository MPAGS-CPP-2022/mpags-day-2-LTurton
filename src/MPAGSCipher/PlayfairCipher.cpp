#include "PlayfairCipher.hpp"
#include "CipherMode.hpp"

#include <iostream>
#include <string>

// Holds a string assigned by the setKey function
PlayfairCipher::PlayfairCipher(const std::string& key){
 this->setKey(key);
};

// Takes the std::string key, and calls setKey
void PlayfairCipher::setKey( const std::string& key)
{
    // store the original key
    key_ = key;

    // Append the alphabet

    // Make sure the key is upper case
    // Remove non-alpha characters
    // Change J -> I

    // Remove duplicated letters

    // Store the coords of each letter

    // Store the playfair cihper key map
};

// Applies the Playfair Cipher
std::string PlayfairCipher::applyCipher(const std::string& inputText,
                                        const CipherMode cipherMode) const
{
    std::cout << "Playfair Cipher has not yet been implemented" << std::endl;
    return;
}