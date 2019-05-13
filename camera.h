#ifndef CAMERA_H
#define CAMERA_H

#include <QWidget>
#include <QCamera>
#include <QCameraViewfinder>
#include <QCameraImageCapture>
#include <QLabel>
#include <QHBoxLayout>

namespace Ui {
class camera;
}

class camera : public QWidget
{
    Q_OBJECT

public:
    explicit camera(QWidget *parent = 0);
    ~camera();

private:
    Ui::camera *ui;
    QCamera *m_camera;
    QCameraViewfinder *m_view_finder;
    QCameraImageCapture *m_image_capture;
    QLabel *m_label;
    QHBoxLayout *m_layout;
    QString m_save_path;
private slots:
    void onCapture();
    void onSave();
    void cameImageCaptured(const int id, QImage image);
    void onExit();
    void init();
};

#endif // CAMERA_H
