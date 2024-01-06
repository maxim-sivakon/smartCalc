#ifndef GRAPHCALC_H
#define GRAPHCALC_H

#include <QDialog>
#include <QIntValidator>

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
};

#endif // GRAPHCALC_H
