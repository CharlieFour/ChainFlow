#pragma once

#include <string>
#include <list>
#include <unordered_map>
#include "chainFlow.h"
#include "user.h"

class Exchange
{
private:
    ChainFlow blockchain;
    std::list<User> registeredUsers;
    std::unordered_map<std::string, Coin> coinMarket;

    void simulateMarket();

public:
    Exchange();
    ~Exchange();

    bool login(const std::string& username, const std::string& password);
    bool registerUser(const std::string& username, const std::string& password, const std::string& cpassword);

    void addCoinToMarket(const Coin& coin);
    void buyCoin(const std::string& username, const std::string& signature, double amount);
    void sellCoin(const std::string& username, const std::string& signature, double amount);
    void sendCoin(const std::string& username, std::string& toAddress, const std::string& signature, double amount);
};
