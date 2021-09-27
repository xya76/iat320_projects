#include <FastLED.h>
#define LED_PIN 9
#define NUM_LEDS 10
CRGB leds[NUM_LEDS];
int prt=0;
int btnPin = 6;
int btnState=0;

void setup() {
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
  pinMode (btnPin, INPUT);
}
void loop() {
  btnState= digitalRead(btnPin);
if(btnState = HIGH){ 
  prt++; 
  delay(100);
  Serial.print(prt);
  }
  if(prt==1){
    for (int i = 0; i <= NUM_LEDS; i++) {
    leds[i] = CRGB ( 0, 0, 255);
    FastLED.show();
    delay(40);
  }
  for (int i = NUM_LEDS; i >= 0; i--) {
    leds[i] = CRGB ( 255, 0, 0);
    FastLED.show();
    delay(40);
  }
    }
  if(prt==2){
    for (int i = 0; i <= NUM_LEDS; i++) {
    leds[i] = CRGB ( 0, 255, 0);
    FastLED.show();
    delay(40);
  }
  for (int i = NUM_LEDS; i >= 0; i--) {
    leds[i] = CRGB ( 0, 0, 0);
    FastLED.show();
    delay(40);
  }
    }
  if(prt==3){
    for (int i = 0; i <= NUM_LEDS; i++) {
    leds[i] = CRGB ( 255, 0, 0);
    FastLED.show();
    delay(40);
  }
  for (int i = NUM_LEDS; i >= 0; i--) {
    leds[i] = CRGB ( 0, 0, 255);
    FastLED.show();
    delay(40);
  }
    prt=0;
    }
  
  
}
