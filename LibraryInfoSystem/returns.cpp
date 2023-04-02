#include "returns.h"
#include "ui_returns.h"

Returns::Returns(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Returns)
{
    ui->setupUi(this);
}

Returns::~Returns()
{
    delete ui;
}
