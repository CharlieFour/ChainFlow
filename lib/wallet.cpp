#include <wallet.h>
#include <iostream>

Wallet::Wallet()
{
    
}

Wallet::~Wallet()
{

}

void Wallet::setAddress(std::string address)
{
    this->address = address;
}

std::string Wallet::getAddress()
{
    return this->address;
}

void Wallet::topupBalance()
{
    //user can topup balance by sending coins to his wallet address
}

void Wallet::printCoins()
{
    //print all the coins available in the wallet
    for(auto& coin : coinList)
    {
        std::cout << coin.first << " : " << coin.second << std::endl;
    }
}

void Wallet::printBalance()
{
    std::cout << "USDT: " << USDT << std::endl;
}

void Wallet::transferCoin(std::string address, std::string signature, int amount)
{
    //user can transfer coins to another user
    for(auto& wallet : walletList)
    {
        if(wallet.getAddress() == address)
        {
            for(auto& coin : coinList)
            {
                if(coin.first == signature)
                {
                    if(coin.second >= amount)
                    {
                        coin.second -= amount;
                        wallet.coinList.push_back(std::make_pair(signature, amount));
                        break;
                    }
                    else
                    {
                        std::cout << "Insufficient balance" << std::endl;
                    }
                }
            }
        }
    }
}

void Wallet::receiveCoin()
{
    //user can receive coins from other users
}

void Wallet::printTransactions()
{
    //print all the transactions of the user
}

void Wallet::printTransactionHistory()
{
    //print the transaction history of the user
}