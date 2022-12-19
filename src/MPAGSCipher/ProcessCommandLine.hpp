#ifndef MPAGSCIPHER_PROCESSCOMMANDLINE_HPP
#define MPAGSCIPHER_PROCESSCOMMANDLINE_HPP

#include "CipherMode.hpp"

#include <string>
#include <vector>

//! Process Command Line Arguments:
struct ProgramSettings {
    //Use of --help -h       : indicates help flag as cmdline input.
    bool help_req;                  
    //Use of --ver --version : indicates version flag as cmdline input.
    bool ver_req;                   
    //-i filename            : indicates input of user supplied filename to read from.
    std::string input_filename;     
    //-o filename            : indicates input of user supplied filename to write to.
    std::string output_filename;  
    //-k KEY                 : indiciates input user encryption key  
    std::string cipherKey;
    //--encrypt --decrypt    : indicates whether cipher encrypts (true) or decrypts (false)
    CipherMode encrypt;
};

bool processCommandLine(const std::vector<std::string>& ARGS, ProgramSettings& settings);

#endif    // MPAGSCIPHER_PROCESSCOMMANDLINE_HPP