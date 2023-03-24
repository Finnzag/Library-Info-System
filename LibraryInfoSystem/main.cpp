#include "loginwindow.h"

#include <QApplication>

std::vector<QString> userPassword;
std::vector<QString> userName;

// Function declarations
void checkLoginDetails();

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LoginWindow w;
    w.show();
    userName.push_back("Finn");
    userPassword.push_back("1234");
    return a.exec();
}

void checkLoginDetails(){

    LoginWindow W;

    for (int i = 0; i < userName.size(); i++) {
        if (userName[i] == W.getUseraname() && userPassword[i] == W.getPassword()){

        }
    }
}
