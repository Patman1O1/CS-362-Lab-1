#ifndef TIME_HPP
#define TIME_HPP

#include <cstddef>
#include <cstdint>
#include <functional>

#include <Arduino.h>


namespace ino {

  struct Time {
    /* -------------------------------------------------Fields--------------------------------------------------- */
    std::uint64_t previousMillis, previousMicros;

    std::int64_t interval;

    /* ----------------------------------------------Constructors------------------------------------------------ */
    Time() noexcept;

    Time(std::int64_t interval) noexcept;

    Time(const Time&) noexcept = default;

    Time(Time&&) noexcept = default;

    /* -----------------------------------------------Destructor------------------------------------------------- */
    ~Time() noexcept = default;

    /* ------------------------------------------Overloaded Operators-------------------------------------------- */
    Time& operator=(const Time&) noexcept = default;

    Time& operator=(Time&&) noexcept = default;

    [[nodiscard]] bool operator==(const Time& rhs) const noexcept;

    [[nodiscard]] bool operator==(Time&& rhs) const noexcept;

    [[nodiscard]] bool operator!=(const Time& rhs) const noexcept;

    [[nodiscard]] bool operator!=(Time&& rhs) const noexcept;

    /* ------------------------------------------------Methods--------------------------------------------------- */
    void millisDelay(std::function<void()> lambda) noexcept;

    void microDelay(std::function<void()> lambda) noexcept;
    
  };

} // ino

#endif // TIME_HPP
