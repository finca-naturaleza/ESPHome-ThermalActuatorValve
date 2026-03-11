#pragma once
#include "esphome.h"

namespace esphome {
namespace thermal_valve {

class ThermalValve : public Component {

 public:
  void set_sensor(sensor::Sensor *sensor) { sensor_ = sensor; }
  void set_relay(output::BinaryOutput *relay) { relay_ = relay; }
  void set_setpoint(number::Number *setpoint) { setpoint_ = setpoint; }
  void set_update_interval(uint32_t interval) { update_interval_ = interval; }
  void set_deadband(float deadband) { deadband_ = deadband; }

  void setup() override;
  void loop() override;

 protected:
  sensor::Sensor *sensor_{nullptr};
  output::BinaryOutput *relay_{nullptr};
  number::Number *setpoint_{nullptr};

  uint32_t update_interval_ = 10000;
  uint32_t last_time_ = 0;
  float deadband_ = 0.0;
};

}  
}
