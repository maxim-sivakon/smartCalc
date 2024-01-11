QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

CONFIG += c++17

VERSION = 1.0.0.1
QMAKE_TARGET_PRODUCT		=  наименование товара
QMAKE_TARGET_COMPANY		=  Компания
QMAKE_TARGET_DESCRIPTION	=  Описание файла
QMAKE_TARGET_COPYRIGHT		=  Авторские права

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    creditcalc.cpp \
    depositcalc.cpp \
    graphcalc.cpp \
    lib/creditCalcLib.c \
    lib/depositCalcLib.c \
    lib/polishNotation.c \
    lib/qcustomplot.cpp \
    lib/stack.c \
    main.cpp \
    smartcalc.cpp

HEADERS += \
    creditcalc.h \
    depositcalc.h \
    graphcalc.h \
    lib/creditCalcLib.h \
    lib/depositCalcLib.h \
    lib/polishNotation.h \
    lib/qcustomplot.h \
    lib/stack.h \
    smartcalc.h

FORMS += \
    creditcalc.ui \
    depositcalc.ui \
    graphcalc.ui \
    smartcalc.ui

TRANSLATIONS += \
    smartCalc_ru_RU.ts
CONFIG += lrelease
CONFIG += embed_translations

ICON = calculator_icon.icns

RESOURCES += \
    calculator_icon.qrc

RC_ICONS += calculator_icon.rc
macx:ICON = $${PWD}/calculator_icon.icns

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
