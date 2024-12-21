#pragma once

#include <string>
#include <vector>

class Wallet
{
    private:
        double USDT = 0;	
        std::string address;
        std::vector<std::pair<std::string, int>> coinList; 
        std::vector<Wallet> walletList; // this is wrong way, im just checking wallet...
    public:
        Wallet();
        ~Wallet();
        void setAddress(std::string address);
        std::string getAddress();
        void topupBalance();
        void printCoins();
        void printBalance();
        void transferCoin(std::string address, std::string signature, int amount);
        void receiveCoin();
        void printTransactions();
        void printTransactionHistory();
};