#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "hardware_interface.hpp"
#include <QMainWindow>
#include <QTimer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QTimer *m_timer;
    QTime *m_time_record;
    bool m_is_start;

    ElectricMachine *m_machine1;
    ElectricMachine *m_machine2;
    void initMachineSlider();
    void destroyMachineSlider();
    void initTimer();
    void destroyTimer();
    void initSupplySwitch();
    void destroySupplySwitch();
private slots:
    void changeMachineSpeed1(int value);
    void changeMachineSpeed2(int value);
    void changeMachineSpeed1();
    void changeMachineSpeed2();
    void setSpeedText1(int);
    void setSpeedSlider1();
    void setSpeedText2(int);
    void setSpeedSlider2();
    void updateTime();
    void onButtonBegin();
    void onButtonStop();
    void updateSupplyThreshold();
};

#endif // MAINWINDOW_H
