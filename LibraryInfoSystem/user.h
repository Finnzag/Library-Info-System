#ifndef USER_H
#define USER_H

#include <string>

class User
{
public:
    User();

public:

    void setAccountName(std::string name);
    void setUsername(std::string username);
    void setPassword(std::string password);
    void setIsAdmin(char isAdmin);

    std::string getAccountName();
    std::string getUsername();
    std::string getpassword();
    std::string getIsAdmin();

private:
    std::string accountName;
    std::string username;
    std::string password;
    bool isAdmin;
};

#endif // USER_H
