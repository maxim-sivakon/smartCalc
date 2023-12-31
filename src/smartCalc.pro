QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    graphcalc.cpp \
    lib/polishNotation.c \
    lib/qcustomplot.cpp \
    lib/stack.c \
    main.cpp \
    smartcalc.cpp

HEADERS += \
    graphcalc.h \
    lib/polishNotation.h \
    lib/qcustomplot.h \
    lib/stack.h \
    smartcalc.h

FORMS += \
    graphcalc.ui \
    smartcalc.ui

TRANSLATIONS += \
    smartCalc_ru_RU.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    icon.qrc
