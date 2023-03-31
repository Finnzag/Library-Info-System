#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QMainWindow>
#include "dashboardwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class LoginWindow; }
QT_END_NAMESPACE

class LoginWindow : public QMainWindow
{
    Q_OBJECT

public:
    LoginWindow(QWidget *parent = nullptr);
    ~LoginWindow();

private slots:

    void on_exitButton_clicked();

    void on_submitButton_clicked();

private:
    Ui::LoginWindow *ui;
    DashboardWindow *dashboardWindow;

    QString uName;
    QString uPassword;

public:
    QString getPassword();
    QString getUseraname();
};
#endif // LOGINWINDOW_H
