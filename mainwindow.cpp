#include "mainwindow.h"
#include "ui_mainwindow_new.h"
#include "camera.h"
#include <QHBoxLayout>
#include <QString>
#include <QDesktopServices>
#include <QDir>
#include <iostream>

using std::cout;
using std::endl;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    m_is_start = false;
    ui->setupUi(this);
    m_sensor_reader = new SensorReader();
    m_camera = new camera;
    // init
    initMachineSlider();
    initTimer();
    initSupplySwitch();
    initMachineReader();

    // hardware
    m_machine1 = new ElectricMachine(0.0, true);
    m_machine2 = new ElectricMachine(0.0, false);

    //control
    connect(ui->button_begin, SIGNAL(pressed()), this, SLOT(onButtonBegin()));
    connect(ui->button_stop, SIGNAL(pressed()), this, SLOT(onButtonStop()));

    //camera
    m_save_path = QString::fromStdString("./");
    m_capture_gap = 2;
    m_capture_count = 0;
    ui->snapshot->setScaledContents(true);
    ui->view_finder_layout->addWidget(m_camera->m_view_finder);
    connect(ui->capture_button, SIGNAL(clicked()), this, SLOT(onCapture()));
    connect(m_camera->m_image_capture, SIGNAL(imageCaptured(int, QImage)), this, SLOT(cameImageCaptured(int,QImage)));
    connect(ui->open_album, SIGNAL(clicked()), this, SLOT(onOpenImageDir()));
    initCaptureGap();

    //pump
    initPumpControl();
}

MainWindow::~MainWindow()
{
    m_sensor_reader->quitThread();
    delete ui;
    delete m_machine1;
    destroyPumpControl();
    destroyCaptureGap();
    destroyMachineReader();
    destroySupplySwitch();
    destroyTimer();
    destroyMachineSlider();
}

void MainWindow::changeMachineSpeed1(int value) {
    m_machine1->setSpeed(value*1.0);
}

void MainWindow::changeMachineSpeed1() {
    float value = ui->machine1_line_edit->text().toFloat();
    m_machine1->setSpeed(value);
}

void MainWindow::changeMachineSpeed2(int value) {
    m_machine2->setSpeed(value*1.0);
}

void MainWindow::changeMachineSpeed2() {
    float value = ui->machine2_line_edit->text().toFloat();
    m_machine2->setSpeed(value);
}

void MainWindow::initMachineSlider() {
    float init_value = 0.0;
    QString str = QString::number(init_value);
    ui->machine1_line_edit->setText(str);
    ui->machine2_line_edit->setText(str);

    QBrush myBrush;
    QPalette palette;
    myBrush = QBrush(Qt::blue,Qt::DiagCrossPattern);
    palette.setBrush( QPalette::Text,  myBrush);
    ui->machine1_line_edit->setPalette(palette);
    ui->machine2_line_edit->setPalette(palette);

    ui->machine1_slider->setMinimum(0.0);
    ui->machine1_slider->setMaximum(100.0);
    ui->machine1_slider->setValue(init_value);
    connect(ui->machine1_slider, SIGNAL(valueChanged(int)), this, SLOT(changeMachineSpeed1(int)));
    connect(ui->machine1_line_edit, SIGNAL(editingFinished()), this, SLOT(changeMachineSpeed1()));
    connect(ui->machine1_slider, SIGNAL(valueChanged(int)), this, SLOT(setSpeedText1(int)));
    connect(ui->machine1_line_edit, SIGNAL(editingFinished()), this, SLOT(setSpeedSlider1()));

    ui->machine2_slider->setMinimum(0.0);
    ui->machine2_slider->setMaximum(100.0);
    ui->machine2_slider->setValue(init_value);
    connect(ui->machine2_slider, SIGNAL(valueChanged(int)), this, SLOT(changeMachineSpeed2(int)));
    connect(ui->machine2_line_edit, SIGNAL(editingFinished()), this, SLOT(changeMachineSpeed2()));
    connect(ui->machine2_slider, SIGNAL(valueChanged(int)), this, SLOT(setSpeedText2(int)));
    connect(ui->machine2_line_edit, SIGNAL(editingFinished()), this, SLOT(setSpeedSlider2()));
}

void MainWindow::destroyMachineSlider(){
}

void MainWindow::initTimer(){
    m_timer = new QTimer;
    m_time_record = new QTime(0, 0, 0);
    ui->time_show->setDisplayFormat("hh:mm:ss");
    QBrush myBrush;
    QPalette palette;
    myBrush = QBrush(Qt::black,Qt::DiagCrossPattern);
    palette.setBrush( QPalette::Text,  myBrush);
    ui->time_show->setPalette(palette);
    connect(m_timer, SIGNAL(timeout()), this, SLOT(updateTime()));
}

void MainWindow::destroyTimer(){
    delete m_time_record;
    delete m_timer;
}

