#include "loginwindow.h"
#include "book.h"

#include <QApplication>

std::vector<QString> userPasswordVec;
std::vector<QString> userNameVec;

std::vector<Book> booksVec;

// Function declarations
void checkLoginDetails();

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LoginWindow w;
    w.show();
    return a.exec();
}

void checkLoginDetails(){

    LoginWindow W;

    for (int i = 0; i < userNameVec.size(); i++) {
        if (userNameVec[i] == W.getUseraname() && userPasswordVec[i] == W.getPassword()){

        }
    }
}
