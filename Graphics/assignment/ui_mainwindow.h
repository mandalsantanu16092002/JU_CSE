/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include <my_label.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionSantanu_s_Graphics_Assignment;
    QWidget *centralWidget;
    my_label *frame;
    QLabel *mouse_movement;
    QLabel *label_3;
    QLabel *mouse_pressed;
    QLabel *label_5;
    QLabel *label_6;
    QFrame *x_axis;
    QFrame *y_axis;
    QCheckBox *show_axes;
    QPushButton *setgridbutton;
    QSpinBox *gridspinbox;
    QPushButton *resetButton;
    QPushButton *setpoint1;
    QPushButton *setpoint2;
    QPushButton *DDAline;
    QPushButton *bresenhamLine;
    QSpinBox *radiusSpinBox;
    QPushButton *midpointCircle;
    QPushButton *bresenhamCircle;
    QSpinBox *xaxisRadius;
    QSpinBox *yaxisRadius;
    QLabel *label;
    QLabel *label_2;
    QPushButton *midpointEllipse;
    QPushButton *polarCircle;
    QPushButton *polarEllipse;
    QPushButton *floodfill;
    QComboBox *fill_selector;
    QPushButton *boundaryfill;
    QPushButton *setVertex;
    QPushButton *clearVertex;
    QPushButton *scanlinefill;
    QSpinBox *xtranslate;
    QLabel *label_4;
    QSpinBox *ytranslate;
    QLabel *label_7;
    QPushButton *translation;
    QLabel *label_8;
    QLabel *label_9;
    QPushButton *scaling;
    QLabel *label_10;
    QLabel *label_11;
    QPushButton *shearing;
    QLabel *label_12;
    QPushButton *shearing_2;
    QPushButton *reflection;
    QCheckBox *reflectionaxis;
    QCheckBox *reflectxaxis;
    QCheckBox *reflectyaxis;
    QCheckBox *reflectorigin;
    QLabel *label_13;
    QLabel *label_14;
    QPushButton *setCorner1;
    QPushButton *setCorner2;
    QPushButton *lineclipping;
    QPushButton *drawDDALineByStoringPoints;
    QPushButton *polygonclipping;
    QDoubleSpinBox *anglespinbox;
    QDoubleSpinBox *xshear;
    QDoubleSpinBox *yscale;
    QDoubleSpinBox *xscale;
    QDoubleSpinBox *yshear;
    QMenuBar *menuBar;
    QMenu *menuSantanu_s_Graphics_Assignment;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1274, 889);
        actionSantanu_s_Graphics_Assignment = new QAction(MainWindow);
        actionSantanu_s_Graphics_Assignment->setObjectName(QString::fromUtf8("actionSantanu_s_Graphics_Assignment"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        frame = new my_label(centralWidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(0, 0, 451, 451));
        frame->setMouseTracking(true);
        frame->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
        frame->setFrameShape(QFrame::Box);
        mouse_movement = new QLabel(centralWidget);
        mouse_movement->setObjectName(QString::fromUtf8("mouse_movement"));
        mouse_movement->setGeometry(QRect(680, 40, 111, 31));
        mouse_movement->setFrameShape(QFrame::Panel);
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(660, 10, 151, 20));
        mouse_pressed = new QLabel(centralWidget);
        mouse_pressed->setObjectName(QString::fromUtf8("mouse_pressed"));
        mouse_pressed->setGeometry(QRect(810, 40, 111, 31));
        mouse_pressed->setFrameShape(QFrame::Panel);
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(820, 10, 121, 20));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(180, 460, 81, 20));
        x_axis = new QFrame(centralWidget);
        x_axis->setObjectName(QString::fromUtf8("x_axis"));
        x_axis->setGeometry(QRect(0, 225, 450, 2));
        x_axis->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 85, 255);"));
        x_axis->setFrameShape(QFrame::HLine);
        x_axis->setFrameShadow(QFrame::Sunken);
        y_axis = new QFrame(centralWidget);
        y_axis->setObjectName(QString::fromUtf8("y_axis"));
        y_axis->setGeometry(QRect(220, 0, 2, 450));
        y_axis->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(85, 255, 255);"));
        y_axis->setFrameShape(QFrame::VLine);
        y_axis->setFrameShadow(QFrame::Sunken);
        show_axes = new QCheckBox(centralWidget);
        show_axes->setObjectName(QString::fromUtf8("show_axes"));
        show_axes->setGeometry(QRect(540, 10, 101, 21));
        setgridbutton = new QPushButton(centralWidget);
        setgridbutton->setObjectName(QString::fromUtf8("setgridbutton"));
        setgridbutton->setGeometry(QRect(650, 90, 81, 31));
        gridspinbox = new QSpinBox(centralWidget);
        gridspinbox->setObjectName(QString::fromUtf8("gridspinbox"));
        gridspinbox->setGeometry(QRect(550, 90, 71, 31));
        resetButton = new QPushButton(centralWidget);
        resetButton->setObjectName(QString::fromUtf8("resetButton"));
        resetButton->setGeometry(QRect(290, 490, 231, 25));
        setpoint1 = new QPushButton(centralWidget);
        setpoint1->setObjectName(QString::fromUtf8("setpoint1"));
        setpoint1->setGeometry(QRect(550, 130, 89, 25));
        setpoint2 = new QPushButton(centralWidget);
        setpoint2->setObjectName(QString::fromUtf8("setpoint2"));
        setpoint2->setGeometry(QRect(650, 130, 89, 25));
        DDAline = new QPushButton(centralWidget);
        DDAline->setObjectName(QString::fromUtf8("DDAline"));
        DDAline->setGeometry(QRect(550, 170, 89, 31));
        bresenhamLine = new QPushButton(centralWidget);
        bresenhamLine->setObjectName(QString::fromUtf8("bresenhamLine"));
        bresenhamLine->setGeometry(QRect(650, 170, 121, 31));
        radiusSpinBox = new QSpinBox(centralWidget);
        radiusSpinBox->setObjectName(QString::fromUtf8("radiusSpinBox"));
        radiusSpinBox->setGeometry(QRect(550, 210, 91, 31));
        midpointCircle = new QPushButton(centralWidget);
        midpointCircle->setObjectName(QString::fromUtf8("midpointCircle"));
        midpointCircle->setGeometry(QRect(650, 210, 121, 31));
        bresenhamCircle = new QPushButton(centralWidget);
        bresenhamCircle->setObjectName(QString::fromUtf8("bresenhamCircle"));
        bresenhamCircle->setGeometry(QRect(790, 210, 131, 31));
        xaxisRadius = new QSpinBox(centralWidget);
        xaxisRadius->setObjectName(QString::fromUtf8("xaxisRadius"));
        xaxisRadius->setGeometry(QRect(550, 250, 91, 31));
        yaxisRadius = new QSpinBox(centralWidget);
        yaxisRadius->setObjectName(QString::fromUtf8("yaxisRadius"));
        yaxisRadius->setGeometry(QRect(650, 250, 91, 31));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(550, 290, 91, 17));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(650, 290, 91, 17));
        midpointEllipse = new QPushButton(centralWidget);
        midpointEllipse->setObjectName(QString::fromUtf8("midpointEllipse"));
        midpointEllipse->setGeometry(QRect(770, 250, 121, 31));
        polarCircle = new QPushButton(centralWidget);
        polarCircle->setObjectName(QString::fromUtf8("polarCircle"));
        polarCircle->setGeometry(QRect(940, 210, 121, 31));
        polarEllipse = new QPushButton(centralWidget);
        polarEllipse->setObjectName(QString::fromUtf8("polarEllipse"));
        polarEllipse->setGeometry(QRect(910, 250, 121, 31));
        floodfill = new QPushButton(centralWidget);
        floodfill->setObjectName(QString::fromUtf8("floodfill"));
        floodfill->setGeometry(QRect(720, 320, 121, 31));
        fill_selector = new QComboBox(centralWidget);
        fill_selector->setObjectName(QString::fromUtf8("fill_selector"));
        fill_selector->setGeometry(QRect(550, 320, 151, 25));
        boundaryfill = new QPushButton(centralWidget);
        boundaryfill->setObjectName(QString::fromUtf8("boundaryfill"));
        boundaryfill->setGeometry(QRect(870, 320, 121, 31));
        setVertex = new QPushButton(centralWidget);
        setVertex->setObjectName(QString::fromUtf8("setVertex"));
        setVertex->setGeometry(QRect(550, 360, 121, 31));
        clearVertex = new QPushButton(centralWidget);
        clearVertex->setObjectName(QString::fromUtf8("clearVertex"));
        clearVertex->setGeometry(QRect(690, 360, 121, 31));
        scanlinefill = new QPushButton(centralWidget);
        scanlinefill->setObjectName(QString::fromUtf8("scanlinefill"));
        scanlinefill->setGeometry(QRect(830, 360, 121, 31));
        xtranslate = new QSpinBox(centralWidget);
        xtranslate->setObjectName(QString::fromUtf8("xtranslate"));
        xtranslate->setGeometry(QRect(550, 400, 71, 31));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(640, 410, 91, 17));
        ytranslate = new QSpinBox(centralWidget);
        ytranslate->setObjectName(QString::fromUtf8("ytranslate"));
        ytranslate->setGeometry(QRect(740, 400, 71, 31));
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(840, 410, 91, 17));
        translation = new QPushButton(centralWidget);
        translation->setObjectName(QString::fromUtf8("translation"));
        translation->setGeometry(QRect(970, 400, 121, 31));
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(640, 450, 91, 17));
        label_9 = new QLabel(centralWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(840, 450, 91, 17));
        scaling = new QPushButton(centralWidget);
        scaling->setObjectName(QString::fromUtf8("scaling"));
        scaling->setGeometry(QRect(970, 440, 121, 31));
        label_10 = new QLabel(centralWidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(640, 500, 91, 17));
        label_11 = new QLabel(centralWidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(840, 500, 91, 17));
        shearing = new QPushButton(centralWidget);
        shearing->setObjectName(QString::fromUtf8("shearing"));
        shearing->setGeometry(QRect(970, 490, 121, 31));
        label_12 = new QLabel(centralWidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(640, 540, 121, 17));
        shearing_2 = new QPushButton(centralWidget);
        shearing_2->setObjectName(QString::fromUtf8("shearing_2"));
        shearing_2->setGeometry(QRect(780, 540, 121, 31));
        reflection = new QPushButton(centralWidget);
        reflection->setObjectName(QString::fromUtf8("reflection"));
        reflection->setGeometry(QRect(1140, 590, 121, 31));
        reflectionaxis = new QCheckBox(centralWidget);
        reflectionaxis->setObjectName(QString::fromUtf8("reflectionaxis"));
        reflectionaxis->setGeometry(QRect(550, 590, 121, 21));
        reflectxaxis = new QCheckBox(centralWidget);
        reflectxaxis->setObjectName(QString::fromUtf8("reflectxaxis"));
        reflectxaxis->setGeometry(QRect(690, 590, 131, 21));
        reflectyaxis = new QCheckBox(centralWidget);
        reflectyaxis->setObjectName(QString::fromUtf8("reflectyaxis"));
        reflectyaxis->setGeometry(QRect(840, 590, 131, 21));
        reflectorigin = new QCheckBox(centralWidget);
        reflectorigin->setObjectName(QString::fromUtf8("reflectorigin"));
        reflectorigin->setGeometry(QRect(990, 590, 131, 21));
        label_13 = new QLabel(centralWidget);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(40, 520, 91, 17));
        label_14 = new QLabel(centralWidget);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(190, 520, 91, 21));
        setCorner1 = new QPushButton(centralWidget);
        setCorner1->setObjectName(QString::fromUtf8("setCorner1"));
        setCorner1->setGeometry(QRect(10, 540, 121, 31));
        setCorner2 = new QPushButton(centralWidget);
        setCorner2->setObjectName(QString::fromUtf8("setCorner2"));
        setCorner2->setGeometry(QRect(170, 540, 121, 31));
        lineclipping = new QPushButton(centralWidget);
        lineclipping->setObjectName(QString::fromUtf8("lineclipping"));
        lineclipping->setGeometry(QRect(330, 540, 121, 31));
        drawDDALineByStoringPoints = new QPushButton(centralWidget);
        drawDDALineByStoringPoints->setObjectName(QString::fromUtf8("drawDDALineByStoringPoints"));
        drawDDALineByStoringPoints->setGeometry(QRect(130, 580, 201, 31));
        polygonclipping = new QPushButton(centralWidget);
        polygonclipping->setObjectName(QString::fromUtf8("polygonclipping"));
        polygonclipping->setGeometry(QRect(180, 620, 121, 31));
        anglespinbox = new QDoubleSpinBox(centralWidget);
        anglespinbox->setObjectName(QString::fromUtf8("anglespinbox"));
        anglespinbox->setGeometry(QRect(550, 540, 67, 29));
        xshear = new QDoubleSpinBox(centralWidget);
        xshear->setObjectName(QString::fromUtf8("xshear"));
        xshear->setGeometry(QRect(550, 490, 67, 29));
        yscale = new QDoubleSpinBox(centralWidget);
        yscale->setObjectName(QString::fromUtf8("yscale"));
        yscale->setGeometry(QRect(740, 440, 67, 29));
        xscale = new QDoubleSpinBox(centralWidget);
        xscale->setObjectName(QString::fromUtf8("xscale"));
        xscale->setGeometry(QRect(550, 440, 67, 29));
        yshear = new QDoubleSpinBox(centralWidget);
        yshear->setObjectName(QString::fromUtf8("yshear"));
        yshear->setGeometry(QRect(740, 490, 67, 29));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1274, 25));
        menuSantanu_s_Graphics_Assignment = new QMenu(menuBar);
        menuSantanu_s_Graphics_Assignment->setObjectName(QString::fromUtf8("menuSantanu_s_Graphics_Assignment"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuSantanu_s_Graphics_Assignment->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionSantanu_s_Graphics_Assignment->setText(QCoreApplication::translate("MainWindow", "Santanu's Graphics Assignment", nullptr));
        frame->setText(QString());
        mouse_movement->setText(QString());
        label_3->setText(QCoreApplication::translate("MainWindow", "    Mouse Movement", nullptr));
        mouse_pressed->setText(QString());
        label_5->setText(QCoreApplication::translate("MainWindow", "Mouse Pressed", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "(451 X 451)", nullptr));
        show_axes->setText(QCoreApplication::translate("MainWindow", "Show Axes", nullptr));
        setgridbutton->setText(QCoreApplication::translate("MainWindow", "Set Grid", nullptr));
        resetButton->setText(QCoreApplication::translate("MainWindow", "Reset", nullptr));
        setpoint1->setText(QCoreApplication::translate("MainWindow", "point1", nullptr));
        setpoint2->setText(QCoreApplication::translate("MainWindow", "point2", nullptr));
        DDAline->setText(QCoreApplication::translate("MainWindow", " DDA Line", nullptr));
        bresenhamLine->setText(QCoreApplication::translate("MainWindow", " Bresenham Line", nullptr));
        midpointCircle->setText(QCoreApplication::translate("MainWindow", "midpoint circle", nullptr));
        bresenhamCircle->setText(QCoreApplication::translate("MainWindow", "bresenham circle", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "X axis radius", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Y axis radius", nullptr));
        midpointEllipse->setText(QCoreApplication::translate("MainWindow", "midpoint ellipse", nullptr));
        polarCircle->setText(QCoreApplication::translate("MainWindow", "polar circle", nullptr));
        polarEllipse->setText(QCoreApplication::translate("MainWindow", "polar ellipse", nullptr));
        floodfill->setText(QCoreApplication::translate("MainWindow", "flood fill ", nullptr));
        boundaryfill->setText(QCoreApplication::translate("MainWindow", "boundary fill", nullptr));
        setVertex->setText(QCoreApplication::translate("MainWindow", "set vertex", nullptr));
        clearVertex->setText(QCoreApplication::translate("MainWindow", "clear vertex", nullptr));
        scanlinefill->setText(QCoreApplication::translate("MainWindow", "scan line", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "x translate", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "y translate", nullptr));
        translation->setText(QCoreApplication::translate("MainWindow", "Translate", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "x scale", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "y scale", nullptr));
        scaling->setText(QCoreApplication::translate("MainWindow", "scale", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "x shear", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "y shear", nullptr));
        shearing->setText(QCoreApplication::translate("MainWindow", "shear", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "angle spin value", nullptr));
        shearing_2->setText(QCoreApplication::translate("MainWindow", "rotation", nullptr));
        reflection->setText(QCoreApplication::translate("MainWindow", "reflection", nullptr));
        reflectionaxis->setText(QCoreApplication::translate("MainWindow", "reflection axis", nullptr));
        reflectxaxis->setText(QCoreApplication::translate("MainWindow", "reflection x axis", nullptr));
        reflectyaxis->setText(QCoreApplication::translate("MainWindow", "reflection y axis", nullptr));
        reflectorigin->setText(QCoreApplication::translate("MainWindow", "reflection origin", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "top left", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "bottom right", nullptr));
        setCorner1->setText(QCoreApplication::translate("MainWindow", "set corner 1", nullptr));
        setCorner2->setText(QCoreApplication::translate("MainWindow", "set corner 2", nullptr));
        lineclipping->setText(QCoreApplication::translate("MainWindow", "line clipping", nullptr));
        drawDDALineByStoringPoints->setText(QCoreApplication::translate("MainWindow", "DDA Line storing points", nullptr));
        polygonclipping->setText(QCoreApplication::translate("MainWindow", "Polygon clipping", nullptr));
        menuSantanu_s_Graphics_Assignment->setTitle(QCoreApplication::translate("MainWindow", "Santanu's Graphics Assignment", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
