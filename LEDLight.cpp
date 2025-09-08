#include "LEDLight.hpp"


namespace ino {

  /* ------------------------------------------------Constructors------------------------------------------------ */
  LEDLight::LEDLight() noexcept : _pin(DigitalPin(LED_BUILTIN, OUTPUT)), color(LEDColor::WHITE) {}

  LEDLight::LEDLight(const DigitalPin& pin, LEDColor color) noexcept : _pin(pin), color(color) {}

  LEDLight::LEDLight(DigitalPin&& pin, LEDColor color) noexcept : _pin(pin), color(color) {}

  /* --------------------------------------------Overloaded Operators-------------------------------------------- */
  [[nodiscard]] bool LEDLight::operator==(const LEDLight& rhs) const noexcept {
    return this->_pin == rhs._pin && this->color == rhs.color;
  }

  [[nodiscard]] bool LEDLight::operator==(LEDLight&& rhs) const noexcept {
    return this->_pin == rhs._pin && this->color == rhs.color;
  }

  [[nodiscard]] bool LEDLight::operator!=(const LEDLight& rhs) const noexcept { return !(*this == rhs); }

  [[nodiscard]] bool LEDLight::operator!=(LEDLight&& rhs) const noexcept { return !(*this == rhs); }

  /* --------------------------------------------------Setters--------------------------------------------------- */
  void LEDLight::setPin(const DigitalPin& pin) noexcept { this->_pin = pin; }

  void LEDLight::setPin(DigitalPin&& pin) noexcept { this->_pin = pin; }

  /* --------------------------------------------------Getters--------------------------------------------------- */
  [[nodiscard]] DigitalPin LEDLight::getPin() const noexcept { return this->_pin; }

  /* --------------------------------------------------Methods--------------------------------------------------- */
  [[nodiscard]] bool LEDLight::isOn() const noexcept { return this->_pin.getStatus() == HIGH; }

  [[nodiscard]] bool LEDLight::isOff() const noexcept { return this->_pin.getStatus() == LOW; }

  void LEDLight::turnOn() noexcept { this->_pin.setStatus(HIGH); }

  void LEDLight::turnOff() noexcept { this->_pin.setStatus(LOW); }

} // ino
