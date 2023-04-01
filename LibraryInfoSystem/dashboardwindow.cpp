#include "dashboardwindow.h"
#include "ui_dashboardwindow.h"
#include "QDebug"

DashboardWindow::DashboardWindow(QWidget *parent) :
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

void DashboardWindow::on_EditCatalogueButton_clicked()
{

}


void DashboardWindow::on_pushButton_clicked()
{

}


void DashboardWindow::on_pushButton_2_clicked()
{

}

