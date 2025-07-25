#include <Arduino.h>
#include "rgb.h"

// put function declarations here:
int myFunction(int, int);

void setup() {
  // put your setup code here, to run once:
  // pinMode(DATA_PIN, OUTPUT);
  FastLED.addLeds<WS2812, DATA_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness(50);
  int result = myFunction(2, 3);
}

void loop() {
  // put your main code here, to run repeatedly:
  updateLEDs();
  delay(10); // Adjust the delay as needed
}

// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
}