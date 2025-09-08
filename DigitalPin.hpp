#ifndef DIGITAL_PIN_HPP
#define DIGITAL_PIN_HPP

#include <cstddef>

#include <Arduino.h>


namespace ino {

  class DigitalPin {
  private:
    /* -------------------------------------------------Fields--------------------------------------------------- */
    pin_size_t _number;

    PinMode _mode;

    PinStatus _status;

  public:
    /* ----------------------------------------------Constructors------------------------------------------------ */
    DigitalPin() noexcept;

    DigitalPin(pin_size_t number, PinMode mode) noexcept;

    DigitalPin(pin_size_t number, PinMode mode, PinStatus status) noexcept;

    DigitalPin(const DigitalPin&) noexcept = default;

    DigitalPin(DigitalPin&&) noexcept = default;

    /* -----------------------------------------------Destructor------------------------------------------------- */
    ~DigitalPin() noexcept = default;

    /* ------------------------------------------Overloaded Operators-------------------------------------------- */
    DigitalPin& operator=(const DigitalPin&) noexcept = default;

    DigitalPin& operator=(DigitalPin&&) noexcept = default;

    [[nodiscard]] bool operator==(const DigitalPin& rhs) const noexcept;

    [[nodiscard]] bool operator==(DigitalPin&& rhs) const noexcept;

    [[nodiscard]] bool operator!=(const DigitalPin& rhs) const noexcept;

    [[nodiscard]] bool operator!=(DigitalPin&& rhs) const noexcept;
  
    /* ------------------------------------------------Setters--------------------------------------------------- */
    void setNumber(pin_size_t number) noexcept;

    void setMode(PinMode mode) noexcept;

    void setStatus(PinStatus status) noexcept;
    
    /* ------------------------------------------------Getters--------------------------------------------------- */
    [[nodiscard]] pin_size_t getNumber() const noexcept;

    [[nodiscard]] PinMode getMode() const noexcept;

    [[nodiscard]] PinStatus getStatus() const noexcept;
    

  };

} // ino

#endif // DIGITAL_PIN_HPP
