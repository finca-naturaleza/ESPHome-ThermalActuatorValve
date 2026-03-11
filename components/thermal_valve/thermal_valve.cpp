#include "thermal_valve.h"

namespace esphome {
namespace thermal_valve {

void ThermalValve::setup() {
  last_time_ = millis();
}

void ThermalValve::loop() {

  uint32_t now = millis();
  if (now - last_time_ < update_interval_)
    return;
  if (!sensor_ || !relay_ || !setpoint_) return;

  float input = sensor_->state;
  float setpoint = setpoint_->state;
  float error = setpoint - input;
  
  if (fabs(error) < deadband_)
    return;

  if (error > 0)
    relay_->turn_on();
  else
    relay_->turn_off();
    
  last_time_ = now;
}

}
}
