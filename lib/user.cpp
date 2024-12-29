#include "user.h"


User::User()
{
    
}
User::User(std::string name, std::string password)
{
    this->username = name;
    this->password = password;
}

User::~User()
{
    
}

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