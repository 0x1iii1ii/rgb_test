#ifndef RGB_H
#define RGB_H

#include "Arduino.h"
#include <FastLED.h>

#define NUM_LEDS 1
#define DATA_PIN 48

static uint8_t hue = 0;
static int led_index = 0;
static bool direction = true; // true for forward, false for backward
static unsigned long previousMillis = 0;
const long interval = 10; // interval to wait between updates

CRGB leds[NUM_LEDS];

void updateLEDs();

void updateLEDs()
{
  if (direction)
  {
    // Slide the LEDs forward
    if (led_index < NUM_LEDS)
    {
      leds[led_index] = CHSV(hue++, 255, 255);
      FastLED.show();
      leds[led_index].nscale8(250);
      led_index++;
    }
    else
    {
      direction = false;
      led_index = NUM_LEDS - 1;
    }
  }
  else
  {
    // Slide the LEDs backward
    if (led_index >= 0)
    {
      leds[led_index] = CHSV(hue++, 255, 255);
      FastLED.show();
      leds[led_index].nscale8(250);
      led_index--;
    }
    else
    {
      direction = true;
      led_index = 0;
    }
  }
}

#endif