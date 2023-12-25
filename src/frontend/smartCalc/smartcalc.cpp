#include "smartcalc.h"
#include "ui_smartcalc.h"

smartCalc::smartCalc(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::smartCalc)
{
    ui->setupUi(this);
}

smartCalc::~smartCalc()
{
    delete ui;
}
