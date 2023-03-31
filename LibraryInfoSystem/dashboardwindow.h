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
    explicit DashboardWindow(QWidget *parent = nullptr);
    ~DashboardWindow();

private:
    Ui::DashboardWindow *ui;

    // Hold the admin status of the currently logged in user
    bool isAdminUser;

public:
    void setIsAdminUser(bool adminStatus);
};

#endif // DASHBOARDWINDOW_H
