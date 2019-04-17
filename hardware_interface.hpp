#ifndef HARDWARE_INTERFACE_HPP
#define HARDWARE_INTERFACE_HPP
#include "datastructure.hpp"

class ElectricMachine {
public:
    ElectricMachine(machine_speed_t init_value=0) {
        m_state.real_speed = init_value;
    }
    ~ElectricMachine() {

    }
    void setSpeed(machine_speed_t value);
private:
    electric_machine_state_t m_state;
};

class Pump{
};

class PumpSystem {

};
#endif // HARDWARE_INTERFACE_HPP
