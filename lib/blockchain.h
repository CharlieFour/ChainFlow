#pragma once
#include "block.h"

#include <string>
#include <list>
#include <vector>

class BlockChain
{
    public:
        BlockChain();
        ~BlockChain();
        void addBlock(Block * block);
        void printChain();
        
    private:
        std::list<Block*> chain;
        Block* getLastBlock();
        std::string getTimeStamp();
};