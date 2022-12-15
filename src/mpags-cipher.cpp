#include <cctype>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

// Our Own Project Headers:
#include "TransformChar.hpp"
#include "ProcessCommandLine.hpp"

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
    const std::string VER_STR{"The current version is v0.5.0."};
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

    // Transliterate input:
    std::cout << "Please provide some text and press enter, Ctrl + 'd'."
              << std::endl;
    while (std::cin >> in_char) {
        out_str += transformChar(in_char);
    }
    // Print the transliterated text:
    std::cout << "Transliterated text is " << out_str << std::endl;
    return 0;
}