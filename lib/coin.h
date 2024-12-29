#pragma once
#include <string>
struct Coin
{
    public:
        std::string signature; // like BNB, Bitcoin(BTC)
        double maxSupply; // 21000000
        double circulatingSupply; // 21000000	
        double availableSupply; // 21000000
};