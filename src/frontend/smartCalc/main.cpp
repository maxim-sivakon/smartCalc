#include "smartcalc.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "smartCalc_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.setWindowIcon(QIcon(":/new/prefix1/calculator.png"));
            a.installTranslator(&translator);
            break;
        }
    }
    smartCalc w;
    w.show();
    return a.exec();
}
