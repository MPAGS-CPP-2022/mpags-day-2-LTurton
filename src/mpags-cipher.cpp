#include <cctype>
#include <cmath>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

// Our Own Project Headers:
#include "ProcessCommandLine.hpp"
#include "TransformChar.hpp"

//Declare Functions:
int main(int argc, char* argv[])
{
    // Command Line Arguments:
    const std::vector<std::string> INPUT_ARGS{
        argv, argv + argc};    //Convert inputs to a vector.

    // Related Variables:
    bool help_req{false};
    bool ver_req{false};
    std::string input_filename{""};
    std::string output_filename{""};

    const bool cmdLineStatus{processCommandLine(
        INPUT_ARGS, help_req, ver_req, input_filename, output_filename)};

    // Any failure in argument processing means the function shouldn't run.
    if (!cmdLineStatus) {
        return 1;
    }

    const std::string HELP_STR{
        "Type a string, then press Ctrl+D to continue after the inputs are transliterated for classical ciphers."};
    const std::string VER_STR{"The current version is v0.7.0."};
    //Handle help, requires no further action so return 0; to end program
    if (help_req) {
        std::cout
            << "Usage: mpags-cipher [-h/--help] [--version] [-i <file>] [-o <file>]\n\n"
            << "Encrypts/Decrypts input alphanumeric text using classical ciphers\n\n"
            << HELP_STR << "Available options:\n\n"
            << "  -h|--help        Print this help message and exit\n\n"
            << "  --version        Print version information\n\n"
            << "  -i FILE          Read text to be processed from FILE\n"
            << "                   Stdin will be used if not supplied\n\n"
            << "  -o FILE          Write processed text to FILE\n"
            << "                   Stdout will be used if not supplied\n\n"
            << std::endl;
        return 0;
    }

    //Handle version, also requires no further action.
    if (ver_req) {
        std::cout << VER_STR << "\n";
        return 0;
    }

    // Initialise for Cipher:
    char in_char{};
    std::string out_str{""};

    // Transliterate Input:
    if (!input_filename.empty()) {
        // Open the file and check that we can read from it
        std::ifstream inputStream{input_filename};
        if (!inputStream.good()) {
            std::cerr << "[error] failed to read from file '" << input_filename
                      << "'" << std::endl;
            return 1;
        }

        // Loop over each character from the file
        while (inputStream >> in_char) {
            out_str += transformChar(in_char);
        }

    } else {
        // Loop over each character from user input
        // (until Return then CTRL-D (EOF) pressed)
        while (std::cin >> in_char) {
            out_str += transformChar(in_char);
        }
    }

    // Output
    if (output_filename.empty()) {
        // Print the transliterated text to terminal:
        std::cout << "Transliterated text is " << out_str << std::endl;
    } else {
        //Output to file:
        std::ofstream out_file{output_filename};
        // {name, std::ios::app} to append rather than overwrite prev.

        if (out_file.good()) {
            out_file << out_str << std::endl;
        } else {
            std::cerr << "[error], cannot write to file" << output_filename
                      << std::endl;
            return 1;
        }
    }
    return 0;
}