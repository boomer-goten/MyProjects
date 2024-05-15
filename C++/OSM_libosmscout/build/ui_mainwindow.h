/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QTabWidget *Tab;
    QWidget *MapTab;
    QGraphicsView *graphicsView;
    QPushButton *CalculatePath;
    QComboBox *StrategyBox;
    QComboBox *VehicleBox;
    QLabel *label_5;
    QLabel *label_6;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_3;
    QLabel *label_3;
    QLabel *label;
    QLabel *total_time;
    QLabel *real_distance;
    QLabel *graph_size;
    QLabel *label_2;
    QLabel *label_4;
    QLabel *Distance;
    QLabel *labe12;
    QLabel *touch_size;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *Lat_start;
    QLabel *label_9;
    QLabel *label_15;
    QLabel *Lon_start;
    QWidget *gridLayoutWidget_3;
    QGridLayout *gridLayout_4;
    QLabel *Lat_end;
    QLabel *label_10;
    QLabel *label_12;
    QLabel *Lon_end;
    QLabel *label_7;
    QLabel *label_8;
    QCheckBox *CheckDots;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1264, 598);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(9, 0, 951, 571));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        Tab = new QTabWidget(horizontalLayoutWidget);
        Tab->setObjectName(QString::fromUtf8("Tab"));
        Tab->setTabPosition(QTabWidget::West);
        MapTab = new QWidget();
        MapTab->setObjectName(QString::fromUtf8("MapTab"));
        graphicsView = new QGraphicsView(MapTab);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(-5, -9, 931, 581));
        graphicsView->setAutoFillBackground(true);
        graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        graphicsView->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContentsOnFirstShow);
        graphicsView->setDragMode(QGraphicsView::ScrollHandDrag);
        graphicsView->setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
        graphicsView->setResizeAnchor(QGraphicsView::NoAnchor);
        graphicsView->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
        Tab->addTab(MapTab, QString());

        horizontalLayout->addWidget(Tab);

        CalculatePath = new QPushButton(centralwidget);
        CalculatePath->setObjectName(QString::fromUtf8("CalculatePath"));
        CalculatePath->setGeometry(QRect(970, 320, 289, 25));
        StrategyBox = new QComboBox(centralwidget);
        StrategyBox->addItem(QString());
        StrategyBox->addItem(QString());
        StrategyBox->addItem(QString());
        StrategyBox->addItem(QString());
        StrategyBox->addItem(QString());
        StrategyBox->addItem(QString());
        StrategyBox->setObjectName(QString::fromUtf8("StrategyBox"));
        StrategyBox->setGeometry(QRect(970, 250, 289, 25));
        VehicleBox = new QComboBox(centralwidget);
        VehicleBox->addItem(QString());
        VehicleBox->addItem(QString());
        VehicleBox->setObjectName(QString::fromUtf8("VehicleBox"));
        VehicleBox->setGeometry(QRect(970, 180, 289, 25));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(970, 150, 231, 16));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(970, 220, 221, 17));
        gridLayoutWidget_2 = new QWidget(centralwidget);
        gridLayoutWidget_2->setObjectName(QString::fromUtf8("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(970, 350, 291, 171));
        gridLayout_3 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(gridLayoutWidget_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_3, 3, 0, 1, 1);

        label = new QLabel(gridLayoutWidget_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_3->addWidget(label, 0, 0, 1, 1);

        total_time = new QLabel(gridLayoutWidget_2);
        total_time->setObjectName(QString::fromUtf8("total_time"));
        total_time->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        total_time->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(total_time, 2, 1, 1, 1);

        real_distance = new QLabel(gridLayoutWidget_2);
        real_distance->setObjectName(QString::fromUtf8("real_distance"));
        real_distance->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        real_distance->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(real_distance, 4, 1, 1, 1);

        graph_size = new QLabel(gridLayoutWidget_2);
        graph_size->setObjectName(QString::fromUtf8("graph_size"));
        graph_size->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        graph_size->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(graph_size, 0, 1, 1, 1);

        label_2 = new QLabel(gridLayoutWidget_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_2, 2, 0, 1, 1);

        label_4 = new QLabel(gridLayoutWidget_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_4, 4, 0, 1, 1);

        Distance = new QLabel(gridLayoutWidget_2);
        Distance->setObjectName(QString::fromUtf8("Distance"));
        Distance->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        Distance->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(Distance, 3, 1, 1, 1);

        labe12 = new QLabel(gridLayoutWidget_2);
        labe12->setObjectName(QString::fromUtf8("labe12"));

        gridLayout_3->addWidget(labe12, 1, 0, 1, 1);

        touch_size = new QLabel(gridLayoutWidget_2);
        touch_size->setObjectName(QString::fromUtf8("touch_size"));
        touch_size->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        touch_size->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(touch_size, 1, 1, 1, 1);

        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(970, 20, 288, 42));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        Lat_start = new QLabel(gridLayoutWidget);
        Lat_start->setObjectName(QString::fromUtf8("Lat_start"));
        Lat_start->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        Lat_start->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(Lat_start, 0, 1, 1, 1);

        label_9 = new QLabel(gridLayoutWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_9, 0, 0, 1, 1);

        label_15 = new QLabel(gridLayoutWidget);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_15, 0, 2, 1, 1);

        Lon_start = new QLabel(gridLayoutWidget);
        Lon_start->setObjectName(QString::fromUtf8("Lon_start"));
        Lon_start->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        Lon_start->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(Lon_start, 0, 3, 1, 1);

        gridLayoutWidget_3 = new QWidget(centralwidget);
        gridLayoutWidget_3->setObjectName(QString::fromUtf8("gridLayoutWidget_3"));
        gridLayoutWidget_3->setGeometry(QRect(970, 90, 288, 41));
        gridLayout_4 = new QGridLayout(gridLayoutWidget_3);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        Lat_end = new QLabel(gridLayoutWidget_3);
        Lat_end->setObjectName(QString::fromUtf8("Lat_end"));
        Lat_end->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        Lat_end->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(Lat_end, 0, 1, 1, 1);

        label_10 = new QLabel(gridLayoutWidget_3);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label_10, 0, 0, 1, 1);

        label_12 = new QLabel(gridLayoutWidget_3);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label_12, 0, 2, 1, 1);

        Lon_end = new QLabel(gridLayoutWidget_3);
        Lon_end->setObjectName(QString::fromUtf8("Lon_end"));
        Lon_end->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        Lon_end->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(Lon_end, 0, 3, 1, 1);

        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(970, 0, 271, 17));
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(970, 70, 271, 17));
        CheckDots = new QCheckBox(centralwidget);
        CheckDots->setObjectName(QString::fromUtf8("CheckDots"));
        CheckDots->setGeometry(QRect(970, 290, 281, 23));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1264, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        Tab->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        Tab->setTabText(Tab->indexOf(MapTab), QCoreApplication::translate("MainWindow", "Map", nullptr));
        CalculatePath->setText(QCoreApplication::translate("MainWindow", "\320\240\320\260\321\201\321\201\321\207\320\270\321\202\320\260\321\202\321\214 \320\277\321\203\321\202\321\214", nullptr));
        StrategyBox->setItemText(0, QCoreApplication::translate("MainWindow", "\320\220\320\273\320\263\320\276\321\200\320\270\321\202\320\274 \320\224\320\265\320\271\320\272\321\201\321\202\321\200\321\213", nullptr));
        StrategyBox->setItemText(1, QCoreApplication::translate("MainWindow", "A*", nullptr));
        StrategyBox->setItemText(2, QCoreApplication::translate("MainWindow", "\320\224\320\262\321\203\321\201\321\202\320\276\321\200\320\276\320\275\320\275\320\270\320\271 \320\260\320\273\320\263\320\276\321\200\320\270\321\202\320\274 \320\224\320\265\320\271\320\272\321\201\321\202\321\200\321\213", nullptr));
        StrategyBox->setItemText(3, QCoreApplication::translate("MainWindow", "\320\224\320\262\321\203\321\201\321\202\320\276\321\200\320\276\320\275\320\275\320\270\320\271 \320\220*", nullptr));
        StrategyBox->setItemText(4, QCoreApplication::translate("MainWindow", "\320\220\320\273\320\263\320\276\321\200\320\270\321\202\320\274 \320\221\320\265\320\273\321\214\320\274\320\260\320\275\320\260 \320\244\320\276\321\200\320\264\320\260", nullptr));
        StrategyBox->setItemText(5, QCoreApplication::translate("MainWindow", "\320\220\320\273\320\263\320\276\321\200\320\270\321\202\320\274 \320\233\320\265\320\262\320\270\321\202\320\260", nullptr));

        VehicleBox->setItemText(0, QCoreApplication::translate("MainWindow", "\320\234\320\260\321\210\320\270\320\275\320\260", nullptr));
        VehicleBox->setItemText(1, QCoreApplication::translate("MainWindow", "\320\237\320\265\321\210\320\272\320\276\320\274", nullptr));

        label_5->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\261\320\276\321\200 \321\201\321\200\320\265\320\264\321\202\321\201\320\262\320\260 \320\277\320\265\321\200\320\265\320\264\320\262\320\270\320\266\320\265\320\275\320\270\321\217", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\261\320\276\321\200 \320\260\320\273\320\263\320\276\321\200\320\270\321\202\320\274\320\260 \321\200\320\260\321\201\321\207\320\265\321\202\320\260 \320\277\321\203\321\202\320\270", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\320\240\320\260\321\201\321\201\321\202\320\276\321\217\320\275\320\270\320\265 \320\274\320\265\320\266\320\264\321\203 \321\202\320\276\321\207\320\272\320\260\320\274\320\270", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \321\203\320\267\320\273\320\276\320\262 \320\262 \320\263\321\200\320\260\321\204\320\265", nullptr));
        total_time->setText(QString());
        real_distance->setText(QString());
        graph_size->setText(QString());
        label_2->setText(QCoreApplication::translate("MainWindow", "\320\236\320\261\321\211\320\265\320\265 \320\262\321\200\320\265\320\274\321\217 \320\262\321\213\320\277\320\276\320\273\320\275\320\265\320\275\320\270\321\217", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\320\244\320\260\320\272\321\202\320\270\321\207\320\265\321\201\320\272\320\276\320\265 \321\200\320\260\321\201\321\201\321\202\320\276\321\217\320\275\320\270\320\265", nullptr));
        Distance->setText(QString());
        labe12->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\321\202\321\200\320\276\320\275\321\203\321\202\320\276 \321\203\320\267\320\273\320\276\320\262 \320\262 \320\263\321\200\320\260\321\204\320\265", nullptr));
        touch_size->setText(QString());
        Lat_start->setText(QString());
        label_9->setText(QCoreApplication::translate("MainWindow", "Lat", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "Lon", nullptr));
        Lon_start->setText(QString());
        Lat_end->setText(QString());
        label_10->setText(QCoreApplication::translate("MainWindow", "Lat", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "Lon", nullptr));
        Lon_end->setText(QString());
        label_7->setText(QCoreApplication::translate("MainWindow", "\320\232\320\276\320\276\321\200\320\264\320\270\320\275\320\260\321\202\321\213 \320\275\320\260\321\207\320\260\320\273\320\260 \320\277\321\203\321\202\320\270", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "\320\232\320\276\320\276\321\200\320\264\320\270\320\275\320\260\321\202\321\213 \320\272\320\276\320\275\321\206\320\260 \320\277\321\203\321\202\320\270", nullptr));
        CheckDots->setText(QCoreApplication::translate("MainWindow", "\320\240\320\270\321\201\320\276\320\262\320\260\321\202\321\214 \321\202\320\276\321\207\320\272\320\270 \320\263\321\200\320\260\321\204\320\276\320\262 \320\275\320\260 \320\272\320\260\321\200\321\202\320\265", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
