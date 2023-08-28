QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

CONFIG += c++17
QMAKE_CXXFLAGS += -Wall -Wextra -g -std=c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

ICON = \
    icons/Calculator.ico

SOURCES += \
    BankModelOperations.cc \
    CalculatorModelOperations.cc \
    CreditWindow.cc \
    DepositWindow.cc \
    Graph.cc \
    MainWindowView.cc \
    QCustomPlot/qcustomplot.cpp \
    main.cc \


HEADERS += \
    QCustomPlot/qcustomplot.h \
    headers/BankModel.h \
    headers/CalculatorModel.h \
    headers/Controller.h \
    headers/CreditWindow.h \
    headers/DepositWindow.h \
    headers/Graph.h \
    headers/MainWindowView.h \

FORMS += \
    ui/CreditWindow.ui \
    ui/DepositWindow.ui \
    ui/Graph.ui \
    ui/MainWindowView.ui


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    icons/Calculator.ico \

RESOURCES += \
    icon.qrc
