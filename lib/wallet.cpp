#include "wallet.h"
#include <iostream>
#include <iomanip>
#include <chrono>
#include <ctime>

std::string getCurrentTime()
{
    auto now = std::chrono::system_clock::now();
    std::time_t currentTime = std::chrono::system_clock::to_time_t(now);
    auto milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()) % 1000;

    std::ostringstream oss;
    oss << std::put_time(std::localtime(&currentTime), "%Y-%m-%d %H:%M:%S")
        << '.' << std::setfill('0') << std::setw(3) << milliseconds.count();

    return oss.str();
}
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

bool Wallet::transferCoin(const std::string& toAddress, const std::string& signature, double amount)
{
    if (coinList[signature] < amount)
    {
        std::cout << "Insufficient " << signature << " balance for transfer.\n";
        return false;
    }
    coinList[signature] -= amount;
    return true;
}

void Wallet::receiveCoin(const std::string& signature, double amount)
{
    coinList[signature] += amount;
    std::cout << amount << " " << signature << " received.\n";
    std::string timestamp = getCurrentTime();
}

void Wallet::printPortfolio() const
{
    std::cout << "Wallet Portfolio:\n";
    for (const auto& coin : coinList)
    {
        std::cout << "- " << coin.first << ": " << std::fixed << std::setprecision(2) << coin.second << "\n";
    }
}
