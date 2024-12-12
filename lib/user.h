#pragma once

#include <string>
#include <template.h>
class User
{
    private:
        Template info;
    public:
        User();
        ~User();
        void topup();
        void buyCoin(std::string signature, double amount);
        void sellCoin(std::string signature, double amount);
        void transferCoin(std::string signature, double amount, std::string receiverAddress);
        void reciveCoin(std::string signature);
        void viewBalance(std::string signature);
        void viewTransactionHistory();
        void viewCoinList();
};