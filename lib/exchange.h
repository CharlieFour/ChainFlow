#include <string>

class Exchange
{
    private:
    public:
    bool login(std::string username, std::string password);
    bool registerUser(std::string username, std::string password, std::string cpassword, std::string name);

};