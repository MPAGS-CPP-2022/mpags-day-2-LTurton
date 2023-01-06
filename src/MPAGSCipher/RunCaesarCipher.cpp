#include "RunCaesarCipher.hpp"
#include "Alphabet.hpp"

#include <iostream>
#include <string>
#include <vector>

std::string runCaesarCipher(const std::string& inputText, const std::size_t key,
                            const bool encrypt)
{
    // Create the a output string & Fix The Key in the range 0 - length alphabet
    const std::size_t filter_key = key % Alphabet::size;
    std::string output_string{};
    int shift_pos{};

    // For each loop, for each member of array inputText do a thing to orgionalChar:
    for (const auto& origionalChar : inputText) {
        // Find Position in the Alphabet container:
        for (size_t i{0}; i < Alphabet::size; ++i) {
            if (origionalChar == Alphabet::alphabet[i]) {
                // Apply the chosen shift, and determine new character.
                // Then break out of alphabet loop.
                if (encrypt) {
                    shift_pos = (i + filter_key) % Alphabet::size;
                } else if (!encrypt) {
                    shift_pos =
                        (i + Alphabet::size - filter_key) %
                        Alphabet::size;    // +SIZE deals with negative wrapping nicely.
                } else {
                    std::cout
                        << "Encrypt/decrypt not set, defaulting to decryption.";
                    shift_pos =
                        (i + Alphabet::size - filter_key) % Alphabet::size;
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