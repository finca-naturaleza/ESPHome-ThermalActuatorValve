#include "compound_thermal_valve.h"
#include "esphome/components/thermal_valve/thermal_valve.h"

namespace esphome {
namespace compound_thermal_valve {

  void CompoundThermalValve::setup() {
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

  void CompoundThermalValve::loop() {
    if (valve1_) valve1_->loop();
    if (valve2_) valve2_->loop();
    if (valve3_) valve3_->loop();
    if (valve4_) valve4_->loop();
    if (valve5_) valve5_->loop();
    if (valve6_) valve6_->loop();
    if (valve7_) valve7_->loop();
    if (valve8_) valve8_->loop();
  }

}  // namespace compound_thermal_valve
}  // namespace esphome