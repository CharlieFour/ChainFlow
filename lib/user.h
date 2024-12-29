#pragma once

#include <string>
#include "wallet.h"

class User
{
private:
    std::string username;
    std::string password;
    Wallet wallet; // Wallet object associated with the user

public:
    User();
    User(std::string name, std::string password);
    ~User();

    std::string getUsername() const;
    std::string getPassword() const;

    void setUsername(std::string username);
    void setPassword(std::string password);

    Wallet& getWallet(); // Getter for accessing the user's wallet
};
