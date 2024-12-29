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