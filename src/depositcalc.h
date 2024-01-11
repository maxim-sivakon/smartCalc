#ifndef DEPOSITCALC_H
#define DEPOSITCALC_H

#include <QList>
#include <QWidget>

extern "C" {
#include "lib/depositCalcLib.h"
}

namespace Ui {
class depositcalc;
}

class depositcalc : public QWidget {
  Q_OBJECT

 public:
  explicit depositcalc(QWidget *parent = nullptr);
  ~depositcalc();

 private slots:
  void calculateDepositValues();
  void addChange();

 private:
  Ui::depositcalc *ui;
  QList<change> list_changes;
};

#endif  // DEPOSITCALC_H
