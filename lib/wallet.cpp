#include "wallet.h"
#include <iostream>
#include <iomanip>

Wallet::Wallet() : USDT(0) {}

Wallet::~Wallet() {}

void Wallet::setAddress(const std::string& address)
{
    this->address = address;
}

std::string Wallet::getAddress() const
{
    return address;
}

void Wallet::topupBalance(double amount)
{
    USDT += amount;
    std::cout << "Balance topped up. Current USDT: " << USDT << "\n";
}

double Wallet::getBalance() const
{
    return USDT;
}

void Wallet::addCoin(const Coin& coin, double amount)
{
    if (amount > coin.availableSupply)
    {
        std::cout << "Insufficient available supply of " << coin.signature << "\n";
        return;
    }

    coinList[coin.signature] += amount;
    std::cout << amount << " " << coin.signature << " added to wallet.\n";
}

void Wallet::transferCoin(const std::string& toAddress, const std::string& signature, double amount)
{
    if (coinList[signature] < amount)
    {
        std::cout << "Insufficient " << signature << " balance for transfer.\n";
        return;
    }

    coinList[signature] -= amount;
    std::cout << amount << " " << signature << " transferred to " << toAddress << "\n";
}

void Wallet::receiveCoin(const std::string& signature, double amount)
{
    coinList[signature] += amount;
    std::cout << amount << " " << signature << " received.\n";
}

void Wallet::printPortfolio() const
{
    std::cout << "Wallet Portfolio:\n";
    for (const auto& coin : coinList)
    {
        std::cout << "- " << coin.first << ": " << std::fixed << std::setprecision(2) << coin.second << "\n";
    }
}