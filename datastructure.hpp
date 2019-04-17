#ifndef DATASTRUCTURE_HPP
#define DATASTRUCTURE_HPP
typedef int bioerrcode;
typedef float machine_speed_t;

typedef struct _electric_machine_setting_t{
    const int min_limit = 0;
    const int max_limit = 100;
    int machine_id;
} electric_machine_setting_t;

typedef struct _electric_machine_state_t{
    machine_speed_t real_speed;
}electric_machine_state_t;

typedef struct _fluid_supply_threshold_t {
    float flow_num_threshold;
    float percentage_threshold;
} fluid_supply_threshold_t;

typedef struct _pump_setting_t {
    const float max_fluid_num_ml = 200;
    int pump_id;
    fluid_supply_threshold_t supply_threshold_t;    
} pump_setting_t;

typedef struct _pump_state_t {
    float fluid_speed;
    float fluid_flow;
    float current_flow_num_ml;
    float current_flow_num_percentage;
} pump_state_t;

typedef struct _culture_device_gesture_t {
    float locate_x;
    float locate_y;
    float locate_z;
} culture_device_gesture_t;

typedef struct _culture_device_setting_t {
    const float max_fluid_num_ml = 200;
    float device_size;
} culture_device_setting_t;
#endif // DATASTRUCTURE_HPP
