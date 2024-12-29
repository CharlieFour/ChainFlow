#include "user.h"

User::User() {}

User::User(std::string name, std::string password) : username(name), password(password)
{
    wallet.setAddress(name + "_address"); // Initialize wallet address during user creation
}

User::~User() {}

std::string User::getUsername() const
{
    return this->username;
}

std::string User::getPassword() const
{
    return this->password;
}

void User::setUsername(std::string username)
{
    this->username = username;
}

void User::setPassword(std::string password)
{
    this->password = password;
}

Wallet& User::getWallet()
{
    return wallet;
}
