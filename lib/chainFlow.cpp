#include "chainFlow.h"
#include <iostream>

ChainFlow::ChainFlow()
{
    // Add the genesis block to the chain
    chain.push_back(createGenesisBlock());
}

// Create the genesis block
Block ChainFlow::createGenesisBlock() const
{
    Transaction genesisTransaction = {"", "", 0.0, "2024-12-28T00:00:00Z", ""};
    Block genesisBlock;
    genesisBlock.previousHash = "0";
    genesisBlock.transactions = genesisTransaction;
    genesisBlock.generateBlockHash();
    return genesisBlock;
}

// Add a new block to the chain
void ChainFlow::addBlock(const Transaction& transaction)
{
    Block newBlock;
    newBlock.previousHash = getLastBlock().hash;
    newBlock.transactions = transaction;
    newBlock.generateBlockHash();
    chain.push_back(newBlock);
}

// Validate the blockchain integrity
bool ChainFlow::validateChain() const
{
    auto it = chain.begin();
    auto nextIt = std::next(it);

    while (nextIt != chain.end())
    {
        const Block& currentBlock = *nextIt;
        const Block& previousBlock = *it;

        // Check if the block's hash is correctly calculated
        if(currentBlock.hash != sha256(generateTransactionHash(currentBlock.transactions) + currentBlock.previousHash))
        {
            return false;
        }

        // Check if the block's previous hash matches the previous block's hash
        if(currentBlock.previousHash != previousBlock.hash)
        {
            return false;
        }

        ++it;
        ++nextIt;
    }
    return true;
}

// Get the last block in the chain
const Block& ChainFlow::getLastBlock() const
{
    return chain.back();
}

// Get the blockchain
const std::list<Block>& ChainFlow::getChain() const
{
    return chain;
}
