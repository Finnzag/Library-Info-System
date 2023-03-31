#ifndef DASHBOARDWINDOW_H
#define DASHBOARDWINDOW_H

#include <QMainWindow>

namespace Ui {
class DashboardWindow;
}

class DashboardWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit DashboardWindow(bool adminStatus, QWidget *parent = nullptr);
    ~DashboardWindow();

private:
    Ui::DashboardWindow *ui;

    // Hold the admin status of the currently logged in user
    bool isAdminUser;

public:
    void setIsAdminUser(bool adminStatus);
private slots:
    void on_MyAccountButton_clicked();
    void on_EditAccountButton_clicked();
    void on_pushButton_clicked();
    void on_saveDetailsButton_clicked();
};

#endif // DASHBOARDWINDOW_H
