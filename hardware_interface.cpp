#include "hardware_interface.hpp"
#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::endl;
using std::vector;
using std::string;

void ElectricMachine::setSpeed(machine_speed_t value) {
    //cout << "machine speed" << value << endl;
}

vector<float> Sensor::getData() const {
    vector<float> ret;
    ret.push_back(a_x);
    ret.push_back(a_y);
    ret.push_back(a_z);
    ret.push_back(w_x);
    ret.push_back(w_y);
    ret.push_back(w_z);
    ret.push_back(theta_x);
    ret.push_back(theta_y);
    ret.push_back(theta_z);
    ret.push_back(T);
    return ret;
}

void Sensor::setData(const vector<float>& data) {
    a_x = data[0];
    a_y = data[1];
    a_z = data[2];
    w_x = data[3];
    w_y = data[4];
    w_z = data[5];
    theta_x = data[6];
    theta_y = data[7];
    theta_z = data[8];
    T = data[9];
}

string& Sensor::toString() {
    string ret = "";
    ret += "a_x:" + std::to_string(a_x) + "\n";
    ret += "a_y:" + std::to_string(a_y) + "\n";
    ret += "a_z:" + std::to_string(a_z) + "\n";
    ret += "w_x:" + std::to_string(w_x) + "\n";
    ret += "w_y:" + std::to_string(w_y) + "\n";
    ret += "w_z:" + std::to_string(w_z) + "\n";
    ret += "theta_x:" + std::to_string(theta_x) + "\n";
    ret += "theta_y:" + std::to_string(theta_y) + "\n";
    ret += "theta_z:" + std::to_string(theta_z) + "\n";
    ret += "T:" + std::to_string(T) + "\n";
    return ret;
}

