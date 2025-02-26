#ifndef ENCRYPTION_H
#define ENCRYPTION_H

#include <string>
#include <cassert>
#include <random>

// Encrypt or decrypt a string using XOR
std::string encrypt_decrypt(const std::string& source, const std::string& key);

// Sanitize input to prevent SQL injection and unsafe characters
std::string sanitize_input(const std::string& input);

// Generate a cryptographically secure random number
int generate_secure_random();

#endif // ENCRYPTION_H
