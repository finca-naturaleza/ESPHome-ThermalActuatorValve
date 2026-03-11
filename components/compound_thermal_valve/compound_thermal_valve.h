#pragma once

#include "esphome.h"

namespace esphome {

namespace thermal_valve {
  // Forward declaration only
  class ThermalValve;
}  // namespace thermal_valve


namespace compound_thermal_valve {

class CompoundThermalValve : public Component {
 public:
  void set_valve1(esphome::thermal_valve::ThermalValve *valve) { valve1_ = valve; }
  void set_valve2(esphome::thermal_valve::ThermalValve *valve) { valve2_ = valve; }
  void set_valve3(esphome::thermal_valve::ThermalValve *valve) { valve3_ = valve; }
  void set_valve4(esphome::thermal_valve::ThermalValve *valve) { valve4_ = valve; }
  void set_valve5(esphome::thermal_valve::ThermalValve *valve) { valve5_ = valve; }
  void set_valve6(esphome::thermal_valve::ThermalValve *valve) { valve6_ = valve; }
  void set_valve7(esphome::thermal_valve::ThermalValve *valve) { valve7_ = valve; }
  void set_valve8(esphome::thermal_valve::ThermalValve *valve) { valve8_ = valve; }

  void setup() override;
  void loop() override;

 protected:
  esphome::thermal_valve::ThermalValve *valve1_{nullptr};
  esphome::thermal_valve::ThermalValve *valve2_{nullptr};
  esphome::thermal_valve::ThermalValve *valve3_{nullptr};
  esphome::thermal_valve::ThermalValve *valve4_{nullptr};
  esphome::thermal_valve::ThermalValve *valve5_{nullptr};
  esphome::thermal_valve::ThermalValve *valve6_{nullptr};
  esphome::thermal_valve::ThermalValve *valve7_{nullptr};
  esphome::thermal_valve::ThermalValve *valve8_{nullptr};
};

}  // namespace compound_thermal_valve
}  // namespace esphome