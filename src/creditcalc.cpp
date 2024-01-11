#include "creditcalc.h"
#include "ui_creditcalc.h"

creditcalc::creditcalc(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::creditcalc)
{
    ui->setupUi(this);

    connect(ui->pushButton_calculate, SIGNAL(clicked()), this, SLOT(calculateCredit()));
}

creditcalc::~creditcalc()
{
    delete ui;
}

void creditcalc::calculateCredit() {
    ui->comboBox_payment->clear();
    ui->label_total_payment->setText("Общая сумма платежа: ");
    ui->label_overpayment->setText("Переплата: ");

    if (!ui->lineEdit_total_loan->text().isEmpty() && !ui->lineEdit_interest_rate->text().isEmpty() &&
        !ui->lineEdit_term->text().isEmpty()) {

        double total_loan = ui->lineEdit_total_loan->text().toDouble();
        int term = ui->lineEdit_term->text().toInt();
        double interest_rate = ui->lineEdit_interest_rate->text().toDouble();

        double payment;
        double total_payment;

        if (ui->radioButton_annuity_payment->isChecked()) {
            payment = calculateAnnuityPayment(total_loan, term, interest_rate);
            total_payment = calculateAnnuityTotalPayment(total_loan, term, interest_rate);
            ui->comboBox_payment->addItem("Все месяцы = " + QString::number(payment, 'g', 15) + " $");
        } else {
            total_payment = calculateDifferentiatedTotalPayment(total_loan, term, interest_rate);
            for (int i = 1; i <= term; i++) {
                payment = calculateDifferentiatedPayment(total_loan, term, interest_rate, i);
                ui->comboBox_payment->addItem("Месяц: " + QString::number(i) + " = " + QString::number(payment, 'g', 15) + " $");
            }
        }
        double overpayment = calculateLoanOverpayment(total_loan, total_payment);
        ui->label_total_payment->setText("Общая сумма платежа: " + QString::number(total_payment, 'g', 15) + " $");
        ui->label_overpayment->setText("Переплата: " + QString::number(overpayment, 'g', 15) + " $");
    }
}

