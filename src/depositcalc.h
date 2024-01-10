#ifndef DEPOSITCALC_H
#define DEPOSITCALC_H

#include <QWidget>

namespace Ui {
class depositcalc;
}

class depositcalc : public QWidget
{
    Q_OBJECT

public:
    explicit depositcalc(QWidget *parent = nullptr);
    ~depositcalc();

private:
    Ui::depositcalc *ui;
};

#endif // DEPOSITCALC_H
