#ifndef GRAPHCALC_H
#define GRAPHCALC_H

#include <QDialog>
#include <QIntValidator>

extern "C" {
#include "lib/polishNotation.h"
#include "lib/stack.h"
}

namespace Ui {
class graphcalc;
}

class graphcalc : public QDialog
{
    Q_OBJECT

public:
    explicit graphcalc(QWidget *parent = nullptr);
    ~graphcalc();

private:
    Ui::graphcalc *ui;

private slots:
    void drawGraph();
    void setValidators();
    double getY(QString expression, double X);
};

#endif // GRAPHCALC_H
