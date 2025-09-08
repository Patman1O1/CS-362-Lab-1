#include "Time.hpp"


namespace ino {
  /* ------------------------------------------------Constructors------------------------------------------------ */
  Time::Time() noexcept : previousMillis(0), previousMicros(0), interval(1) {}

  Time::Time(std::int64_t interval) noexcept : previousMillis(0), previousMicros(0), interval(interval) {}

  /* --------------------------------------------Overloaded Operators-------------------------------------------- */
  [[nodiscard]] bool Time::operator==(const Time& rhs) const noexcept {
    return this->previousMillis == rhs.previousMillis &&
           this->previousMicros == rhs.previousMicros && 
           this->interval == rhs.interval;
  }

  [[nodiscard]] bool Time::operator==(Time&& rhs) const noexcept {
    return this->previousMillis == rhs.previousMillis &&
           this->previousMicros == rhs.previousMicros && 
           this->interval == rhs.interval;
  }

  [[nodiscard]] bool Time::operator!=(const Time& rhs) const noexcept { return !(*this == rhs); }

  [[nodiscard]] bool Time::operator!=(Time&& rhs) const noexcept { return !(*this == rhs); }

  /* --------------------------------------------------Methods--------------------------------------------------- */
  void Time::millisDelay(std::function<void()> lambda) noexcept {
    // Get the current time in milliseconds
    std::uint64_t currentMillis = millis();

    if (currentMillis - this->previousMillis >= this->interval) {
      // Update the previous time
      this->previousMillis = currentMillis;

      // Call the lambda function
      lambda();
    }
  }

  void Time::microDelay(std::function<void()> lambda) noexcept {
    // Get the current time in microseconds
    std::uint64_t currentMicros = micros();

    if (currentMicros - this->previousMicros >= this->interval) {
      // Update the previous time
      this->previousMicros = currentMicros;

      // Call the lambda function
      lambda();
    }
  }
  

} // ino
