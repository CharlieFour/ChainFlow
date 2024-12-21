#pragma once

#include <string>
#include <template.h>
#include "coin.h"
class Admin
{
    private:
        Template info;
    public:
        Admin();
        Admin(std::string userName, std::string password);
        ~Admin();
        Coin addCoin(std::string signature, double maxSupply, double circulatingSupply, double availableSupply);
        void removeCoin(std::string signature);
        void burnCoin(std::string signature, double amount);
};