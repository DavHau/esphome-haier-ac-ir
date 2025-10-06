import esphome.codegen as cg
from esphome.components import climate

haier_acyrw02_ns = cg.esphome_ns.namespace("haier_acyrw02")

# Define the HaierClimate class here so it's available to all subcomponents
HaierClimate = haier_acyrw02_ns.class_("HaierClimate", climate.Climate)