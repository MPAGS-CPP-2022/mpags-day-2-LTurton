#ifndef MPAGSCIPHER_TRANSFORMCHAR_HPP
#define MPAGSCIPHER_TRANSFORMCHAR_HPP

#include <string>

/**
 * \file TransformChar.hpp
 * \brief Contains the declaration of the function for pre-processing the input text
 */

/**
 * \brief take a character and transliterate to capitalised strings.

 *   in_char - character to be modified, input is constant. 
 *   If alphabetic, is automatically capitalised. 
 *   If numeric, is converted to a capitalised string.

 *   return: the character after operation(s). 
*/
std::string transformChar(const char in_char);

#endif // MPAGSCIPHER_TRANSFORMCHAR_HPP