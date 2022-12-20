//! Unit Tests for MPAGSCipher processCommandLine interface
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "ProcessCommandLine.hpp"

TEST_CASE("Help found correctly", "[commandline]")
{
    ProgramSettings settings{false, false, "", "", "", CipherMode::Encrypt};
    const std::vector<std::string> cmdLine{"mpags-cipher", "--help"};
    const bool res{processCommandLine(cmdLine, settings)};

    REQUIRE(res);
    REQUIRE(settings.help_req);
}

TEST_CASE("Help found correctly alternative input", "[commandline]")
{
    ProgramSettings settings{false, false, "", "", "", CipherMode::Encrypt};
    const std::vector<std::string> cmdLine{"mpags-cipher", "-h"};
    const bool res{processCommandLine(cmdLine, settings)};

    REQUIRE(res);
    REQUIRE(settings.help_req);
}

TEST_CASE("Version found correctly", "[commandline]")
{
    ProgramSettings settings{false, false, "", "", "", CipherMode::Encrypt};
    const std::vector<std::string> cmdLine{"mpags-cipher", "--version"};
    const bool res{processCommandLine(cmdLine, settings)};

    REQUIRE(res);
    REQUIRE(settings.ver_req);
}

TEST_CASE("Version found correctly alternative input", "[commandline]")
{
    ProgramSettings settings{false, false, "", "", "", CipherMode::Encrypt};
    const std::vector<std::string> cmdLine{"mpags-cipher", "--ver"};
    const bool res{processCommandLine(cmdLine, settings)};

    REQUIRE(res);
    REQUIRE(settings.ver_req);
}

TEST_CASE("Encrypt mode activated")
{
    ProgramSettings settings{false, false, "", "", "", CipherMode::Encrypt};
    const std::vector<std::string> cmdLine{"mpags-cipher", "--encrypt"};
    const bool res{processCommandLine(cmdLine, settings)};

    REQUIRE(res);
    REQUIRE(settings.encrypt == CipherMode::Encrypt);
}

TEST_CASE("Decrypt mode activated")
{
    ProgramSettings settings{false, false, "", "", "", CipherMode::Encrypt};
    const std::vector<std::string> cmdLine{"mpags-cipher", "--decrypt"};
    const bool res{processCommandLine(cmdLine, settings)};

    REQUIRE(res);
    REQUIRE(settings.encrypt == CipherMode::Decrypt);
}

TEST_CASE("Key entered with no key specified")
{
    ProgramSettings settings{false, false, "", "", "", CipherMode::Encrypt};
    const std::vector<std::string> cmdLine = {"mpags-cipher", "-k"};
    const bool res{processCommandLine(cmdLine, settings)};

    REQUIRE(!res);
}

TEST_CASE("Key entered with key specified")
{
    ProgramSettings settings{false, false, "", "", "", CipherMode::Encrypt};
    const std::vector<std::string> cmdLine = {"mpags-cipher", "-k", "4"};
    const bool res{processCommandLine(cmdLine, settings)};

    REQUIRE(res);
    REQUIRE(settings.cipherKey == "4");
}

TEST_CASE("Input file declared without using input file")
{
    ProgramSettings settings{false, false, "", "", "", CipherMode::Encrypt};
    const std::vector<std::string> cmdLine = {"mpags-cipher", "-i"};
    const bool res{processCommandLine(cmdLine, settings)};

    REQUIRE(!res);
}

TEST_CASE("Input file declared")
{
    ProgramSettings settings{false, false, "", "", "", CipherMode::Encrypt};
    const std::vector<std::string> cmdLine = {"mpags-cipher", "-i",
                                               "input.txt"};
    const bool res{processCommandLine(cmdLine, settings)};

    REQUIRE(res);
    REQUIRE(settings.input_filename == "input.txt");
}

TEST_CASE("Output file declared without specifying output file")
{
    ProgramSettings settings{false, false, "", "", "", CipherMode::Encrypt};
    const std::vector<std::string> cmdLine = {"mpags-cipher", "-o"};
    const bool res{processCommandLine(cmdLine, settings)};

    REQUIRE(!res);
}

TEST_CASE("Output file declared")
{
    ProgramSettings settings{false, false, "", "", "", CipherMode::Encrypt};
    const std::vector<std::string> cmdLine = {"mpags-cipher", "-o",
                                               "output.txt"};
    const bool res{processCommandLine(cmdLine, settings)};

    REQUIRE(res);
    REQUIRE(settings.output_filename == "output.txt");
}