#ifndef CREDITCALC_H
#define CREDITCALC_H

#include <QWidget>

namespace Ui {
class creditcalc;
}

class creditcalc : public QWidget
{
    Q_OBJECT

public:
    explicit creditcalc(QWidget *parent = nullptr);
    ~creditcalc();

private:
    Ui::creditcalc *ui;
};

#endif // CREDITCALC_H
