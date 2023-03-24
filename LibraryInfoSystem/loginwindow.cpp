#include "loginwindow.h"
#include "ui_loginwindow.h"


LoginWindow::LoginWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LoginWindow)
{

    ui->setupUi(this);
}

LoginWindow::~LoginWindow()
{
    delete ui;
}


void LoginWindow::on_loginButton_clicked()
{
    ui->loginDetailsBox->setVisible(true);
}


void LoginWindow::on_exitButton_clicked()
{
    LoginWindow::close();
}


void LoginWindow::on_submitButton_clicked()
{
    ui->loginDetailsBox->setVisible(false);
    uName = ui->UNInput->text();
    uPassword = ui->PassInput->text();
}

