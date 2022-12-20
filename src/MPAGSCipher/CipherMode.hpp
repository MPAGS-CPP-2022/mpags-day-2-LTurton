#ifndef MPAGSCIPHER_CIPHERMODE_HPP
#define MPAGSCIPHER_CIPHERMODE_HPP

/**
 * \file CipherMode.hpp
 * \brief Contains the declaration of the CipherMode enumeration
 */

/**
 * \enum CipherMode
 * \brief The Encryption/Decryption state.
 */

enum class CipherMode {
    Encrypt,    ///< Encrypt the data
    Decrypt     ///< Decrypt the data
};

#endif    // MPAGSCIPHER_CIPHERMODE_HPP