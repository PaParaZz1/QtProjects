#include "camera.h"
#include "ui_camera.h"
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QCameraInfo>
#include <QDateTime>
#include <iostream>

using std::cout;
using std::endl;

camera::camera(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::camera)
{
    cout << "constructor" << endl;
    ui->setupUi(this);
    cout << "setup" <<endl;
    this->init();
}

camera::~camera()
{
    delete m_camera;
    delete m_view_finder;
    delete m_image_capture;
    delete m_label;
    delete m_layout;
    delete ui;
}

void camera::init() {
    m_save_path = QString::fromStdString("./");
    QList<QCameraInfo> cameras = QCameraInfo::availableCameras();
    cout << "default:" << QCameraInfo::defaultCamera().deviceName().toStdString() << endl;
    for (QCameraInfo t : cameras) {
        cout << "names:" << t.deviceName().toStdString() << endl;
    }
    int height = 600;
    int width = 400;
    this->resize(height, width);
    m_camera = new QCamera(cameras[1], nullptr);
    m_view_finder = new QCameraViewfinder();
    m_image_capture = new QCameraImageCapture(m_camera);

    QPushButton *capture_button = new QPushButton(QString::fromLocal8Bit("capture"));
    QPushButton *save_button = new QPushButton(QString::fromLocal8Bit("save"));
    QPushButton *exit_button = new QPushButton(QString::fromLocal8Bit("exit"));

    m_label = new QLabel();
    m_label->setFixedSize(200, 150);
    m_label->setScaledContents(true);

    QVBoxLayout *sub_layout = new QVBoxLayout();
    sub_layout->addWidget(m_label);
    sub_layout->addStretch();
    sub_layout->addWidget(capture_button);
    sub_layout->addWidget(save_button);
    sub_layout->addWidget(exit_button);

    m_layout = new QHBoxLayout();
    m_layout->addWidget(m_view_finder);
    m_layout->addLayout(sub_layout);

    connect(capture_button, SIGNAL(clicked()), this, SLOT(onCapture()));
    connect(save_button, SIGNAL(clicked()), this, SLOT(onSave()));
    connect(exit_button, SIGNAL(clicked()), this, SLOT(onExit()));
    connect(m_image_capture, SIGNAL(imageCaptured(int, QImage)), this, SLOT(cameImageCaptured(int,QImage)));

    m_image_capture->setCaptureDestination(QCameraImageCapture::CaptureToFile);
    m_camera->setCaptureMode(QCamera::CaptureStillImage);
    //m_camera->setCaptureMode(QCamera::CaptureVideo);
    m_camera->setViewfinder(m_view_finder);
    m_camera->start();
    this->setLayout(m_layout);
}

void camera::onCapture() {
    m_image_capture->capture();
}

void camera::onSave() {
    //cout << "save call" << endl;
    const QPixmap *img = m_label->pixmap();
    if (img) {
        qint64 timestamp = QDateTime::currentDateTime().toMSecsSinceEpoch();
        //QString *timestamp_str = tr(%1).arg(timestamp);
        QString path = m_save_path + (tr("%1").arg(timestamp)) + QString::fromStdString(".jpg");
        img->save(path);
    }
}

void camera::onExit() {
    m_camera->stop();
    this->close();
}

void camera::cameImageCaptured(const int id, QImage image) {
    m_label->setPixmap(QPixmap::fromImage(image));
}

