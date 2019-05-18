#include "sensorreader.h"
#include <iostream>

using std::cout;
using std::endl;

SensorReader::SensorReader()
{
    m_isquit = false;
    m_sensor = new Sensor();
}
SensorReader::~SensorReader(){
    delete m_sensor;
}

void SensorReader::quitThread(){
    m_isquit = true;
}

void SensorReader::run() {
    float count = 0.01;
    while(true) {
        if (m_isquit) {
            break;
        }
        emit onSensorValueChanged();
        this->sleep(1);
        //count += 0.01;
        //cout<<count<<endl;
    }
}

void SensorReader::setSensorData(const vector<float>& data) {
    m_sensor->setData(data);
}


SensorReader* handle_sensor_reader = NULL;
