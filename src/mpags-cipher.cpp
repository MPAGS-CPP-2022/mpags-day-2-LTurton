// Our Own Project Headers:
#include "ProcessCommandLine.hpp"
#include "RunCaesarCipher.hpp"
#include "TransformChar.hpp"

#include <cctype>
#include <cmath>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

int main(int argc, char* argv[])
{
    // Command Line Arguments:
    const std::vector<std::string> INPUT_ARGS{
        argv, argv + argc};    //Convert inputs to a vector.

    // Related Variables:
    ProgramSettings settings{false,false,"","","",false};

    const bool cmdLineStatus{processCommandLine(INPUT_ARGS,settings)};

    // Any failure in argument processing means the function shouldn't run.
    if (!cmdLineStatus) {
        return 1;
    }

    const std::string HELP_STR{
        "Type a string, then press Ctrl+D to continue after the inputs are transliterated for classical ciphers."};
    const std::string VER_STR{"The current version is v0.9.1."};
    //Handle help, requires no further action so return 0; to end program
    if (settings.help_req) {
        std::cout
            << "Usage: mpags-cipher [-h|--help] [--version|--ver] [-i <file>] [-o <file>]\n\n"
            << "Encrypts/Decrypts input alphanumeric text using classical ciphers\n\n"
            << HELP_STR << "Available options:\n\n"
            << "  -h|--help        Print this help message and exit.\n\n"
            << "  --version|--ver  Print version information.\n\n"
            << "  -i FILE          Read text to be processed from FILE.\n"
            << "                   Stdin will be used if not supplied.\n\n"
            << "  -o FILE          Write processed text to FILE.\n"
            << "                   Stdout will be used if not supplied.\n\n"
            << "  -k KEY           Encypt/Decrypt Key Shift Positions.\n"
            << "                   A key of zero, i.e no encryption is default.\n\n"
            << "--encrypt          Use key to encrypt text.\n\n"
            << "--decrypt          Use key to decrypt text.\n"
            << std::endl;
        return 0;
    }

    //Handle version, also requires no further action.
    if (settings.ver_req) {
        std::cout << VER_STR << "\n";
        return 0;
    }

    // Initialise for Cipher:
    char in_char;
    std::string input_string;

    // Transliterate Input:
    if (!settings.input_filename.empty()) {
        // Open the file and check that we can read from it
        std::ifstream inputStream{settings.input_filename};
        if (!inputStream.good()) {
            std::cerr << "[error] failed to read from file '" << settings.input_filename
                      << "'" << std::endl;
            return 1;
        }

        // Loop over each character from the file
        while (inputStream >> in_char) {
            input_string += transformChar(in_char);
        }

    } else {
        // Loop over each character from user input
        std::cout << "Please provide some text and press enter, Ctrl + 'd'."
                  << std::endl;
        while (std::cin >> in_char) {
            input_string += transformChar(in_char);
        }
    }
    std::cout << "The transliterated text is " << input_string << std::endl;

    //Need to convert cipherKey from string to std::size_t and handle unsupplied key.
    std::size_t encryption_key{0};
    if (!settings.cipherKey.empty()) {
        // Check input string IS a valid positive int then convert:
        for (const auto& elem : settings.cipherKey) {
            if (!std::isdigit(elem)) {
                std::cerr
                    << "[error] cipher key must be unsigned long integer for Caeser cipher, \n"
                    << "     the supplied key of " << settings.cipherKey
                    << " cannot be converted." << std::endl;
                return 1;
            }

            encryption_key = stoul(settings.cipherKey);
        }
    }

    /* TODO
Cipher Function is bugged and just outputs aaaaa at whatever the string is's length. 
*/
    std::string out_str{runCaesarCipher(input_string, encryption_key, settings.encrypt)};
    std::cout << "The Cipher Key is " << encryption_key << std::endl;

    // Output
    if (settings.output_filename.empty()) {
        // Print the final text to terminal:
        std::cout << "Final text is " << out_str << std::endl;
    } else {
        //Output to file:
        std::ofstream output_file{settings.output_filename};
        // {name, std::ios::app} to append rather than overwrite prev.

        if (output_file.good()) {
            output_file << out_str << std::endl;
        } else {
            std::cerr << "[error], cannot write to file" << settings.output_filename
                      << std::endl;
            return 1;
        }
    }
    return 0;
}