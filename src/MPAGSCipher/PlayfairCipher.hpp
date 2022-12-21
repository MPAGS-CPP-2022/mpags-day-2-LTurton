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
    /**
     * \brief Create a new PlayfairCipher with the given key
     *
     * \param key the key to use in the cipher
     */
    explicit PlayfairCipher::PlayfairCipher(const std::string& key);

    /**
     * \brief Set the key to be used for the encryption/decryption
     *
     * \param key the key to use in the cipher
     */
    void PlayfairCipher::setKey(const std::string& key);

    /**
     * \brief Apply the cipher to the provided text
     *
     * \param inputText the text to encrypt or decrypt
     * \param cipherMode whether to encrypt or decrypt the input text
     * \return the result of applying the cipher to the input text
     */

    std::string PlayfairCipher::applyCipher(const std::string& inputText,
                                            const CipherMode cipherMode) const;

  private:
    std::string key_{""};

    const std::string ALPHABET_{"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
};

#endif
