#ifndef USER_H
#define USER_H

#include <QWindow>

class User
{
public:
    User(QString username, QString password, bool isAdmin);

public:

    void setUsername(QString Iusername);
    void setPassword(QString Ipassword);
    void setIsAdmin(bool IisAdmin);

    QString getUsername();
    QString getpassword();
    QString getIsAdmin();

    std::vector<int> booksCheckedOut;

private:

    QString username;
    QString password;
    bool isAdmin;


};

#endif // USER_H
