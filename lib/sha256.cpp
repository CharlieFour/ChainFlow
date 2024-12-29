#include "sha256.h"

// SHA-256 implementation
std::string sha256(const std::string& data)
{
    // Padding the data to make it a multiple of 512 bits
    std::vector<unsigned char> message;
    for(size_t i = 0; i < data.size(); ++i)
    {
        message.push_back(static_cast<unsigned char>(data[i]));
    }

    // Append the bit '1' and pad with zeros
    message.push_back(0x80);
    while((message.size() * 8) % 512 != 448)
    {
        message.push_back(0x00);
    }

    // Append the length of the original message (in bits)
    unsigned long long int length = data.size() * 8;
    for(int i = 0; i < 8; ++i)
    {
        message.push_back(static_cast<unsigned char>(length >> (56 - i * 8)));
    }

    // Process the message in 512-bit chunks
    std::vector<unsigned int> w(64);
    unsigned int h[8] = {
        0x6a09e667, 0xbb67ae85, 0x3c6ef372, 0xa54ff53a,
        0x510e527f, 0x9b05688c, 0x1f83d9ab, 0x5be0cd19
    };

    for(size_t i = 0; i < message.size(); i += 64)
    {
        for(int j = 0; j < 16; ++j)
        {
            w[j] = (message[i + j * 4] << 24) |
                   (message[i + j * 4 + 1] << 16) |
                   (message[i + j * 4 + 2] << 8) |
                   message[i + j * 4 + 3];
        }

        for(int j = 16; j < 64; ++j)
        {
            w[j] = sigma1(w[j - 2]) + w[j - 7] + sigma0(w[j - 15]) + w[j - 16];
        }

        unsigned int a = h[0], b = h[1], c = h[2], d = h[3];
        unsigned int e = h[4], f = h[5], g = h[6], h_val = h[7];

        for(int j = 0; j < 64; ++j)
        {
            unsigned int t1 = h_val + bigSigma1(e) + choice(e, f, g) + k[j] + w[j];
            unsigned int t2 = bigSigma0(a) + majority(a, b, c);
            h_val = g;
            g = f;
            f = e;
            e = d + t1;
            d = c;
            c = b;
            b = a;
            a = t1 + t2;
        }

        h[0] += a;
        h[1] += b;
        h[2] += c;
        h[3] += d;
        h[4] += e;
        h[5] += f;
        h[6] += g;
        h[7] += h_val;
    }

    // Convert the hash value to a string
    std::stringstream ss;
    for(int i = 0; i < 8; ++i)
    {
        ss << std::setw(8) << std::setfill('0') << std::hex << h[i];
    }
    return ss.str();
}

// Generate the transaction hash
std::string generateTransactionHash(const Transaction& tx)
{
    std::string txData = tx.senderAddress + tx.receiverAddress + std::to_string(tx.amount) + tx.timestamp + tx.signature;
    return sha256(txData);
}

// Generate block hash based on the transaction and previous hash
void Block::generateBlockHash()
{
    // Generate the hash by concatenating the transaction and previous hash
    std::string blockData = generateTransactionHash(transactions) + previousHash;
    hash = sha256(blockData);
}
