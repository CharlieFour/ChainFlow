#pragma once

#include <string>
#include <unordered_map>
#include "coin.h"
#include "chainFlow.h"

class Wallet
{
private:
    double USDT; // Balance in USDT
    std::string address;
    std::unordered_map<std::string, double> coinList; // Coin signature and balance

public:
    Wallet();
    ~Wallet();

    void setAddress(const std::string& address);
    std::string getAddress() const;

    void topupBalance(double amount);
    double getBalance() const;

    void addCoin(const Coin& coin, double amount);
    bool transferCoin(const std::string& toAddress, const std::string& signature, double amount);
    void receiveCoin(const std::string& signature, double amount);

    void printPortfolio() const;
};
