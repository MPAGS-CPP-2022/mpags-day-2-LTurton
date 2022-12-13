#include <cctype>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
/*
Good practice to include this, 
basic strings only included in 
iostream or g++ compiler is autofixing
which is why it works without.
*/

int main(int argc, char* argv[])
{
    // Command Line Arguments:
    const std::vector<std::string> INPUT_ARGS{
        argv, argv + argc};    //Convert inputs to a vector.
    const std::size_t N_INPUTS{INPUT_ARGS.size()};

    // Related Variables:
    bool help_req{false};
    bool ver_req{false};
    std::string input_filename{""};
    std::string output_filename{""};

    const std::string HELP_STR{
        "Type a string, then press Ctrl+D to continue after the inputs are transliterated for classical ciphers."};
    const std::string VER_STR{"The current version is v0.5.0."};

    // CMD Inputs:
    // skip 0 because this is program name and can be ignored.
    for (int i{1}; i < N_INPUTS; ++i) {
        //std::cout << "Argument " << i << " is " << INPUT_ARGS[i] << std::endl;
        // //Print All Arguements For User.
        if (INPUT_ARGS[i] == "-h" || INPUT_ARGS[i] == "--help") {
            help_req = true;
        }

        else if (INPUT_ARGS[i] == "--version") {
            ver_req = true;
        }

        //Handle input file
        else if (INPUT_ARGS[i] == "-i") {
            // Next element is filename unless "-i" is the last argument
            if (i == N_INPUTS - 1) {
                std::cerr << "Error, -i needs a filaname argument" << std::endl;
                return 1;    // exit main with non-zero return to indicate failure
            } else {
                input_filename = INPUT_ARGS[i + 1];
                std::cout << ("Input filename is " + input_filename) << "\n";
                continue;
            }
        }

        //Handle Output file
        else if (INPUT_ARGS[i] == "-o") {
            if (i == N_INPUTS - 1) {
                std::cerr << "Error, -o needs a filaname argument" << std::endl;
                return 1;
            } else {
                output_filename = INPUT_ARGS[i + 1];
                std::cout << ("Output filename is " + output_filename) << "\n";
                continue;
            }
        } else {
            // Have an unknown flag to output error message and return non-zero
            // exit status to indicate failure
            std::cerr << "[error] unknown argument '" << INPUT_ARGS[i] << "'\n";
            return 1;
        }
    }

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
        // - Convert to upper case
        if (std::isalpha(in_char)) {
            //std::cout << "Selected Character is " << in_char << "\n";
            out_str += std::toupper(in_char);
            continue;
        }

        // - Change numbers to words
        switch (in_char) {
            case '0':
                out_str += "ZERO";
                break;
            case '1':
                out_str += "ONE";
                break;
            case '2':
                out_str += "TWO";
                break;
            case '3':
                out_str += "THREE";
                break;
            case '4':
                out_str += "FOUR";
                break;
            case '5':
                out_str += "FIVE";
                break;
            case '6':
                out_str += "SIX";
                break;
            case '7':
                out_str += "SEVEN";
                break;
            case '8':
                out_str += "EIGHT";
                break;
            case '9':
                out_str += "NINE";
                break;
            default:
                //do nothing
                break;
        }
        // - Ignore any other (non-alpha) character
        // - In each case, add result to a string variable
    }
    // Print the transliterated text:
    std::cout << "Transliterated text is " << out_str << std::endl;
    return 0;
}