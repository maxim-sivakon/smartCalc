#ifndef GRAPHCALC_H
#define GRAPHCALC_H

#include <QDialog>

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
};

#endif // GRAPHCALC_H
