#include <string>
struct Block
{
    std::string senderAddress;
    std::string receiverAddress;
    std::string hash;
    std::string previousHash;
    double amount;
    std::string timestamp; //chorono
    std::string signature;
};
