#ifndef SHA256_H
#define SHA256_H

#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>

// SHA-256 constants
static const unsigned int k[64] =
{
    0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5, 0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
    0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3, 0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
    0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc, 0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
    0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7, 0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967,
    0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13, 0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
    0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3, 0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
    0x19a4c116, 0x1e376c08, 0x2a437e5d, 0x3c4ef3b7, 0x43172f60, 0x4e7f8f74, 0x5dff9b1f, 0x6b3012fd
};

// Helper macros
#define ROTATE_LEFT(x, n) (((x) << (n)) | ((x) >> (32 - (n))))
#define SHA256_BLOCK_SIZE 32

// SHA-256 functions
inline unsigned int choice(unsigned int x, unsigned int y, unsigned int z)
{
    return (x & y) ^ (~x & z);
}

inline unsigned int majority(unsigned int x, unsigned int y, unsigned int z)
{
    return (x & y) ^ (x & z) ^ (y & z);
}

inline unsigned int sigma0(unsigned int x)
{
    return ROTATE_LEFT(x, 7) ^ ROTATE_LEFT(x, 18) ^ (x >> 3);
}

inline unsigned int sigma1(unsigned int x)
{
    return ROTATE_LEFT(x, 17) ^ ROTATE_LEFT(x, 19) ^ (x >> 10);
}

inline unsigned int bigSigma0(unsigned int x)
{
    return ROTATE_LEFT(x, 2) ^ ROTATE_LEFT(x, 13) ^ ROTATE_LEFT(x, 22);
}

inline unsigned int bigSigma1(unsigned int x)
{
    return ROTATE_LEFT(x, 6) ^ ROTATE_LEFT(x, 11) ^ ROTATE_LEFT(x, 25);
}

// SHA-256 hash function
std::string sha256(const std::string& data);

// Transaction struct
struct Transaction
{
    std::string senderAddress;
    std::string receiverAddress;
    double amount;
    std::string timestamp;
    std::string signature;
};

// Function to generate the transaction hash
std::string generateTransactionHash(const Transaction& tx);

// Block struct
struct Block
{
    std::string hash;
    Transaction transactions;
    std::string previousHash;

    // Generate a block hash
    void generateBlockHash();
};

#endif // SHA256_H
