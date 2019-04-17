/********************************************************************************
** Form generated from reading UI file 'mainwindow_new.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_NEW_H
#define UI_MAINWINDOW_NEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QSlider *machine1_slider;
    QSlider *machine2_slider;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QFrame *line;
    QFrame *line_2;
    QFrame *line_3;
    QLineEdit *machine1_line_edit;
    QLineEdit *machine2_line_edit;
    QLabel *label_6;
    QTimeEdit *time_show;
    QPushButton *button_begin;
    QPushButton *button_stop;
    QSpinBox *fluid_threshold;
    QMenuBar *menuBar;
    QMenu *menuHostComputer;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(653, 466);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        machine1_slider = new QSlider(centralWidget);
        machine1_slider->setObjectName(QStringLiteral("machine1_slider"));
        machine1_slider->setGeometry(QRect(410, 240, 22, 160));
        machine1_slider->setOrientation(Qt::Vertical);
        machine2_slider = new QSlider(centralWidget);
        machine2_slider->setObjectName(QStringLiteral("machine2_slider"));
        machine2_slider->setGeometry(QRect(520, 240, 22, 160));
        machine2_slider->setOrientation(Qt::Vertical);
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(440, 250, 31, 16));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(550, 250, 41, 16));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 140, 81, 16));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(420, 180, 131, 16));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(430, 30, 71, 16));
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(430, 50, 71, 16));
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(430, 70, 101, 16));
        label_9 = new QLabel(centralWidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(430, 110, 81, 16));
        label_10 = new QLabel(centralWidget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(430, 150, 101, 16));
        label_11 = new QLabel(centralWidget);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(430, 130, 81, 16));
        line = new QFrame(centralWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(390, 0, 20, 411));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        line_2 = new QFrame(centralWidget);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setGeometry(QRect(400, 220, 251, 16));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        line_3 = new QFrame(centralWidget);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setGeometry(QRect(0, 130, 401, 16));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);
        machine1_line_edit = new QLineEdit(centralWidget);
        machine1_line_edit->setObjectName(QStringLiteral("machine1_line_edit"));
        machine1_line_edit->setGeometry(QRect(440, 370, 61, 21));
        machine2_line_edit = new QLineEdit(centralWidget);
        machine2_line_edit->setObjectName(QStringLiteral("machine2_line_edit"));
        machine2_line_edit->setGeometry(QRect(550, 370, 61, 21));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(10, 100, 101, 16));
        time_show = new QTimeEdit(centralWidget);
        time_show->setObjectName(QStringLiteral("time_show"));
        time_show->setGeometry(QRect(117, 91, 131, 31));
        time_show->setInputMethodHints(Qt::ImhNone);
        time_show->setReadOnly(true);
        button_begin = new QPushButton(centralWidget);
        button_begin->setObjectName(QStringLiteral("button_begin"));
        button_begin->setGeometry(QRect(260, 30, 114, 32));
        button_stop = new QPushButton(centralWidget);
        button_stop->setObjectName(QStringLiteral("button_stop"));
        button_stop->setGeometry(QRect(260, 90, 114, 32));
        fluid_threshold = new QSpinBox(centralWidget);
        fluid_threshold->setObjectName(QStringLiteral("fluid_threshold"));
        fluid_threshold->setGeometry(QRect(550, 170, 71, 31));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 653, 22));
        menuHostComputer = new QMenu(menuBar);
        menuHostComputer->setObjectName(QStringLiteral("menuHostComputer"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuHostComputer->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QApplication::translate("MainWindow", "\347\224\265\346\234\2721", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "\347\224\265\346\234\2722", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "\345\237\271\345\205\273\350\243\205\347\275\256\345\247\277\346\200\201", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "\350\207\252\345\212\250\344\270\212\346\266\262\347\231\276\345\210\206\346\257\224\351\230\210\345\200\274", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "\346\263\250\345\260\204\346\263\2651\346\265\201\351\200\237", nullptr));
        label_7->setText(QApplication::translate("MainWindow", "\346\263\250\345\260\204\346\263\2651\346\265\201\351\207\217", nullptr));
        label_8->setText(QApplication::translate("MainWindow", "\346\263\250\345\260\204\346\263\2651\345\211\251\344\275\231\346\266\262\351\207\217", nullptr));
        label_9->setText(QApplication::translate("MainWindow", "\346\263\250\345\260\204\346\263\2652\346\265\201\351\200\237", nullptr));
        label_10->setText(QApplication::translate("MainWindow", "\346\263\250\345\260\204\346\263\2652\345\211\251\344\275\231\346\266\262\351\207\217", nullptr));
        label_11->setText(QApplication::translate("MainWindow", "\346\263\250\345\260\204\346\263\2652\346\265\201\351\207\217", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "\347\263\273\347\273\237\345\267\262\350\277\220\350\241\214\346\227\266\351\227\264", nullptr));
        time_show->setDisplayFormat(QApplication::translate("MainWindow", "HH:mm:ss", nullptr));
        button_begin->setText(QApplication::translate("MainWindow", "\345\274\200\345\247\213", nullptr));
        button_stop->setText(QApplication::translate("MainWindow", "\347\273\223\346\235\237", nullptr));
        menuHostComputer->setTitle(QApplication::translate("MainWindow", "HostComputer", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_NEW_H
