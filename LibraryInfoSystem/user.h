#ifndef USER_H
#define USER_H

#include <QMainWindow>


class User
{
public:
    User();

public:

    void setAccountName(QString name);
    void setUsername(QString username);
    void setPassword(QString password);
    void setIsAdmin(char isAdmin);

    QString getAccountName();
    QString getUsername();
    QString getpassword();
    QString getIsAdmin();

private:
    QString accountName;
    QString username;
    QString password;
    bool isAdmin;

};

#endif // USER_H
