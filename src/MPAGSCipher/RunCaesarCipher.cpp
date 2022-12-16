#include "RunCaesarCipher.hpp"

#include <iostream>
#include <string>
#include <vector>

std::string runCaesarCipher(const std::string& inputText, const std::size_t key,
                            const bool encrypt)
{
    // Create the alphabet container and output string
    const std::string ALPHABET{
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    const std::size_t ALPHABET_SIZE{ALPHABET.size()};

    //Fix The Key in the range 0 - length alphabet
    const std::size_t filter_key = key % ALPHABET_SIZE;

    std::string output_string{};
    int shift_pos{};

    // For each loop, for each member of array inputText do a thing to orgionalChar:
    for (const auto& origionalChar : inputText) {
        // Find Position in the Alphabet container:
        for (size_t i{0}; i < ALPHABET_SIZE; ++i) {
            if (origionalChar == ALPHABET[i]) {
                // Apply the chosen shift, and determine new character.
                // Then break out of alphabet loop.
                if (encrypt) {
                    shift_pos = (i + filter_key) % ALPHABET_SIZE;
                } else if (!encrypt) {
                    shift_pos =
                        (i + ALPHABET_SIZE - filter_key) %
                        ALPHABET_SIZE;    // +SIZE deals with negative wrapping nicely.
                } else {
                    std::cout
                        << "Encrypt/decrypt not set, defaulting to decryption.";
                    shift_pos =
                        (i + ALPHABET_SIZE - filter_key) % ALPHABET_SIZE;
                }
                break;
            }
        }

        //Add Ciphered Result to Ouput:
        output_string += ALPHABET[shift_pos];
    }

    // Finally, return the output string
    return output_string;
}