#ifndef SMARTCALC_H
#define SMARTCALC_H

#include <QMainWindow>

extern "C" {
    #include "lib/polishNotation.h"
    #include "lib/stack.h"
}

QT_BEGIN_NAMESPACE
namespace Ui {
class smartCalc;
}
QT_END_NAMESPACE

class smartCalc : public QMainWindow
{
    Q_OBJECT

public:
    smartCalc(QWidget *parent = nullptr);
    ~smartCalc();

private:
    Ui::smartCalc *ui;

private slots:
    void clickedBtnDot();
    void clickedBtnClearAll();
    void clickedBtnPi();
    void clickedBtnClearLastChar();
    void trigonometricFunctions();
    void takeSymbols();
    void equalls();

    // top menu contecst
    void closeProgram();
    void openBaseCalc();
    void openDepositCalc();
    void openCreditCalc();
};
#endif // SMARTCALC_H
