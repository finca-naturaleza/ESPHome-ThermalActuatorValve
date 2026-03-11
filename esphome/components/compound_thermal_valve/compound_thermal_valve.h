#pragma once

#include "esphome.h"
#include "thermal_valve/thermal_valve.h"  // Make sure this path matches your repo structure

namespace esphome {
namespace compound_thermal_valve {

class CompoundThermalValve : public Component {
 public:
  CompoundThermalValve() = default;

  void set_valve1(thermal_valve::ThermalValve *valve) { this->valve1_ = valve; }
  void set_valve2(thermal_valve::ThermalValve *valve) { this->valve2_ = valve; }
  void set_valve3(thermal_valve::ThermalValve *valve) { this->valve3_ = valve; }
  void set_valve4(thermal_valve::ThermalValve *valve) { this->valve4_ = valve; }
  void set_valve5(thermal_valve::ThermalValve *valve) { this->valve5_ = valve; }
  void set_valve6(thermal_valve::ThermalValve *valve) { this->valve6_ = valve; }
  void set_valve7(thermal_valve::ThermalValve *valve) { this->valve7_ = valve; }
  void set_valve8(thermal_valve::ThermalValve *valve) { this->valve8_ = valve; }

  void setup() override {
    if (valve1_) valve1_->setup();
    if (valve2_) valve2_->setup();
    if (valve3_) valve3_->setup();
    if (valve4_) valve4_->setup();
    if (valve5_) valve5_->setup();
    if (valve6_) valve6_->setup();
    if (valve7_) valve7_->setup();
    if (valve8_) valve8_->setup();
    ESP_LOGD("compound_thermal_valve", "CompoundThermalValve setup");
  }

  void loop() override {
    if (valve1_) valve1_->loop();
    if (valve2_) valve2_->loop();
    if (valve3_) valve3_->loop();
    if (valve4_) valve4_->loop();
    if (valve5_) valve5_->loop();
    if (valve6_) valve6_->loop();
    if (valve7_) valve7_->loop();
    if (valve8_) valve8_->loop();
  }

 protected:
  thermal_valve::ThermalValve *valve1_{nullptr};
  thermal_valve::ThermalValve *valve2_{nullptr};
  thermal_valve::ThermalValve *valve3_{nullptr};
  thermal_valve::ThermalValve *valve4_{nullptr};
  thermal_valve::ThermalValve *valve5_{nullptr};
  thermal_valve::ThermalValve *valve6_{nullptr};
  thermal_valve::ThermalValve *valve7_{nullptr};
  thermal_valve::ThermalValve *valve8_{nullptr};
};

}  // namespace compound_thermal_valve
}  // namespace esphome