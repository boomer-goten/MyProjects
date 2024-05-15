QT       += core gui svg multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

LIBS += -L/usr/local/lib -losmscout -losmscout_map
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ../../../libosmscout/libosmscout-map-qt/src/osmscoutmapqt/MapPainterQt.cpp \
    ../../../libosmscout/libosmscout-map-qt/src/osmscoutmapqt/SymbolRendererQt.cpp \
    implementation.cpp \
    main.cpp \
    mainwindow.cpp \
    paint.cpp \
    router.cpp

HEADERS += \
    ../../../../../usr/local/include/osmscoutmapqt/MapPainterQt.h \
    ../../../../../usr/local/include/osmscoutmapqt/SymbolRendererQt.h \
    Drawer.h \
    StyleWidgetTab.h \
    mainwindow.h \
    paint.h \
    routeStrategy.h \
    router.h \
    structNodePath.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
