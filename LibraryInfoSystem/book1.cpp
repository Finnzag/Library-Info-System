#include "book1.h"
#include "ui_book1.h"

Book1::Book1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Book1)
{
    ui->setupUi(this);
}

Book1::~Book1()
{
    delete ui;
}
