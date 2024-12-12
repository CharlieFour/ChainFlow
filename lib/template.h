#pragma once

#include <string>

class Template
{
        std::string username;
        std::string password;
    public:
        Template();
        ~Template();
        void setUsername(std::string username);
        void setPassword(std::string password);
        std::string getUsername();
        std::string getPassword();
        void registerAdmin(std::string name, std::string password);
        void loginAdmin();
        void registerUser(std::string name, std::string password);
        void loginUser();
};