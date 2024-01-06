#include "smartcalc.h"
#include "ui_smartcalc.h"

smartCalc::smartCalc(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::smartCalc)
{
    ui->setupUi(this);

    // method takeSymbols()
    connect(ui->btn_num_0, SIGNAL(clicked()), this, SLOT(takeSymbols()));
    connect(ui->btn_num_1, SIGNAL(clicked()), this, SLOT(takeSymbols()));
    connect(ui->btn_num_2, SIGNAL(clicked()), this, SLOT(takeSymbols()));
    connect(ui->btn_num_3, SIGNAL(clicked()), this, SLOT(takeSymbols()));
    connect(ui->btn_num_4, SIGNAL(clicked()), this, SLOT(takeSymbols()));
    connect(ui->btn_num_5, SIGNAL(clicked()), this, SLOT(takeSymbols()));
    connect(ui->btn_num_6, SIGNAL(clicked()), this, SLOT(takeSymbols()));
    connect(ui->btn_num_7, SIGNAL(clicked()), this, SLOT(takeSymbols()));
    connect(ui->btn_num_8, SIGNAL(clicked()), this, SLOT(takeSymbols()));
    connect(ui->btn_num_9, SIGNAL(clicked()), this, SLOT(takeSymbols()));
    connect(ui->btn_dot, SIGNAL(clicked()), this, SLOT(takeSymbols()));
    connect(ui->btn_action_bracketRight, SIGNAL(clicked()), this, SLOT(takeSymbols()));
    connect(ui->btn_action_bracketLeft, SIGNAL(clicked()), this, SLOT(takeSymbols()));
    connect(ui->btn_action_plus, SIGNAL(clicked()), this, SLOT(takeSymbols()));
    connect(ui->btn_action_minus, SIGNAL(clicked()), this, SLOT(takeSymbols()));
    connect(ui->btn_action_toShare, SIGNAL(clicked()), this, SLOT(takeSymbols()));
    connect(ui->btn_action_multiply, SIGNAL(clicked()), this, SLOT(takeSymbols()));
    connect(ui->btn_num_x, SIGNAL(clicked()), this, SLOT(takeSymbols()));
    connect(ui->btn_action_up, SIGNAL(clicked()), this, SLOT(takeSymbols()));

    // method trigonometricFunctions()
    connect(ui->btn_action_sin, SIGNAL(clicked()), this, SLOT(trigonometricFunctions()));
    connect(ui->btn_action_tan, SIGNAL(clicked()), this, SLOT(trigonometricFunctions()));
    connect(ui->btn_action_sqrt, SIGNAL(clicked()), this, SLOT(trigonometricFunctions()));
    connect(ui->btn_action_atan, SIGNAL(clicked()), this, SLOT(trigonometricFunctions()));
    connect(ui->btn_action_acos, SIGNAL(clicked()), this, SLOT(trigonometricFunctions()));
    connect(ui->btn_action_asin, SIGNAL(clicked()), this, SLOT(trigonometricFunctions()));
    connect(ui->btn_action_cos, SIGNAL(clicked()), this, SLOT(trigonometricFunctions()));
    connect(ui->btn_action_ln, SIGNAL(clicked()), this, SLOT(trigonometricFunctions()));
    connect(ui->btn_action_log, SIGNAL(clicked()), this, SLOT(trigonometricFunctions()));

    // method clickedBtnClearAll()
    connect(ui->btn_action_deleteAllChar, SIGNAL(clicked()), this, SLOT(clickedBtnClearAll()));

    // method clickedBtnPi()
    connect(ui->btn_num_pi, SIGNAL(clicked()), this, SLOT(clickedBtnPi()));

    // method clickedBtnClearLastChar()
    connect(ui->btn_action_deleteLastChar, SIGNAL(clicked()), this, SLOT(clickedBtnClearLastChar()));

    // method equalls()
    connect(ui->btn_action_equally, SIGNAL(clicked()), this, SLOT(equalls()));

    // top menu contecst
    connect(ui->action_close_program, SIGNAL(triggered()), this, SLOT(closeProgram()));
    connect(ui->action_open_baseCalc, SIGNAL(triggered()), this, SLOT(openBaseCalc()));
    connect(ui->action_open_depositCalc, SIGNAL(triggered()), this, SLOT(openDepositCalc()));
    connect(ui->action_open_creditCalc, SIGNAL(triggered()), this, SLOT(openCreditCalc()));
}

smartCalc::~smartCalc()
{
    delete ui;
}

void smartCalc::closeProgram(){
    QApplication::quit();
}

void smartCalc::openBaseCalc(){
    ui->statusBar->showMessage("open Base Calc");
}

void smartCalc::openDepositCalc(){
    ui->statusBar->showMessage("open Deposit Calc");
}

void smartCalc::openCreditCalc(){
    ui->statusBar->showMessage("open Credit Calc");
}

void smartCalc::takeSymbols(){
    QPushButton *button = (QPushButton *)sender();
    ui->input_result->setText(ui->input_result->text()+button->text());
}

void smartCalc::trigonometricFunctions(){
    QPushButton *button = (QPushButton *)sender();
    ui->input_result->setText(ui->input_result->text()+button->text() + "(");
}

void smartCalc::clickedBtnDot()
{
    ui->input_result->setText(ui->input_result->text() + ".");
}

void smartCalc::clickedBtnClearAll()
{
    ui->input_result->clear();
}

void smartCalc::clickedBtnPi()
{
    ui->input_result->setText(ui->input_result->text() + QString::number(M_PI, 'g', 6));
}

void smartCalc::clickedBtnClearLastChar()
{
    QString expression = ui->input_result->text();

    if(!expression.isEmpty()){
        ui->input_result->setText(ui->input_result->text().chopped(1));
    } else {
        ui->input_result->clear();
    }
}

void smartCalc::equalls(){

    QString expression = ui->input_result->text();

    if(expression.isEmpty()){
        return;
    }

    QByteArray byteArray = expression.toLocal8Bit();
    char *infix = byteArray.data();
    char *postfix = (char *)malloc(MAX_SIZE * sizeof(char));
    int code = 0;
    code = infixToPostfix(infix, postfix);

    if (!code) {
        double result;

        if (ui->input_additional_x->text().isEmpty()) {
            code = processPostfix(postfix, NAN, &result);
        } else {
            code =
                processPostfix(postfix, ui->input_additional_x->text().toDouble(), &result);
        }

        if (!code) {
            ui->input_result->setText(QString::number(result, 'g', 15));
        } else {
            ui->input_result->setText("ERROR");
        }
    } else {
        ui->input_result->setText("ERROR");
    }

    free(postfix);
}
