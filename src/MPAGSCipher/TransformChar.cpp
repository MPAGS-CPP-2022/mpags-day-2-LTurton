#include <cctype>
#include <iostream>

std::string transformChar(const char in_char)
{
    /* transformChar take a character and transliterate to capitalised strings.

    char in_char - character to be modified, input is constant. 
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
