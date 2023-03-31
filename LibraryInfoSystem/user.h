#ifndef USER_H
#define USER_H

#include <string>
#include <QWindow>

class User
{
public:
    User(QString username, QString password, bool adminState);

public:

    void setUsername(QString username);
    void setPassword(QString password);
    void setIsAdmin(char isAdmin);

    QString getUsername();
    QString getpassword();
    QString getIsAdmin();

private:
    QString username;
    QString password;
    bool isAdmin;
};

#endif // USER_H
