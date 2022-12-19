#ifndef MPAGSCIPHER_CAESARCIPHER_HPP
#define MPAGSCIPHER_CAESARCIPHER_HPP

#include "CipherMode.hpp"
#include <cstddef>
#include <string>
#include <vector>

/// Encrypt or decrypt text using the Caesar cipher with the given key
class CaesarCipher {
  public:
    /// Create a new CaesarCipher, with the given key
    explicit CaesarCipher(const std::size_t key);

    /// Create a new CaesarCipher, converting the given string into the key
    explicit CaesarCipher(const std::string& key);

    //! Run Cipher:
    std::string applyCipher(const std::string& inputText,
                            const CipherMode encrypt) const;

  private:
    const std::string ALPHABET_{"ABCDEFGHIJKLMNOPQRSTUVWXYZ"}; //Need to be defined first, otherwise uninitialised compiler error --> maybe const comes first?
    const std::size_t ALPHABETSIZE_{ALPHABET_.size()};

    std::size_t key_{0};    //Encryption Key
};

#endif