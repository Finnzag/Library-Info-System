#include "loginwindow.h"
#include <string>
#include <fstream>
#include <QMessageBox>
#include <qdebug.h>
#include "ui_loginwindow.h"

// create a username and password vector
std::vector<QString> UNVec;
std::vector<QString> PWVec;
std::vector<int> ASVec;

LoginWindow::LoginWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LoginWindow)
{

    ui->setupUi(this);

    // Temp variables for user data
    std::string readInUsername;
    std::string readInpassword;
    bool readInAdminState;


    // load credentials from text file
    std::ifstream UsernameFile("username.txt");
    std::ifstream PasswordFile("password.txt");
    std::ifstream AdminStateFile("adminstate.txt");

    // Transfer loaded data from temp variables to the array for each of them
    if (UsernameFile && PasswordFile && AdminStateFile){
        while (UsernameFile >> readInUsername) {
            UNVec.push_back(QString::fromStdString(readInUsername));
            PasswordFile >> readInpassword;
            PWVec.push_back(QString::fromStdString(readInpassword));
            AdminStateFile >> readInAdminState;
            ASVec.push_back(readInAdminState);
        }
    }
}

LoginWindow::~LoginWindow()
{
    delete ui;
}

void LoginWindow::on_exitButton_clicked()
{
    LoginWindow::close();
}


void LoginWindow::on_submitButton_clicked()
{
    bool bDoOnce = true;
    //ui->loginDetailsBox->setVisible(false);
    uName = ui->UNInput->text();
    ui->UNInput->clear();
    uPassword = ui->PassInput->text();
    ui->PassInput->clear();

    // Compare enetered text to PW and UN saves by programme
    for (int i = 0;  i < UNVec.size(); i++) {

        if (uName == UNVec[i]){
            if (uPassword == PWVec[i]){
                QMessageBox::information(this, "Login", "Username and Password are correct");
                hide();
                // hide login window and create the dashboard window
                dashboardWindow = new DashboardWindow(ASVec[i], this);
                dashboardWindow->show();
                bDoOnce = true;
            }
            else{
                bDoOnce = false;
                if (bDoOnce == false){
                    QMessageBox::warning(this, "Login", "Username or Password are incorrect");
                    bDoOnce = true;
                }
            }
        }
        else{
            if (bDoOnce == false){
                QMessageBox::warning(this, "Login", "Username or Password are incorrect");
                bDoOnce = true;
            }
        }
    }

}