void MainWindow::initSupplySwitch(){
    QBrush myBrush;
    QPalette palette;
    myBrush = QBrush(Qt::blue,Qt::DiagCrossPattern);
    palette.setBrush( QPalette::Text,  myBrush);
    ui->fluid_threshold->setPalette(palette);
    ui->fluid_threshold->setValue(20);
    connect(ui->fluid_threshold, SIGNAL(editingFinished()), this, SLOT(updateSupplyThreshold()));
}

void MainWindow::initCaptureGap(){
    QBrush myBrush;
    QPalette palette;
    myBrush = QBrush(Qt::blue,Qt::DiagCrossPattern);
    palette.setBrush( QPalette::Text,  myBrush);
    ui->capture_gap->setPalette(palette);
    ui->capture_gap->setText(QString::number(m_capture_gap));
    connect(ui->capture_gap, SIGNAL(editingFinished()), this, SLOT(updateCaptureGap()));
}

void MainWindow::destroyCaptureGap(){

}

void MainWindow::destroySupplySwitch(){

}

void MainWindow::initMachineReader() {
    QBrush myBrush;
    QPalette palette;
    myBrush = QBrush(Qt::blue,Qt::DiagCrossPattern);
    palette.setBrush( QPalette::Text,  myBrush);
    ui->real_state1->setPalette(palette);
    ui->real_state1->setText(QString::fromStdString(m_sensor_reader->getSensorData()));
        m_sensor_reader->start();
    connect(m_sensor_reader, SIGNAL(onSensorValueChanged()), this, SLOT(updateSensorValueShow()));

}

void MainWindow::destroyMachineReader() {

}

void MainWindow::initPumpControl() {
    m_shear_force = 0;
    m_vessel_height = 0;
    m_vessel_width = 0;
    m_fluid_viscosity = 0;
    m_density = 0;

    m_injection_radius = 0;
    m_injection_radius = 0;
}

void MainWindow::destroyPumpControl() {

}

void MainWindow::setSpeedText1(int value) {
    QString str = QString::number(value);
    ui->machine1_line_edit->setText(str);
}

void MainWindow::setSpeedSlider1() {
    QString str = ui->machine1_line_edit->text();
    ui->machine1_slider->setValue(str.toInt());
}

void MainWindow::setSpeedText2(int value) {
    QString str = QString::number(value);
    ui->machine2_line_edit->setText(str);
}

void MainWindow::setSpeedSlider2() {
    QString str = ui->machine2_line_edit->text();
    ui->machine2_slider->setValue(str.toInt());
}

void MainWindow::updateTime() {
    *m_time_record = m_time_record->addSecs(1);
    //cout<<m_time_record->currentTime().toString().toInt()<<endl;
    ui->time_show->setTime(*m_time_record);
    m_capture_count += 1;
    if (m_capture_count == m_capture_gap) {
        m_capture_count = 0;
        this->onCapture();
    }
}

void MainWindow::onButtonBegin() {
    if (!m_is_start) {
        m_is_start = true;
        m_timer->start(1000);
        m_camera->onBegin();
    }
}

void MainWindow::onButtonStop() {
    if (m_is_start) {
        m_is_start = false;
        m_timer->stop();
        m_time_record->setHMS(0, 0, 0);
        ui->time_show->setTime(*m_time_record);
        m_camera->onExit();
    }
}

void MainWindow::updateSupplyThreshold() {
    if (m_is_start) {
        int value = ui->fluid_threshold->value();
        cout<<"changed value"<<value<<endl;
    }
}


void MainWindow::updateSensorValueShow() {
    QString str = this->getSensorData();
    ui->real_state1->setText("str");
}

QString MainWindow::getSensorData() {
    return QString::fromStdString(m_sensor_reader->getSensorData());
}

void MainWindow::onCapture() {
    m_camera->onCapture();
    this->onSave();
}

void MainWindow::cameImageCaptured(const int id, QImage image) {
    ui->snapshot->setPixmap(QPixmap::fromImage(image));
}

void MainWindow::onSave() {
    const QPixmap *img = ui->snapshot->pixmap();
    if (img) {
        qint64 timestamp = QDateTime::currentDateTime().toMSecsSinceEpoch();
        QString path = m_save_path + (tr("%1").arg(timestamp)) + QString::fromStdString(".jpg");
        cout << "save path:" << path.toStdString() << endl;
        img->save(path);
    }
}

void MainWindow::onOpenImageDir() {
    //QString path=QDir::currentPath();
    cout << m_save_path.toStdString() <<endl;
    bool ret = QDesktopServices::openUrl(QUrl(m_save_path, QUrl::TolerantMode));
    cout << (ret?"nice":"fxxk")<<endl;
}

void MainWindow::updateCaptureGap() {
    int value = ui->capture_gap->text().toInt();
    m_capture_gap = value;
    cout << "update value:" << m_capture_gap << endl;
}
