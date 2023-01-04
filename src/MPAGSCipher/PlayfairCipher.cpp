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
    key_ += ALPHABET_;

    // Make sure the key is upper case
    std::transform(
        std::begin(key_), std::end(key_), std::begin(key_),
        ::toupper);    //--> (input_start, input_end, output_start, operator)

    // Remove non-alpha characters
    //--> use a lambda which re-orders string with whitespaces to left, and erases those spaces.
    key_.erase(std::remove_if(key_.begin(), key_.end(),
                              [](unsigned char c) { return !std::isalpha(c); }),
               key_.end());

    // Change J -> I
    std::transform(key_.begin(), key_.end(),
                   key_.begin(),    //write to same location
                   [](unsigned char c) { return (c == 'J') ? 'I' : c; });

    // Remove duplicated letters
    std::string duplicateLetters{""};
    auto detectDuplicates = [&](char c) {
        if (duplicateLetters.find(c) == std::string::npos) {
            duplicateLetters += c;    //if not in duplicate letters, append c.
            return false;
        } else {
            return true;
        }
    };

    key_.erase(std::remove_if(key_.begin(), key_.end(), detectDuplicates),
               key_.end());

    // Store the coords of each letter
    // (at this point the key length must be equal to grid dimension squared)
    for (std::size_t i{0}; i < keyLength_; ++i) {
        std::size_t row{i / gridSize_};
        std::size_t column{i % gridSize_};

        auto coords = std::make_pair(row, column);

        charLookup_[key_[i]] = coords;
        coordLookup_[coords] = key_[i];
    }

    // Store the playfair cipher key map
}

// Applies the Playfair Cipher
std::string PlayfairCipher::applyCipher(const std::string& inputText,
                                        const CipherMode cipherMode) const
{
    // Create the output string, initially a copy of the input text
    std::string outputText{inputText};

    // Change J -> I
    std::transform(outputText.begin(), outputText.end(),
                   outputText.begin(),    //write to same location
                   [](unsigned char c) { return (c == 'J') ? 'I' : c; });

    // Find repeated characters and add an X (or a Q for repeated X's)
    // (only when they occur within a bigram)
    std::string tempString{""};
    tempString.reserve(
        outputText.size() *
        1.1);    //Reserve space to hold the result, plus headroom.

    for (std::size_t i{0}; i < outputText.size(); i += 2) {
        //Always add first of character pairs
        tempString += outputText[i];
        if (i + 1 == outputText.size()) {
            //If this is last character, result is odd so add a Z, or X if char is already Z
            tempString += (outputText[i] == 'Z') ? 'X' : 'Z';
            break;    //Last character, so leave loop

        } else if (outputText[i + 1] != outputText[i]) {
            // if characters are different, add the new character
            tempString += outputText[i + 1];

        } else {    // if they're the same, add X/Q
            tempString += (outputText[i] == 'X') ? 'Q' : 'X';

            //decrement i because outputText[i+1] hasn't been used
            --i;
        }
    }

    // Swap the contents of the original and modified strings - cheaper than assignment
    outputText.swap(tempString);

    // Depending on encryption/decryption mode, set whether to increment or
    // decrement the column/row index (modulo the grid dimension)
    const std::size_t shift{
        (cipherMode == CipherMode::Encrypt) ? 1u : gridSize_ - 1u};

    // Loop over the input digraphs
    for (std::size_t i{0}; i < outputText.size(); i += 2) {
        // - Find the coordinates in the grid for each digraph
        PlayfairCoords firstCoord{charLookup_.at(outputText[i])};
        PlayfairCoords secondCoord{charLookup_.at(outputText[i + 1])};

        // Use Structured Bindings to improve readability:
        auto& [rowOne, columnOne]{firstCoord};
        auto& [rowTwo, columnTwo]{secondCoord};

        // Find whether the two points are on a row, a column or form a rectangle/square
        // Then apply the appropriate rule to these coords to get new coords
        if (rowOne == rowTwo) {
            // Row - so increment/decrement the column indices (modulo the grid dimension)
            columnOne = (columnOne + shift) % gridSize_;
            columnTwo = (columnTwo + shift) % gridSize_;

        } else if (columnOne == columnTwo) {
            // Column - so increment/decrement the row indices (modulo the grid dimension)
            rowOne = (rowOne + shift) % gridSize_;
            rowTwo = (rowTwo + shift) % gridSize_;

        } else {
            // Rectangle/Square - so keep the rows the same and swap the columns
            std::swap(columnOne, columnTwo);
        }
        // - Find the letters associated with the new coords & Make the replacements
        outputText[i] = coordLookup_.at(firstCoord);
        outputText[i + 1] = coordLookup_.at(secondCoord);
    }

    // Return the output text
    return outputText;
}