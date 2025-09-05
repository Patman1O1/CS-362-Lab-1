#include <cstddef>

/*
  Blink without Delay

  Turns on and off a light emitting diode (LED) connected to a digital pin,
  without using the delay() function. This means that other code can run at the
  same time without being interrupted by the LED code.

  The circuit:
  - Use the onboard LED.
  - Note: Most Arduinos have an on-board LED you can control. On the UNO, MEGA
    and ZERO it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN
    is set to the correct LED pin independent of which board is used.
    If you want to know what pin the on-board LED is connected to on your
    Arduino model, check the Technical Specs of your board at:
    https://www.arduino.cc/en/Main/Products

  created 2005
  by David A. Mellis
  modified 8 Feb 2010
  by Paul Stoffregen
  modified 11 Nov 2013
  by Scott Fitzgerald
  modified 9 Jan 2017
  by Arturo Guadalupi

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/BlinkWithoutDelay
*/

enum class LEDColor { RED, GREEN, YELLOW, WHITE, BLUE };

struct Pin {
  PinStatus status;

  pin_size_t number;

  PinMode mode;

  bool operator==(const Pin& other) const noexcept {
    return this->status == other.status && this->number == other.number && this->mode == other.mode;
  }

  bool operator!=(const Pin& other) const noexcept { return !(*this == other); }

};

class LEDLight {
private:
  Pin pin;

  LEDColor color;

public:
  LEDLight() : pin({LOW, LED_BUILTIN, OUTPUT}), color(LEDColor::WHITE) {}

  LEDLight(LEDColor color) : pin({LOW, LED_BUILTIN, OUTPUT}), color(color) {}

  LEDLight(LEDColor color, pin_size_t pinNumber) : pin({LOW, pinNumber, OUTPUT}), color(color) {}

  LEDLight(LEDColor color, Pin pin) : pin(pin), color(color) {}

  LEDLight(const LEDLight&) noexcept = default;

  LEDLight(LEDLight&&) noexcept = default;

  ~LEDLight() noexcept = default;

  LEDLight& operator=(const LEDLight&) noexcept = default;

  LEDLight& operator=(LEDLight&&) noexcept = default;

  bool operator==(const LEDLight& other) const noexcept {
    return this->pin == other.pin && this->color == other.color;
  }

  bool operator!=(const LEDLight& other) const noexcept { return !(*this == other); }

  explicit operator bool() noexcept { return this->pin.status != LOW; }

  void turnOn() noexcept {
    this->pin.status = HIGH;
    digitalWrite(this->pin.number, this->pin.status);
  }

  void turnOff() noexcept {
    this->pin.status = LOW;
    digitalWrite(this->pin.number, this->pin.status);
  }

  void changePinNumber(pin_size_t number) noexcept { this->pin.number = number; }

  void setColor(const enum LEDColor color) noexcept { this->color = color; }

  [[nodiscard]] bool isOn() const noexcept { return this->pin.status == HIGH; }

  [[nodiscard]] bool isOff() const noexcept { return this->pin.status == LOW; }

  [[nodiscard]] pin_size_t getPinNumber() const noexcept { return this->pin.number; }

  [[nodiscard]] LEDColor getColor() const noexcept { return this->color; }

  void setUp() const noexcept { pinMode(this->pin.number, OUTPUT); }

};

LEDLight boardLED(LEDColor::YELLOW);
LEDLight redLED(LEDColor::RED);
LEDLight greenLED(LEDColor::GREEN, 11);

constexpr std::size_t ledCount = 3;
LEDLight ledLights[] = {boardLED, redLED, greenLED};


// Generally, you should use "unsigned long" for variables that hold time
// The value will quickly become too large for an int to store
unsigned long previousMillis = 0;  // will store last time LED was updated

// constants won't change:
constexpr long interval = 1000;  // interval at which to blink (milliseconds)

void setup() {
  boardLED.setUp();
  redLED.setUp();
  greenLED.setUp();

  // set the digital pin as output:
  //pinMode(ledPin, OUTPUT);
}

void loop() {
  // check to see if it's time to blink the LED; that is, if the difference
  // between the current time and last time you blinked the LED is bigger than
  // the interval at which you want to blink the LED.
  
}
