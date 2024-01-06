#include "graphcalc.h"
#include "ui_graphcalc.h"

graphcalc::graphcalc(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::graphcalc)
{
    ui->setupUi(this);
}

graphcalc::~graphcalc()
{
    delete ui;
}
