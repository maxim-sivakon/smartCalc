#include "smartcalcfront.h"
#include "ui_smartcalcfront.h"

smartCalcFront::smartCalcFront(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::smartCalcFront)
{
    ui->setupUi(this);
}

smartCalcFront::~smartCalcFront()
{
    delete ui;
}
