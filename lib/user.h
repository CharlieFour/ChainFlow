#pragma once

#include <string>
#include <template.h>
class User
{
    private:
        Template info;
    public:
        User();
        User(std::string name, std::string password);
        ~User();
};