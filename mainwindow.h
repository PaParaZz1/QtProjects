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

    float m_shear_force;
    float m_vessel_height;
    int m_vessel_width;
    float m_fluid_viscosity;
    float m_density;
    float m_input_volume;
    int m_injection_radius;
    int m_injection_volume;

    float m_flow;

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
    void initPumpControl();
    void destroyPumpControl();

    QString getSensorData();
    float calFlow() const;
    void updateFlow();
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
    void setShearForce();
    void setVesselHeight();
    void setVesselWidth();
    void setFluidViscosity();
    void setDensity();
    void setInputVolume();
    void setInjectionRadius();
    void setInjectionVolume();
};

#endif // MAINWINDOW_H
