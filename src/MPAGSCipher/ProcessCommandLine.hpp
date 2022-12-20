#ifndef MPAGSCIPHER_PROCESSCOMMANDLINE_HPP
#define MPAGSCIPHER_PROCESSCOMMANDLINE_HPP

#include "CipherMode.hpp"

#include <string>
#include <vector>

/**
 * \file ProcessCommandLine.hpp
 * \brief Contains the declarations of the data structures and functions associated with the processing of command-line arguments
 */

/**
 * \struct ProgramSettings
 * \brief Holds the settings of the program that can be modified by command-line arguments
 */
struct ProgramSettings {
    /// Use of --help -h       : indicates help flag as cmdline input.
    bool help_req;
    /// Use of --ver --version : indicates version flag as cmdline input.
    bool ver_req;
    /// -i filename            : indicates input of user supplied filename to read from.
    std::string input_filename;
    /// -o filename            : indicates input of user supplied filename to write to.
    std::string output_filename;
    /// -k KEY                 : indiciates input user encryption key
    std::string cipherKey;
    /// --encrypt --decrypt    : indicates whether cipher encrypts (true) or decrypts (false)
    CipherMode encrypt;
};

/**
 * \brief Processes the command-line arguments and modifies accordingly the program settings
 *
 * \param cmdLineArgs the command-line arguments to be processed
 * \param settings the program settings to be modified based upon the arguments received
 * \return true if the arguments could be successfully parsed, false otherwise
 */
bool processCommandLine(const std::vector<std::string>& ARGS,
                        ProgramSettings& settings);

#endif    // MPAGSCIPHER_PROCESSCOMMANDLINE_HPP