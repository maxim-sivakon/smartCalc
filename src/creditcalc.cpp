#include "creditcalc.h"
#include "ui_creditcalc.h"

creditcalc::creditcalc(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::creditcalc)
{
    ui->setupUi(this);
}

creditcalc::~creditcalc()
{
    delete ui;
}
