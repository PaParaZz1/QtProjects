#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "hardware_interface.hpp"
#include "sensorreader.h"
#include "camera.h"
#include <QMainWindow>
#include <QTimer>

namespace Ui {
class MainWindow;
}
class camera;

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
    camera *m_camera;
    bool m_is_start;
    QString m_save_path;
    int m_capture_gap;
    int m_capture_count;

    SensorReader* m_sensor_reader;
    ElectricMachine *m_machine1;
    ElectricMachine *m_machine2;
    void initMachineSlider();
    void destroyMachineSlider();
    void initTimer();
    void destroyTimer();
    void initSupplySwitch();
    void destroySupplySwitch();
    void initMachineReader();
    void destroyMachineReader();
    void initCaptureGap();
    void destroyCaptureGap();
    QString getSensorData();
signals:
    void sensorValueChanged();
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
    void updateSensorValueShow();
    void onCapture();
    void cameImageCaptured(const int id, QImage image);
    void onSave();
    void onOpenImageDir();
    void updateCaptureGap();
};

#endif // MAINWINDOW_H
