#ifndef LED_LIGHT_HPP
#define LED_LIGHT_HPP

#include <cstddef>

#include <Arduino.h>

#include "DigitalPin.hpp"


namespace ino {

  enum class LEDColor { WHITE, RED, GREEN, YELLOW, BLUE };

  class LEDLight {
  private:
    /* -------------------------------------------------Fields--------------------------------------------------- */
    DigitalPin _pin;

  public:
    /* -------------------------------------------------Fields--------------------------------------------------- */
    LEDColor color;

    /* ----------------------------------------------Constructors------------------------------------------------ */
    LEDLight() noexcept;

    LEDLight(const DigitalPin& pin, LEDColor color) noexcept;

    LEDLight(DigitalPin&& pin, LEDColor color) noexcept;

    LEDLight(const LEDLight&) noexcept = default;

    LEDLight(LEDLight&&) noexcept = default;

    /* -----------------------------------------------Destructor------------------------------------------------- */
    ~LEDLight() noexcept = default;

    /* ------------------------------------------Overloaded Operators-------------------------------------------- */
    LEDLight& operator=(const LEDLight&) noexcept = default;

    LEDLight& operator=(LEDLight&&) noexcept = default;

    [[nodiscard]] bool operator==(const LEDLight& rhs) const noexcept;

    [[nodiscard]] bool operator==(LEDLight&& rhs) const noexcept;

    [[nodiscard]] bool operator!=(const LEDLight& rhs) const noexcept;

    [[nodiscard]] bool operator!=(LEDLight&& rhs) const noexcept;

    /* ------------------------------------------------Setters--------------------------------------------------- */
    void setPin(const DigitalPin& pin) noexcept;

    void setPin(DigitalPin&& pin) noexcept;
    
    /* ------------------------------------------------Getters--------------------------------------------------- */
    [[nodiscard]] DigitalPin getPin() const noexcept;
    
    /* ------------------------------------------------Methods--------------------------------------------------- */
    [[nodiscard]] bool isOn() const noexcept;

    [[nodiscard]] bool isOff() const noexcept;

    void turnOn() noexcept;

    void turnOff() noexcept;

  };

} // ino

#endif
