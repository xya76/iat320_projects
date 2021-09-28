#include <FastLED.h>
#define LED_PIN     9
#define NUM_LEDS    10
CRGB leds[NUM_LEDS];  //define 

void setup() { //inital
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
}
void loop() { 
   for (int i = 0; i <= NUM_LEDS; i++) { //floating effect from https://howtomechatronics.com
    leds[i] = CRGB ( 255, 0, 100);
    FastLED.show();
    delay(40);
  }
  for (int i = NUM_LEDS; i >= 0; i--) {
    leds[i] = CRGB ( 100, 255, 0);
    FastLED.show();
    delay(40);
  }
  for (int i = 0; i <= 10; i++) { // flashing effect from Tony
    leds[0] = CRGB::White;
    leds[1] = CRGB::White;
    leds[2] = CRGB::White;
    leds[3] = CRGB::White;
    leds[4] = CRGB::White;
    leds[5] = CRGB::White;
    leds[6] = CRGB::White;
    leds[7] = CRGB::White;
    leds[8] = CRGB::White;
    leds[9] = CRGB::White;
    FastLED.show();
    delay(80);
    leds[0] = CRGB::Black;
    leds[1] = CRGB::Black;
    leds[2] = CRGB::Black;
    leds[3] = CRGB::Black;
    leds[4] = CRGB::Black;
    leds[5] = CRGB::Black;
    leds[6] = CRGB::Black;
    leds[7] = CRGB::Black;
    leds[8] = CRGB::Black;
    leds[9] = CRGB::Black;
    FastLED.show();
    delay(80);
  }
}
