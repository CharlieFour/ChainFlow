#include "exchange.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

Exchange::Exchange()
{
    srand(static_cast<unsigned>(time(0)));
}

Exchange::~Exchange() {}

bool Exchange::login(const std::string& username, const std::string& password)
{
    for (const auto& user : registeredUsers)
    {
        if (user.getUsername() == username && user.getPassword() == password)
        {
            std::cout << "Login successful.\n";
            return true;
        }
    }
    std::cout << "Invalid username or password.\n";
    return false;
}

bool Exchange::registerUser(const std::string& username, const std::string& password, const std::string& cpassword)
{
    if (password != cpassword)
    {
        std::cout << "Passwords do not match.\n";
        return false;
    }

    for (const auto& user : registeredUsers)
    {
        if (user.getUsername() == username)
        {
            std::cout << "Username already exists.\n";
            return false;
        }
    }

    User newUser(username, password);
    registeredUsers.push_back(newUser);

    Wallet newWallet;
    newWallet.setAddress(username + "_address");
    userWallets[username] = newWallet;

    std::cout << "Registration successful.\n";
    return true;
}

void Exchange::simulateMarket()
{
    for (auto& [signature, coin] : coinMarket)
    {
        double priceFluctuation = ((rand() % 2001) - 1000) / 10000.0; // +/-10% fluctuation
        coin.availableSupply *= (1 + priceFluctuation);
    }
}

void Exchange::addCoinToMarket(const Coin& coin)
{
    coinMarket[coin.signature] = coin;
    std::cout << coin.signature << " added to market.\n";
}

void Exchange::buyCoin(const std::string& username, const std::string& signature, double amount)
{
    if (coinMarket.find(signature) == coinMarket.end())
    {
        std::cout << "Coin not available in market.\n";
        return;
    }

    double cost = amount * coinMarket[signature].availableSupply;

    if (userWallets[username].getBalance() < cost)
    {
        std::cout << "Insufficient USDT balance.\n";
        return;
    }

    userWallets[username].topupBalance(-cost);
    userWallets[username].addCoin(coinMarket[signature], amount);
    blockchain.addBlock({username, "Exchange", amount, "2024-12-28T12:00:00Z", ""});

    std::cout << "Purchase successful.\n";
}

void Exchange::sellCoin(const std::string& username, const std::string& signature, double amount)
{
    userWallets[username].transferCoin("Exchange", signature, amount);
    double earnings = amount * coinMarket[signature].availableSupply;
    userWallets[username].topupBalance(earnings);

    blockchain.addBlock({"Exchange", username, amount, "2024-12-28T12:00:00Z", ""});
    std::cout << "Sale successful.\n";
}