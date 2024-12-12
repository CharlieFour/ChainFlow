#pragma once

#include <string>
struct Coin
{
    public:
        std::string signature;
        double maxSupply;
        double circulatingSupply;
        double availableSupply;
};