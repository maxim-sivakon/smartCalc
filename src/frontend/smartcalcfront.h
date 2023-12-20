#ifndef SMARTCALCFRONT_H
#define SMARTCALCFRONT_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class smartCalcFront;
}
QT_END_NAMESPACE

class smartCalcFront : public QMainWindow
{
    Q_OBJECT

public:
    smartCalcFront(QWidget *parent = nullptr);
    ~smartCalcFront();

private:
    Ui::smartCalcFront *ui;
};
#endif // SMARTCALCFRONT_H
