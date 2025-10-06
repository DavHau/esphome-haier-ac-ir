import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.components import button
from esphome.const import CONF_ID

# Import from the haier_acyrw02 component
from ..haier_acyrw02 import haier_acyrw02_ns, HaierClimate

HaierDisplayButton = haier_acyrw02_ns.class_("HaierDisplayButton", button.Button)

CONF_CLIMATE_ID = "climate_id"

CONFIG_SCHEMA = button.button_schema(HaierDisplayButton).extend(
    {
        cv.GenerateID(): cv.declare_id(HaierDisplayButton),
        cv.Required(CONF_CLIMATE_ID): cv.use_id(HaierClimate),
    }
)


async def to_code(config):
    var = await button.new_button(config)
    climate_parent = await cg.get_variable(config[CONF_CLIMATE_ID])
    cg.add(var.set_climate_parent(climate_parent))