#include <template.h>

Template::Template()
{

}

void Template::setUsername(std::string username)
{
    this->username = username;
}

void Template::setPassword(std::string password)
{
    this->password = password;
}

std::string Template::getUsername()
{
    return this->username;
}

std::string Template::getPassword()
{
    return this->password;
}
