# ESPHome Thermal Valve Component

> External ESPHome component to control a **thermal actuator (thermal valve)** in underfloor heating systems.  

---

## Overview

Underfloor heating systems often use **thermal actuators** (small electric devices that open or close valves using heat) to regulate water flow to different zones. These actuators are **slow** compared to solenoid valves — they take several seconds to minutes to fully open or close.  

This external ESPHome component allows an ESP32 to:

- Read a **sensor** (e.g., pulse counter of a flow meter or temperature)  
- Run a **control loop** to maintain a target flow or other setpoint  
- Control a **relay output** connected to a thermal actuator  
- Adjust the **setpoint dynamically at runtime** via Home Assistant  

It is designed for **slow, binary actuators** where traditional bang-bang control at a low frequency (e.g., 0.1 Hz) is sufficient to maintain stable control.

---

## Features

- **Control** of a single thermal valve (actuator)  
- Configurable **update interval** for slow actuators  
- Optional **deadband** to prevent unnecessary relay toggling  
- Runtime **setpoint adjustable** via Home Assistant `number` entity  
- Fully compatible with multiple instances for multi-zone heating systems  

---

## Parameters

| Parameter | Type | Default | Description |
|-----------|------|---------|-------------|
| `sensor` | any | **required** | Flow/pulse sensor or temperature input. |
| `relay` | `BinaryOutput` | **required** | Relay output controlling the thermal actuator. |
| `setpoint` | `number` | **required** | Runtime adjustable target value. |
| `update_interval` | time | 10s | Frequency at which the PID loop updates. Use slow values (e.g., 10s) for thermal actuators. |
| `deadband` | float | 0.0 | Minimum error before relay toggles, prevents unnecessary switching. |

**Note**: 
When using https://esphome.io/components/sensor/pulse_counter/ or https://esphome.io/components/sensor/pulse_meter/ make sure to follow instructions to adjust the units to the same as your setpoint.

---

## Installation

Include this external component in your ESPHome YAML:

```yaml
external_components:
  - source: github://finca-naturaleza/ESPHome-ThermalActuatorValve
```

---

## Example

```yaml
esphome:
  name: multi_zone_heating
  platform: ESP32
  board: esp32dev

# ---- Option 1: Flow sensor (local) ----
sensor:
  - platform: pulse_counter
    pin: 32
    name: "Flow Sensor Zone 1"
    id: flow1
    update_interval: 1s

# ---- Option 2: Temperature sensor from Home Assistant ----
  - platform: homeassistant
    id: temp2_ha
    entity_id: sensor.zone2_temp
    update_interval: 10s

# ---- Relays for each zone ----
output:
  - platform: gpio
    pin: 4
    id: relay1
  - platform: gpio
    pin: 5
    id: relay2

# ---- Setpoints (runtime adjustable) ----
number:
  - platform: template
    name: "Zone 1 Flow Setpoint"
    id: sp1
    min_value: 0
    max_value: 500
    step: 1
    restore_value: true
    optimistic: true

  - platform: template
    name: "Zone 2 Temperature Setpoint"
    id: sp2
    min_value: 18
    max_value: 30
    step: 0.5
    restore_value: true
    optimistic: true

# ---- Thermal Valve Controllers ----
thermal_valve:
  id: zone1_controller
  sensor: flow1
  relay: relay1
  setpoint: sp1
  update_interval: 10s
  deadband: 2.0

thermal_valve:
  id: zone2_controller
  sensor: temp2_ha
  relay: relay2
  setpoint: sp2
  update_interval: 10s
  deadband: 0.5
```