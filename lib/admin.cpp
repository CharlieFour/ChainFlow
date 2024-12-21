#include "admin.h"

Admin::Admin()
{

}

Admin::Admin(std::string userName, std::string password)
{
    info.setUsername(userName);
    info.setPassword(password);
}

Admin::~Admin()
{

}	

Coin Admin::addCoin(std::string signature, double maxSupply, double circulatingSupply, double availableSupply)
{
    Coin coin;
    coin.signature = signature;
    coin.maxSupply = maxSupply;
    coin.circulatingSupply = circulatingSupply;
    coin.availableSupply = availableSupply;
    return coin;
}

void Admin::removeCoin(std::string signature)
{
    /*for(auto& coin : coinList)
    {
        if(coin.signature == signature)
        {
            coinList.erase(coinList.begin());
            break;
        }
    }*/
}

void Admin::burnCoin(std::string signature, double amount)
{
    //admin only able to burn coins only if he have sufficient coins balance
    /*for(auto& coin : coinList)
    {
        if(coin.signature == signature)
        {
            coin.availableSupply -= amount;
            break;
        }
    }*/
}