#ifndef MPAGSCIPHER_PLAYFAIRCIPHER_HPP
#define MPAGSCIPHER_PLAYFAIRCIPHER_HPP

/**
 * \file PlayfairCipher.hpp
 * \brief Contains the declaration of the PlayfairCipher class
 */

/**
 * \class PlayfairCipher
 * \brief Encrypt or decrypt text using the Playfair cipher with the given key
 */

class PlayfairCipher {
  public:
    explicit PlayfairCipher::PlayfairCipher(const std::string& key);

    void PlayfairCipher::setKey(const std::string& key);

    std::string PlayfairCipher::applyCipher(const std::string& inputText, const CipherMode cipherMode ) const;
};

#endif
