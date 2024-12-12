#pragma once

#include <string>
#include <template.h>
class Admin
{
    private:
        Template info;
    public:
        Admin();
        ~Admin();
        void addCoin();
        void removeCoin();
        void burnCoin();
};