#ifndef HARDWARE_INTERFACE_HPP
#define HARDWARE_INTERFACE_HPP
#include "datastructure.hpp"
#include "Serial.h"
#include <vector>
#include <string>

using std::vector;
using std::string;

class ElectricMachine {
public:
    ElectricMachine(machine_speed_t init_value, bool flag) {
        m_state.real_speed = init_value;
        if (flag) {
            m_serial = new CSerial(true);
            m_serial->OpenSerialPort(_T("COM2:"), 115200, 8, 1);
        } else {
            m_serial = new CSerial(false);
        }
    }
    ~ElectricMachine() {
        if (m_serial) {
            delete m_serial;
        }
    }
    void setSpeed(machine_speed_t value1, machine_speed_t value2);
    void setTime(int time);
private:
    electric_machine_state_t m_state;
    CSerial* m_serial;
};

class Sensor {
public:
    Sensor() {
        a_x = 0;
        a_y = 0;
        a_z = 0;
        w_x = 0;
        w_y = 0;
        w_z = 0;
        theta_x = 0;
        theta_y = 0;
        theta_z = 0;
        T = 20;
    }
    ~Sensor(){

    }
    vector<float> getData() const;
    void setData(const vector<float>& data);
    string toString();
private:
    float a_x;
    float a_y;
    float a_z;
    float w_x;
    float w_y;
    float w_z;
    float theta_x;
    float theta_y;
    float theta_z;
    float T;
};

class Pump{
};

class PumpSystem {

};
#endif // HARDWARE_INTERFACE_HPP
