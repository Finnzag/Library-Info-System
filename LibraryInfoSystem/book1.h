#ifndef BOOK1_H
#define BOOK1_H

#include <QDialog>

namespace Ui {
class Book1;
}

class Book1 : public QDialog
{
    Q_OBJECT

public:
    explicit Book1(QWidget *parent = nullptr);
    ~Book1();

private:
    Ui::Book1 *ui;
};

#endif // BOOK1_H
