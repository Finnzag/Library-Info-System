#include "user.h"

User::User(QString username, QString password, bool isAdmin):
    username(username), password(password), isAdmin(isAdmin)
{

}

void User::setUsername(QString Iusername)
{
    username = Iusername;
}

void User::setPassword(QString Ipassword)
{
    password = Ipassword;
}

void User::setIsAdmin(bool IisAdmin)
{
    isAdmin = IisAdmin;
}

QString User::getUsername()
{
    return username;
}

QString User::getpassword()
{
    return password;
}

QString User::getIsAdmin()
{
    switch (isAdmin) {
    case 0:
        return "false";
        break;
    case 1:
        return "true";
        break;
    }
}
