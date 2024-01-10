#include "depositcalc.h"
#include "ui_depositcalc.h"

depositcalc::depositcalc(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::depositcalc)
{
    ui->setupUi(this);
}

depositcalc::~depositcalc()
{
    delete ui;
}
