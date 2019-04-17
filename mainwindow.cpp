#include "mainwindow.h"
#include "ui_mainwindow_new.h"
#include <QHBoxLayout>
#include <QString>
#include <iostream>

using std::cout;
using std::endl;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    m_is_start = false;
    ui->setupUi(this);
    // init
    initMachineSlider();
    initTimer();
    initSupplySwitch();
    // hardware
    m_machine1 = new ElectricMachine(0.0);
    m_machine2 = new ElectricMachine(0.0);

    //control
    connect(ui->button_begin, SIGNAL(pressed()), this, SLOT(onButtonBegin()));
    connect(ui->button_stop, SIGNAL(pressed()), this, SLOT(onButtonStop()));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete m_machine1;
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

void MainWindow::destroySupplySwitch(){

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
}

void MainWindow::onButtonBegin() {
    if (!m_is_start) {
        m_is_start = true;
        m_timer->start(1000);
    }
}

void MainWindow::onButtonStop() {
    if (m_is_start) {
        m_is_start = false;
        m_timer->stop();
        m_time_record->setHMS(0, 0, 0);
        ui->time_show->setTime(*m_time_record);
    }
}

void MainWindow::updateSupplyThreshold() {
    if (m_is_start) {
        int value = ui->fluid_threshold->value();
        cout<<"changed value"<<value<<endl;
    }
}
