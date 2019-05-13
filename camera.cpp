#include "camera.h"
#include "mainwindow.h"
#include "ui_camera.h"
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QCameraInfo>
#include <QDateTime>
#include <iostream>

class MainWindow;
using std::cout;
using std::endl;


camera::camera(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::camera)
{
    this->init();
}

camera::~camera()
{
    delete m_camera;
    delete m_view_finder;
    delete m_image_capture;
    delete ui;
}

void camera::init() {
    m_capture_gap = 2;

    QList<QCameraInfo> cameras = QCameraInfo::availableCameras();
    cout << "default:" << QCameraInfo::defaultCamera().deviceName().toStdString() << endl;
    for (QCameraInfo t : cameras) {
        cout << "names:" << t.deviceName().toStdString() << endl;
    }

    m_camera = new QCamera(cameras[0], nullptr);
    m_view_finder = new QCameraViewfinder();
    m_image_capture = new QCameraImageCapture(m_camera);


    m_image_capture->setCaptureDestination(QCameraImageCapture::CaptureToFile);
    m_camera->setCaptureMode(QCamera::CaptureStillImage);
    //m_camera->setCaptureMode(QCamera::CaptureVideo);
    m_camera->setViewfinder(m_view_finder);
}

void camera::onCapture() {
    m_image_capture->capture();
}


void camera::onBegin() {
      m_camera->start();
}

void camera::onExit() {
    m_camera->stop();
    this->close();
}

