#pragma once

#include "esphome/core/log.h"
#include "esphome/components/climate/climate.h"
#include "esphome/components/sensor/sensor.h"
#include "esphome/components/button/button.h"

#include "IRremoteESP8266.h"
#include "IRsend.h"
#include "ir_Haier.h"


namespace esphome {
namespace haier_acyrw02 {

const uint8_t HAIER_ACYRW02_TEMP_MIN = 16;  // 16C
const uint8_t HAIER_ACYRW02_TEMP_MAX = 30;  // 32C

class HaierClimate : public climate::Climate {
 public:
  HaierClimate() : climate::Climate() {}
 public:
  void set_sensor(sensor::Sensor *sensor);
  void init(sensor::Sensor *sensor, uint16_t pin);
  void send_display_toggle();  // Method for display switch to call
  IRHaierACYRW02 *get_ac() { return ac_; }  // Getter for AC object
 
 protected:
  IRHaierACYRW02 *ac_{nullptr};
  sensor::Sensor *sensor_{nullptr};
  
  void setup_ir_cmd();

  climate::ClimateTraits traits() override;
  void control(const climate::ClimateCall &call) override;

};

// Display light button component
class HaierDisplayButton : public button::Button {
 public:
  void set_climate_parent(HaierClimate *parent) { this->parent_ = parent; }
  void press_action() override;

 protected:
  HaierClimate *parent_{nullptr};
};

}  // namespace haier_acyrw02
}  // namespace esphome
