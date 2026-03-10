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

## Installation

Include this external component in your ESPHome YAML:

```yaml
external_components:
  - source: github://finca-naturaleza/ESPHome-ThermalActuatorValve