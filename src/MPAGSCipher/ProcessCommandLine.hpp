#ifndef MPAGSCIPHER_PROCESSCOMMANDLINE_HPP
#define MPAGSCIPHER_PROCESSCOMMANDLINE_HPP

#include <string>
#include <vector>

//! Process Command Line Arguments:
bool processCommandLine(const std::vector<std::string>& ARGS, bool& help_req,
                        bool& ver_req, std::string& input_filename,
                        std::string& output_filename, std::string& cipherKey,
                        bool& encrypt);

#endif    // MPAGSCIPHER_PROCESSCOMMANDLINE_HPP