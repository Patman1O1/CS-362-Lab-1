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

#include <Arduino.h>
#include <ArduinoGraphics.h>
#include <Arduino_LED_Matrix.h>

#include "LEDLight.hpp"
#include "Time.hpp"

#define MATRIX_SERIAL 115200


// Represents the 8x12 LED matrix on the Arduino
ArduinoLEDMatrix ledMatrix;

// Initalize digital pins 10, 11, 12, and 13
ino::DigitalPin pin10(D10, OUTPUT), pin11(D11, OUTPUT), pin12(D12, OUTPUT), pin13(D13, OUTPUT);

// Represents the onboard LED light on digital pin 13
ino::LEDLight boardLED(pin13, ino::LEDColor::YELLOW);

// Represents a red LED light on digital pin 12
ino::LEDLight redLED(pin12, ino::LEDColor::RED);

// Represents a green LED light on digital pin 11
ino::LEDLight greenLED(pin11, ino::LEDColor::GREEN);

// Represents a blue LED light on digital pin 10
ino::LEDLight blueLED(pin10, ino::LEDColor::BLUE);

// Contains all the LEDs
ino::LEDLight* ledLights[4] = {&boardLED, &redLED, &greenLED, &blueLED};
std::uint8_t ledLightsIndex = 0;

// Text to print on the 8x12 LED matrix
constexpr char text[] = "    CS 361 Lab 1    ";

ino::Time timer;

void setup() {
  Serial.begin(MATRIX_SERIAL);
  ledMatrix.begin();

  timer.interval = 1000;
  ledLights[ledLightsIndex]->turnOn();
}

void loop() {
  timer.millisDelay([](void){
    // Turn off current LED
    ledLights[ledLightsIndex]->turnOff();

    // Advance to next LED (cycle 0 -> 1 -> 2 -> 0 -> ...)
    ledLightsIndex = (ledLightsIndex + 1) % 4;

    // Turn on the new LED
    ledLights[ledLightsIndex]->turnOn();
  });

  //myArduino.matrix.beginDraw();
  ledMatrix.beginDraw();

  ledMatrix.stroke(0xFFFFFFFF);
  ledMatrix.textScrollSpeed(50);

  // add the text
  ledMatrix.textFont(Font_5x7);
  ledMatrix.beginText(0, 1, 0xFFFFFF);
  ledMatrix.println(text);
  ledMatrix.endText(SCROLL_LEFT);

  ledMatrix.endDraw();

}
