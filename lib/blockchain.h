#pragma once
#include "block.h"

#include <string>
#include <vector>

class BlockChain
{
    public:
        BlockChain();
        ~BlockChain();
        void addBlock(Block * block);
        void printChain();
        
    private:
        std::vector<Block*> chain;
        Block* getLastBlock();
        std::string getTimeStamp();
};