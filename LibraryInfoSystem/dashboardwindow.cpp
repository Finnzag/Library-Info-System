#include "dashboardwindow.h"
#include "ui_dashboardwindow.h"
#include "user.h"
#include <QDebug>
#include <QMessageBox>
#include <fstream>

// Function delcaration
void editUserDetails(QString userToEdit, QString newUsername, QString newPassword, bool newAdminState);
void loadUserInfo();
void saveUserInfo();
void createNewUser(QString username, QString password, bool isAdmin);

// Variables
QString userToEdit;
// create a vector of users
std::vector<User> UserVec;


DashboardWindow::DashboardWindow(bool adminStatus, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DashboardWindow),
    isAdminUser(adminStatus)
{
    loadUserInfo();
    ui->setupUi(this);

    if (isAdminUser){
        ui->EditAccountButton->show();
        ui->EditCatalogueButton->show();
        ui->newUserMenuButton->show();
    }else{
        ui->EditAccountButton->hide();
        ui->EditCatalogueButton->hide();
        ui->newUserMenuButton->hide();
    }

    ui->userToEditBox->hide();
    ui->editUserBox->hide();
    ui->newUserWidget->hide();


}

DashboardWindow::~DashboardWindow()
{
    delete ui;
}

void DashboardWindow::setIsAdminUser(bool adminStatus){
    isAdminUser = adminStatus;
}

void DashboardWindow::on_MyAccountButton_clicked()
{

}


void DashboardWindow::on_EditAccountButton_clicked()
{
    ui->userToEditBox->show();
}

void DashboardWindow::on_EditButton_clicked()
{
    userToEdit = ui->UserToEditInput->text();

    for (int i = 0;  i < UserVec.size(); i++) {
        if (UserVec[i].getUsername() == userToEdit){
            ui->userToEditBox->hide();
            ui->editUserBox->show();
        }
        else{
            //QMessageBox::warning(this, "Incorrect User", "Please enter an existing username");
        }
    }


    ui->userToEditBox->hide();
    ui->editUserBox->show();
}

void DashboardWindow::on_saveDetailsButton_clicked()
{
    QString newUN = ui->newUsernameEdit->text();
    QString newPW = ui->newPasswordEdit->text();
    bool newAS = ui->adminCheckBox->isChecked();
    qDebug() << newUN << " " << newPW << " " << newAS << userToEdit;
    editUserDetails(userToEdit, newUN, newPW, newAS);
    ui->newUsernameEdit->clear();
    ui->newPasswordEdit->clear();
    ui->editUserBox->hide();
}

void loadUserInfo(){
    // Temp variables for user data
    std::string readInUsername;
    std::string readInpassword;
    std::string readInAdminState;
    bool adminState;


    // load credentials from text file
    std::ifstream UsernameFile("username.txt");
    std::ifstream PasswordFile("password.txt");
    std::ifstream AdminStateFile("adminstate.txt");



    // Transfer loaded data from temp variables to the array for each of them
    if (UsernameFile && PasswordFile && AdminStateFile){
        while (UsernameFile >> readInUsername) {
            PasswordFile >> readInpassword;
            AdminStateFile >> readInAdminState;
            qDebug() << "adminState";
            if (readInAdminState == "true"){

                adminState = 1;
            }
            else{
                adminState = 0;
            }

            User U(QString::fromStdString(readInUsername), QString::fromStdString(readInUsername), adminState);

            UserVec.push_back(U);
        }
    }
}

void editUserDetails(QString userToEdit, QString newUsername, QString newPassword, bool newAdminState){
    for (int i = 0; i < UserVec.size(); ++i) {
       if (UserVec[i].getUsername() == userToEdit){
           UserVec[i].setUsername(newUsername);
           UserVec[i].setPassword(newPassword);
           UserVec[i].setIsAdmin(newAdminState);
       }
    }
    saveUserInfo();
}

void saveUserInfo(){

    std::ofstream usernameFile;
    std::ofstream passwordFile;
    std::ofstream adminFile;

    for (int i = 0; i < UserVec.size(); i++) {
        if (i > 0){
            usernameFile.open("username.txt", std::ios::out | std::ios::ate | std::ios::app);
            passwordFile.open("password.txt", std::ios::out | std::ios::ate | std::ios::app);
            adminFile.open("adminstate.txt", std::ios::out | std::ios::ate | std::ios::app);
        }
        else{
            usernameFile.open("username.txt", std::ios::trunc | std::ios::out | std::ios::ate);
            passwordFile.open("password.txt", std::ios::trunc | std::ios::out | std::ios::ate);
            adminFile.open("adminstate.txt", std::ios::trunc  | std::ios::out | std::ios::ate);
        }

        usernameFile << std::endl << UserVec[i].getUsername().toStdString();
        passwordFile << std::endl << UserVec[i].getpassword().toStdString();
        adminFile << std::endl << UserVec[i].getIsAdmin().toStdString();

        usernameFile.close();
        passwordFile.close();
        adminFile.close();

    }
}

void createNewUser(QString username, QString password, bool isAdmin){
    User U(username, password, isAdmin);

    UserVec.push_back(U);

    saveUserInfo();
}


void DashboardWindow::on_AddButton_clicked()
{

}


void DashboardWindow::on_RemoveButton_clicked()
{

}


void DashboardWindow::on_exitButton_clicked()
{
    DashboardWindow::close();
}


void DashboardWindow::on_CurrentBooksButton_clicked()
{

}


void DashboardWindow::on_newUserMenuButton_clicked()
{
    ui->newUserWidget->show();
}


void DashboardWindow::on_createNewButton_clicked()
{
    QString usernmaeInput = ui->usernameNew->text();
    QString passwordInput = ui->passwordNew->text();
    bool adminInput = ui->adminCheckBoxNew->isChecked();

    createNewUser(usernmaeInput, passwordInput, adminInput);

    ui->usernameNew->clear();
    ui->passwordNew->clear();

    ui->newUserWidget->hide();
}

