#ifndef SENSORREADER_H
#define SENSORREADER_H

#include "hardware_interface.hpp"
#include <QThread>
#include <QString>
#include <vector>

using std::vector;
using std::string;


class SensorReader : public QThread
{
    Q_OBJECT
public:
    SensorReader();
    ~SensorReader();
    void quitThread();
    string getSensorData() {
        return m_sensor->toString();
    }
    void setSensorData(const vector<float>& data);
signals:
    void onSensorValueChanged();
protected:
    void run();
private:
    Sensor* m_sensor;
    bool m_isquit;
};

extern SensorReader* handle_sensro_reader;
#endif // SENSORREADER_H
