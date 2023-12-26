#include "smartcalc.h"
#include "ui_smartcalc.h"

smartCalc::smartCalc(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::smartCalc)
{
    ui->setupUi(this);

    connect(ui->btn_num_0, SIGNAL(clicked()), this, SLOT(digits_btn_numbers()));
    connect(ui->btn_num_1, SIGNAL(clicked()), this, SLOT(digits_btn_numbers()));
    connect(ui->btn_num_2, SIGNAL(clicked()), this, SLOT(digits_btn_numbers()));
    connect(ui->btn_num_3, SIGNAL(clicked()), this, SLOT(digits_btn_numbers()));
    connect(ui->btn_num_4, SIGNAL(clicked()), this, SLOT(digits_btn_numbers()));
    connect(ui->btn_num_5, SIGNAL(clicked()), this, SLOT(digits_btn_numbers()));
    connect(ui->btn_num_6, SIGNAL(clicked()), this, SLOT(digits_btn_numbers()));
    connect(ui->btn_num_7, SIGNAL(clicked()), this, SLOT(digits_btn_numbers()));
    connect(ui->btn_num_8, SIGNAL(clicked()), this, SLOT(digits_btn_numbers()));
    connect(ui->btn_num_9, SIGNAL(clicked()), this, SLOT(digits_btn_numbers()));
}

smartCalc::~smartCalc()
{
    delete ui;
}

void smartCalc::digits_btn_numbers(){
    QPushButton *button = (QPushButton *)sender();

    double all_numbers;
    QString result_label;

    all_numbers = (ui->input_result->text() + button->text()).toDouble();
    result_label = QString::number(all_numbers, 'g', 20);

    ui->input_result->setText(result_label);
}

void smartCalc::on_btn_char_dot_clicked()
{
    if(!(ui->input_result->text().contains('.'))){
       ui->input_result->setText(ui->input_result->text() + ".");
    }
}

