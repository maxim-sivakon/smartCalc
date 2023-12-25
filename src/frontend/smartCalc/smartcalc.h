#ifndef SMARTCALC_H
#define SMARTCALC_H

#include <QMainWindow>

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
};
#endif // SMARTCALC_H
