import esphome.codegen as cg
import esphome.config_validation as cv
from ..thermal_valve import thermal_valve
from esphome.const import CONF_ID

compound_thermal_valve_ns = cg.esphome_ns.namespace("compound_thermal_valve")
CompoundThermalValve = compound_thermal_valve_ns.class_(
    "EmptyCompoundSensor", cg.PollingComponent
)

CONF_VALVE1 = "valve1"
CONF_VALVE2 = "valve2"
CONF_VALVE3 = "valve3"
CONF_VALVE4 = "valve4"
CONF_VALVE5 = "valve5"
CONF_VALVE6 = "valve6"
CONF_VALVE7 = "valve7"
CONF_VALVE8 = "valve8"

CONFIG_SCHEMA = cv.Schema(
    {
        cv.GenerateID(): cv.declare_id(CompoundThermalValve),
        cv.Required(CONF_VALVE1): thermal_valve.CONFIG_SCHEMA(CompoundThermalValve).extend(),
        cv.Optional(CONF_VALVE2): thermal_valve.CONFIG_SCHEMA(CompoundThermalValve).extend(),
        cv.Optional(CONF_VALVE3): thermal_valve.CONFIG_SCHEMA(CompoundThermalValve).extend(),
        cv.Optional(CONF_VALVE4): thermal_valve.CONFIG_SCHEMA(CompoundThermalValve).extend(),
        cv.Optional(CONF_VALVE5): thermal_valve.CONFIG_SCHEMA(CompoundThermalValve).extend(),
        cv.Optional(CONF_VALVE6): thermal_valve.CONFIG_SCHEMA(CompoundThermalValve).extend(),
        cv.Optional(CONF_VALVE7): thermal_valve.CONFIG_SCHEMA(CompoundThermalValve).extend(),
        cv.Optional(CONF_VALVE8): thermal_valve.CONFIG_SCHEMA(CompoundThermalValve).extend(),
    }
).extend(cv.COMPONENT_SCHEMA)


async def to_code(config):
    var = cg.new_Pvariable(config[CONF_ID])
    await cg.register_component(var, config)

    if CONF_VALVE1 in config:
        valve = await thermal_valve.to_code(config[CONF_VALVE1], parent=var)
        cg.add(var.set_valve1(valve))

    if CONF_VALVE2 in config:
        valve = await thermal_valve.to_code(config[CONF_VALVE2], parent=var)
        cg.add(var.set_valve2(valve))

    if CONF_VALVE3 in config:
        valve = await thermal_valve.to_code(config[CONF_VALVE3], parent=var)
        cg.add(var.set_valve3(valve))

    if CONF_VALVE4 in config:
        valve = await thermal_valve.to_code(config[CONF_VALVE4], parent=var)
        cg.add(var.set_valve4(valve))

    if CONF_VALVE5 in config:
        valve = await thermal_valve.to_code(config[CONF_VALVE5], parent=var)
        cg.add(var.set_valve5(valve))

    if CONF_VALVE6 in config:
        valve = await thermal_valve.to_code(config[CONF_VALVE6], parent=var)
        cg.add(var.set_valve6(valve))

    if CONF_VALVE7 in config:
        valve = await thermal_valve.to_code(config[CONF_VALVE7], parent=var)
        cg.add(var.set_valve7(valve))

    if CONF_VALVE8 in config:
        valve = await thermal_valve.to_code(config[CONF_VALVE8], parent=var)
        cg.add(var.set_valve8(valve))
