#include "dashboardwindow.h"
#include "ui_dashboardwindow.h"
#include "user.h"
#include "QDebug"
#include <QMessageBox>
#include <fstream>

// Function delcaration
//void editUserDetails(QString userToEdit, QString newUsername, QString newPassword, bool newAdminState);
void loadUserInfo();

// Variables
QString userToEdit;
// create a username and password vector
//std::vector<QString> UNVec;
//std::vector<QString> PWVec;
//std::vector<int> ASVec;
std::vector<User> UserVec;


DashboardWindow::DashboardWindow(bool adminStatus, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DashboardWindow),
    isAdminUser(adminStatus)
{
    ui->setupUi(this);

    if (isAdminUser){
        ui->EditAccountButton->show();
        ui->EditCatalogueButton->show();
    }else{
        ui->EditAccountButton->hide();
        ui->EditCatalogueButton->hide();
    }

    ui->userToEditBox->hide();
    ui->editUserBox->hide();

    loadUserInfo();
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
    //QMessageBox::information(this, "Test", "Test1");
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
            QMessageBox::warning(this, "Incorrect User", "Please enter an existing username");
            on_EditAccountButton_clicked();
            break;
        }
    }


    ui->userToEditBox->hide();
    ui->editUserBox->show();
}

void DashboardWindow::on_saveDetailsButton_clicked()
{
    //editUserDetails(userToEdit, ui->newUsernameEdit->text(), ui->newPasswordEdit->text(), ui->adminCheckBox->isChecked());
    ui->newUsernameEdit->clear();
    ui->newPasswordEdit->clear();
    ui->editUserBox->hide();
}

void loadUserInfo(){
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
            PasswordFile >> readInpassword;
            AdminStateFile >> readInAdminState;

            User U(QString::fromStdString(readInUsername), QString::fromStdString(readInUsername), readInAdminState);

            UserVec.push_back(U);
        }
    }
}

//void editUserDetails(QString userToEdit, QString newUsername, QString newPassword, bool newAdminState){
//
//}

