#include "dashboardwindow.h"
#include "ui_dashboardwindow.h"
#include "QDebug"
#include <fstream>

// Function delcaration
void editUserDetails(QString userToEdit, QString newUsername, QString newPassword, bool newAdminState);
void loadUserInfo();

// Variables
QString userToEdit;
// create a username and password vector
std::vector<QString> UNVec;
std::vector<QString> PWVec;
std::vector<int> ASVec;


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
    ui->userToEditBox->show();
}

void DashboardWindow::on_pushButton_clicked()
{
    userToEdit = ui->UserToEditInput->text();
    ui->userToEditBox->hide();
    ui->editUserBox->show();
}

void DashboardWindow::on_saveDetailsButton_clicked()
{
    editUserDetails(userToEdit, ui->newUsernameEdit->text(), ui->newPasswordEdit->text(), ui->adminCheckBox->isChecked());
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
            UNVec.push_back(QString::fromStdString(readInUsername));
            PasswordFile >> readInpassword;
            PWVec.push_back(QString::fromStdString(readInpassword));
            AdminStateFile >> readInAdminState;
            ASVec.push_back(readInAdminState);
        }
    }
}

void editUserDetails(QString userToEdit, QString newUsername, QString newPassword, bool newAdminState){

}

