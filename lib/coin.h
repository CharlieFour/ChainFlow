#pragma once
// abhey rafay, hum blockchain bana rahien hai, coin market nhi :)
#include <string>
struct Coin
{
    public:
        std::string signature;
        double maxSupply;
        double circulatingSupply;
        double availableSupply;
};