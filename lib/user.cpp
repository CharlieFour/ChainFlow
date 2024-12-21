#include "user.h"


User::User()
{
    
}
User::User(std::string name, std::string password)
{
    info.setUsername(name);
    info.setPassword(password);
}

User::~User()
{
    
}	