#include "depositcalc.h"
#include "ui_depositcalc.h"

depositcalc::depositcalc(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::depositcalc)
{
    ui->setupUi(this);

    connect(ui->pushButton_calculate, SIGNAL(clicked()), this,
            SLOT(calculateDeposit_values()));
    connect(ui->pushButton_add_change, SIGNAL(clicked()), this,
            SLOT(addChange()));
    ui->comboBox_payment_frequency->addItem("once a month");
    ui->comboBox_payment_frequency->addItem("in the end of term");
    ui->comboBox_payment_frequency->addItem("every day");
    ui->comboBox_payment_frequency->addItem("once a year");
    list_changes = QList<change>();

}

depositcalc::~depositcalc()
{
    delete ui;
}

void depositcalc::calculateDepositValues() {
    if (!ui->lineEdit_deposit_amount->text().isEmpty() &&
        !ui->lineEdit_term->text().isEmpty() &&
        !ui->lineEdit_interest_rate->text().isEmpty() &&
        !ui->lineEdit_tax_rate->text().isEmpty()) {
        double deposit_amount = ui->lineEdit_deposit_amount->text().toDouble();
        int term = ui->lineEdit_term->text().toInt();
        double interest_rate = ui->lineEdit_interest_rate->text().toDouble();
        double tax_rate = ui->lineEdit_tax_rate->text().toDouble();
        int interest_capitalization =
                ui->checkBox_interest_capitalization->isChecked();
        int day_start = ui->dateEdit_start_deposit->date().day();
        int month_start = ui->dateEdit_start_deposit->date().month();
        int year_start = ui->dateEdit_start_deposit->date().year();
        int payments_frequency = ui->comboBox_payment_frequency->currentIndex();

        double profit, taxes, res_amount;
        change arr_changes[list_changes.length()];
        for (int i = 0; i < list_changes.length(); i++) {
            arr_changes[i] = list_changes[i];
        }
        calculateDeposit(deposit_amount, term, interest_rate, tax_rate,
                          payments_frequency, interest_capitalization, arr_changes,
                          list_changes.length(), year_start, month_start, day_start,
                          &profit, &taxes, &res_amount);
        ui->comboBox_changes->clear();
        list_changes.clear();
        ui->label_profit->setText("Profit: " + QString::number(profit, 'g', 15) +
                                  " $");
        ui->label_deposit_amount_result->setText(
                "Deposit amount in the end of the term: " +
                QString::number(res_amount, 'g', 15) + " $");
        ui->label_taxes->setText("Taxes: " + QString::number(taxes, 'g', 15) +
                                 " $");
    }
}

void depositcalc::addChange() {
    if (!ui->lineEdit_change_amount->text().isEmpty()) {
        int date_change = ui->dateEdit_date_change->date().day();
        int month_change = ui->dateEdit_date_change->date().month();
        int year_change = ui->dateEdit_date_change->date().year();
        double change_amount = ui->lineEdit_change_amount->text().toDouble();
        list_changes.append(
                change{change_amount, {date_change, month_change, year_change}});
        ui->dateEdit_date_change->clear();
        ui->lineEdit_change_amount->clear();
        ui->comboBox_changes->addItem(ui->dateEdit_date_change->date().toString() +
                                      ": " +
                                      QString::number(change_amount, 'g', 15));
    }
}
