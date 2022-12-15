#include <vector>
#include <iostream>

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