#include "CipherMode.hpp"
#include <ProcessCommandLine.hpp>    //Otherwise ProgramSettings is undefined.

#include <iostream>
#include <string>
#include <vector>

bool processCommandLine(const std::vector<std::string>& ARGS,
                        ProgramSettings& settings)
{
    /* processCommandLine take command line articles and process the results.
     help_ref           - boolean variable for help request.
     ver_ref            - boolean variable for version request.
     input_filename     - filename from -i article.
     output_filename    - filename form -o article.
     cipherKey          - Integer value of cipherKey following -k argument.
     encrypt            - Boolean, encrypt/decrypt text, default decrypt.

     return true if succesful, 1 if error in inputs.

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
            settings.help_req = true;
        }

        else if (ARGS[i] == "--version" || ARGS[i] == "--ver") {
            settings.ver_req = true;
        }

        //Handle input file
        else if (ARGS[i] == "-i") {
            // Next element is filename unless "-i" is the last argument
            if (i == N_INPUTS - 1) {
                std::cerr << "Error, -i needs a filaname argument" << std::endl;
                processStatus = false;
                break;    // exit main to indicate failure
            } else {
                settings.input_filename = ARGS[i + 1];
                std::cout << ("Input filename is " + settings.input_filename)
                          << "\n";
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
                settings.output_filename = ARGS[i + 1];
                std::cout << ("Output filename is " + settings.output_filename)
                          << "\n";
                ++i;
            }
        }

        else if (ARGS[i] == "-k") {
            // Handle cipher key option
            // Next element is the key unless -k is the last argument
            if (i == N_INPUTS - 1) {
                std::cerr << "[error] -k requires a positive integer argument"
                          << std::endl;
                // Set the flag to indicate the error and terminate the loop
                processStatus = false;
                break;
            } else {
                // Got the key, so assign the value and advance past it
                settings.cipherKey = ARGS[i + 1];
                ++i;
            }
        } else if (ARGS[i] == "--encrypt") {
            settings.encrypt = CipherMode::Encrypt;
        } else if (ARGS[i] == "--decrypt") {
            settings.encrypt = CipherMode::Decrypt;
        } else if (ARGS[i] == "-c") {
            // Handle cipher type option
            // Next element is the name of the cipher, unless -c is the last argument
            if (i == N_INPUTS - 1) {
                std::cerr << "[error] -c requires a string argument"
                          << std::endl;
                // Set the flag to indicate the error and terminate the loop
                processStatus = false;
                break;
            } else {
                // Got the cipher name, so assign the value and advance past it
                if (ARGS[i + 1] == "caesar") {
                    settings.cipherType = CipherType::Caesar;
                } else if (ARGS[i + 1] == "playfair") {
                    settings.cipherType = CipherType::Playfair;
                    } else if (ARGS[i + 1] == "vigenere") {
                    settings.cipherType = CipherType::Vigenere;
                } else {
                    std::cerr << "[error] unknown cipher '"
                              << ARGS[i + 1] << "'\n";
                    processStatus = false;
                    break;
                }
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