//! Unit tests for MPAGSCipher CaesarCipher interface
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "CaesarCipher.hpp"

TEST_CASE("Caesar Cipher with no key","[caesar]")
{
    CaesarCipher cc{0};
    REQUIRE(cc.applyCipher("HELLOWORLD", CipherMode::Encrypt) == "HELLOWORLD");
}

TEST_CASE("Caesar Cipher encryption", "[caesar]")
{
    CaesarCipher cc{10};
    REQUIRE(cc.applyCipher("HELLOWORLD", CipherMode::Encrypt) == "ROVVYGYBVN");
}

TEST_CASE("Caesar Cipher decryption", "[caesar]")
{
    CaesarCipher cc{10};
    REQUIRE(cc.applyCipher("ROVVYGYBVN", CipherMode::Decrypt) == "HELLOWORLD");
}

TEST_CASE("Caesar Cipher encryption with out of range key","[caesar]")
{
    CaesarCipher cc{36};
    REQUIRE(cc.applyCipher("HELLOWORLD", CipherMode::Encrypt) == "ROVVYGYBVN");
}

TEST_CASE("Caesar Cipher decryption with out of range key", "[caesar]")
{
    CaesarCipher cc{62};
    REQUIRE(cc.applyCipher("ROVVYGYBVN", CipherMode::Decrypt) == "HELLOWORLD");
}