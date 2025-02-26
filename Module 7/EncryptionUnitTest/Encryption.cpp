#include "pch.h"
#include "Encryption.h"
#include <algorithm>
#include <cctype>
#include <iostream>
#include <regex>

// Encrypt or decrypt a string using XOR
std::string encrypt_decrypt(const std::string& source, const std::string& key)
{
    assert(!key.empty()); // Ensure key is not empty
    assert(!source.empty()); // Ensure input is not empty

    std::string output = source;

    for (size_t i = 0; i < source.length(); ++i)
    {
        output[i] = source[i] ^ key[i % key.length()];
    }

    return output;
}

// Sanitize input to prevent SQL injection and unsafe characters
std::string sanitize_input(const std::string& input)
{
    // Remove potentially dangerous SQL characters using regex
    std::regex pattern("[;'\"--]");
    return std::regex_replace(input, pattern, "");
}

// Generate a cryptographically secure random number
int generate_secure_random()
{
    std::random_device rd; // Entropy source
    std::mt19937 gen(rd()); // Mersenne Twister PRNG
    std::uniform_int_distribution<int> distrib(1, 100000); // Range 1 - 100000

    return distrib(gen);
}
