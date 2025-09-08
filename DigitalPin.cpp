#include "DigitalPin.hpp"


namespace ino {
  /* ------------------------------------------------Constructors------------------------------------------------ */
  DigitalPin::DigitalPin() noexcept : _number(0), _mode(OUTPUT), _status(LOW) {
    pinMode(this->_number, this->_mode);
    digitalWrite(this->_number, this->_status);
  }

  DigitalPin::DigitalPin(pin_size_t number, PinMode mode) noexcept : _number(number), _mode(mode), _status(LOW) {
    pinMode(this->_number, this->_mode);
    digitalWrite(this->_number, this->_status);
  }

  DigitalPin::DigitalPin(pin_size_t number, PinMode mode, PinStatus status) noexcept 
    : _number(number), _mode(mode), _status(status) {
    pinMode(this->_number, this->_mode);
    digitalWrite(this->_number, this->_status);
  }

  /* --------------------------------------------Overloaded Operators-------------------------------------------- */
  [[nodiscard]] bool DigitalPin::operator==(const DigitalPin& rhs) const noexcept {
    return this->_number == rhs._number && this->_mode == rhs._mode && this->_status == rhs._status;
  }

  [[nodiscard]] bool DigitalPin::operator==(DigitalPin&& rhs) const noexcept {
    return this->_number == rhs._number && this->_mode == rhs._mode && this->_status == rhs._status;
  }

  [[nodiscard]] bool DigitalPin::operator!=(const DigitalPin& rhs) const noexcept { return !(*this == rhs); }

  [[nodiscard]] bool DigitalPin::operator!=(DigitalPin&& rhs) const noexcept { return !(*this == rhs); }

  /* --------------------------------------------------Setters--------------------------------------------------- */
  void DigitalPin::setNumber(pin_size_t number) noexcept {
    this->_number = number;
    digitalWrite(this->_number, this->_status);
  }

  void DigitalPin::setMode(PinMode mode) noexcept {
    this->_mode = mode;
    pinMode(this->_number, this->_mode);
  }

  void DigitalPin::setStatus(PinStatus status) noexcept {
    this->_status = status;
    digitalWrite(this->_number, this->_status);
  }

  /* --------------------------------------------------Getters--------------------------------------------------- */
  [[nodiscard]] pin_size_t DigitalPin::getNumber() const noexcept { return this->_number; }

  [[nodiscard]] PinMode DigitalPin::getMode() const noexcept { return this->_mode; }

  [[nodiscard]] PinStatus DigitalPin::getStatus() const noexcept { return this->_status; }


} // ino
