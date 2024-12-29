#pragma once

#include <string>
class User
{
    private:
        std::string username;
        std::string password;
    public:
        User();
        User(std::string name, std::string password);
        ~User();
        std::string getUsername() const;
        std::string getPassword() const;
        void setUsername(std::string username);
        void setPassword(std::string password);
};