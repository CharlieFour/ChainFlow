#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H

#include "sha256.h"
#include <list>
#include <string>

class ChainFlow
{
    public:
        ChainFlow();
        void addBlock(const Transaction& transaction);
        bool validateChain() const; // check if the chain is valid
        const std::list<Block>& getChain() const;

    private:
        std::list<Block> chain;
        Block createGenesisBlock() const;// generates the genesis block, very first block in the chain
        const Block& getLastBlock() const;
};

#endif



/*std::string getCurrentTime()
{
    auto now = std::chrono::system_clock::now();
    std::time_t currentTime = std::chrono::system_clock::to_time_t(now);
    auto milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()) % 1000;

    std::ostringstream oss;
    oss << std::put_time(std::localtime(&currentTime), "%Y-%m-%d %H:%M:%S")
        << '.' << std::setfill('0') << std::setw(3) << milliseconds.count();

    return oss.str();
}*/