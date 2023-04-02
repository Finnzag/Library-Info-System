#ifndef RETURNS_H
#define RETURNS_H

#include <QDialog>

namespace Ui {
class Returns;
}

class Returns : public QDialog
{
    Q_OBJECT

public:
    explicit Returns(QWidget *parent = nullptr);
    ~Returns();

private:
    Ui::Returns *ui;
};

#endif // RETURNS_H
