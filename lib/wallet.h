#pragma once

#include <string>
#include <vector>

class Wallet
{
    private:
        std::string address;
        std::vector<std::pair<std::string, int>> coinList;      
};