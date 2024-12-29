#include "exchange.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <algorithm>

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
Exchange::Exchange()
{
    srand(static_cast<unsigned>(time(0)));
}

Exchange::~Exchange() {}

bool Exchange::login(const std::string& username, const std::string& password)
{
    for (auto& user : registeredUsers)
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

    registeredUsers.emplace_back(username, password);
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
    auto it = std::find_if(registeredUsers.begin(), registeredUsers.end(), [&username](const User& user)
    {
        return user.getUsername() == username;
    });

    if (it == registeredUsers.end())
    {
        std::cout << "User not found.\n";
        return;
    }

    if (coinMarket.find(signature) == coinMarket.end())
    {
        std::cout << "Coin not available in market.\n";
        return;
    }

    Wallet& wallet = it->getWallet();
    double cost = amount * coinMarket[signature].availableSupply;

    if (wallet.getBalance() < cost)
    {
        std::cout << "Insufficient USDT balance.\n";
        return;
    }

    wallet.topupBalance(-cost);
    wallet.receiveCoin(signature, amount);

    std::string timestamp = getCurrentTime();
    blockchain.addBlock({wallet.getAddress(), "Exchange", amount, timestamp, signature});

    std::cout << "Purchase successful.\n";
}

void Exchange::sellCoin(const std::string& username, const std::string& signature, double amount)
{
    auto it = std::find_if(registeredUsers.begin(), registeredUsers.end(), [&username](const User& user)
    {
        return user.getUsername() == username;
    });

    if (it == registeredUsers.end())
    {
        std::cout << "User not found.\n";
        return;
    }

    Wallet& wallet = it->getWallet();
    if (!wallet.transferCoin("Exchange", signature, amount))
    {
        return;
    }

    double earnings = amount * coinMarket[signature].availableSupply;
    wallet.topupBalance(earnings);

    std::string timestamp = getCurrentTime();
    blockchain.addBlock({"Exchange", wallet.getAddress(), amount, timestamp, signature});

    std::cout << "Sale successful.\n";
}

void Exchange::sendCoin(const std::string& username, std::string& toAddress, const std::string& signature, double amount)
{
    auto it = std::find_if(registeredUsers.begin(), registeredUsers.end(), [&username](const User& user)
    {
        return user.getUsername() == username;
    });

    if (it == registeredUsers.end())
    {
        std::cout << "User not found.\n";
        return;
    }

    Wallet& wallet = it->getWallet();

    auto it = std::find_if(registeredUsers.begin(), registeredUsers.end(), [&toAddress](User& user)
    {
        return user.getWallet().getAddress() == toAddress;
    });

    if (it == registeredUsers.end())
    {
        std::cout << "Recipient not found.\n";
        return;
    }
    Wallet& recipientWallet = it->getWallet();

    if(amount > wallet.getBalance())
    {
        std::cout << "Insufficient balance for transfer.\n";
        return;
    }

    recipientWallet.topupBalance(amount);

    std::string timestamp = getCurrentTime();
    blockchain.addBlock({wallet.getAddress(), toAddress, amount, timestamp, signature});

    std::cout << "Transfer successful.\n";
}