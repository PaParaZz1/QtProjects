#ifndef CAMERA_H
#define CAMERA_H

#include "mainwindow.h"

#include <QWidget>
#include <QCamera>
#include <QCameraViewfinder>
#include <QCameraImageCapture>
#include <QLabel>
#include <QHBoxLayout>

namespace Ui {
class MainWindow;
class camera;
}


class camera : public QWidget
{
    Q_OBJECT

public:
    camera(QWidget *parent=0);
    ~camera();
    QCamera *m_camera;
    QCameraViewfinder *m_view_finder;
    QCameraImageCapture *m_image_capture;
private:
    Ui::camera *ui;
    int m_capture_gap;
    void init();
public slots:
    void onCapture();
    void onBegin();
    void onExit();
};

#endif // CAMERA_H
