#include <cctype>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

//Declare Functions:
std::string transformChar(const char in_char);

bool processCommandLine(const std::vector<std::string>& ARGS, 
                        bool& help_req,bool& ver_req, 
                        std::string& input_filename,
                        std::string& output_filename);

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

/*
Function Codes:
*/

std::string transformChar(const char in_char)
{
    /* transformChar take a character and transliterate to capitalised strings.

    in_char - character to be modified, input is constant. 
    If alphabetic, is automatically capitalised. 
    If numeric, is converted to a capitalised string.

    return: the character after operations.    
    */

    std::string out_str;
    // - Convert to upper case
    if (std::isalpha(in_char)) {
        //std::cout << "Selected Character is " << in_char << "\n";
        out_str += std::toupper(in_char);
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
    return out_str;
}

bool processCommandLine(const std::vector<std::string>& ARGS, bool& help_req,
                        bool& ver_req, std::string& input_filename,
                        std::string& output_filename)
{
    /* processCOmmandLine take command line articles and process the results.
     help_ref - boolean variable for help request.
     ver_ref - boolean variable for version request.
     input_filename - filename from -i article.
     output_filename - filename form -o article.

     return true if succesful, 1 if error in input pairs.

    */

    //Define Local Variables
    bool processStatus{
        true};    // Status flag to indicate whether or not the parsing was successful

    // CMD Inputs:
    // skip 0 because this is program name and can be ignored.
    const std::size_t N_INPUTS{ARGS.size()};
    for (std::size_t i{1}; i < N_INPUTS; ++i) {
        //std::cout << "Argument " << i << " is " << ARGS[i] << std::endl;
        // //Print All Arguements For User.
        if (ARGS[i] == "-h" || ARGS[i] == "--help") {
            help_req = true;
        }

        else if (ARGS[i] == "--version") {
            ver_req = true;
        }

        //Handle input file
        else if (ARGS[i] == "-i") {
            // Next element is filename unless "-i" is the last argument
            if (i == N_INPUTS - 1) {
                std::cerr << "Error, -i needs a filaname argument" << std::endl;
                processStatus = false;
                break;    // exit main to indicate failure
            } else {
                input_filename = ARGS[i + 1];
                std::cout << ("Input filename is " + input_filename) << "\n";
                ++i;    //Advance PAST the argument
            }
        }

        //Handle Output file
        else if (ARGS[i] == "-o") {
            if (i == N_INPUTS - 1) {
                std::cerr << "Error, -o needs a filaname argument" << std::endl;
                processStatus = false;
                break;
            } else {
                output_filename = ARGS[i + 1];
                std::cout << ("Output filename is " + output_filename) << "\n";
                ++i;
            }
        } else {
            // Return non-zero exit status to indicate failure for unknown ARG:
            std::cerr << "[error] unknown argument '" << ARGS[i] << "'\n";
            processStatus = false;
            break;
        }
    }
    return processStatus;
}