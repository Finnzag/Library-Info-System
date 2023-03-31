#include "dashboardwindow.h"
#include "ui_dashboardwindow.h"
#include "user.h"
#include "QDebug"

<<<<<<< Updated upstream
DashboardWindow::DashboardWindow(QWidget *parent) :
=======
// Function delcaration
//void editUserDetails(QString userToEdit, QString newUsername, QString newPassword, bool newAdminState);
void loadUserInfo();
void saveUserInfo();

// Variables
QString userToEdit;
// create a username and password vector
std::vector<User> UserVec;


DashboardWindow::DashboardWindow(bool adminStatus, QWidget *parent) :
>>>>>>> Stashed changes
    QMainWindow(parent),
    ui(new Ui::DashboardWindow)
{
    ui->setupUi(this);

    if (isAdminUser){
        ui->EditAccountButton->show();
        ui->EditCatalogueButton->show();
    }else{
        ui->EditAccountButton->hide();
        ui->EditCatalogueButton->hide();
    }

    qInfo() << isAdminUser;
}

DashboardWindow::~DashboardWindow()
{
    delete ui;
}

void DashboardWindow::setIsAdminUser(bool adminStatus){
    isAdminUser = adminStatus;
}
<<<<<<< Updated upstream
=======

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

            //User u(QString::fromStdString(readInUsername), QString::fromStdString(readInpassword), readInAdminState);
            //UserVec.push_back(u);
        }
    }

    UsernameFile.close();
    PasswordFile.close();
    AdminStateFile.close();
}

void saveUserInfo(){

}

//void editUserDetails(QString userToEdit, QString newUsername, QString newPassword, bool newAdminState){
//    for (int i = 0; i < UNVec.size(); i++) {
//        if (userToEdit == UNVec[i]){
//            if (newUsername != ""){
//                UNVec[i] = newUsername;
//            }
//            else{
//                UNVec[i] = UNVec[i];
//            }
//
//            if (newPassword != ""){
//                PWVec[i] = newPassword;
//            }
//            else{
//                PWVec[i] = PWVec[i];
//            }
//
//            ASVec[i] = newAdminState;
//        }
//    }
//}

>>>>>>> Stashed changes
