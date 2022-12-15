#ifndef MPAGSCIPHER_PROCESSCOMMANDLINE_HPP
#define MPAGSCIPHER_PROCESSCOMMANDLINE_HPP

#include <string>
#include <vector>
#include "ProcessCommandLine.hpp"

//! Process Command Line Arguments:
bool processCommandLine(const std::vector<std::string>& ARGS, 
                        bool& help_req,bool& ver_req, 
                        std::string& input_filename,
                        std::string& output_filename);


#endif // MPAGSCIPHER_PROCESSCOMMANDLINE_HPP