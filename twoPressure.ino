#include <Adafruit_NeoPixel.h>

#define PIN 8

#define NUMPIXELS 1

const int analogInPinOne = A10;
const int analogInPinTwo = A9;
const int analogOutPin = 7;

int sensorValueOne = 0;
int sensorValueTwo = 0;
int outputValueOne = 0;
int outputValueTwo = 0;

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pixels.begin(); // This initializes the NeoPixel library.
  pixels.setBrightness(255);
  pixels.show();
}

void loop() { //Approach from https://www.motolibrarian.com/flora/ with modified 
  // put your main code here, to run repeatedly:
  sensorValueOne = analogRead(analogInPinOne);
  sensorValueTwo = analogRead(analogInPinTwo);
  outputValueOne = map(sensorValueOne, 0, 1023, 0, 255);
  outputValueTwo = map(sensorValueTwo, 0, 1023, 0, 255);
  //Serial.println(sensorValue);
  analogWrite(analogOutPin, outputValueOne);
  
  if(outputValueOne >= 1 && outputValueTwo >= 1) {
     pixels.setPixelColor(0, pixels.Color(255,255,255)); 
     pixels.show();
    }else{
      pixels.setPixelColor(0, pixels.Color(0,0,0)); 
      pixels.show();
      }
  
  Serial.println("sensor1 = ");
  Serial.println(sensorValueOne);
  Serial.println("\t output = ");
  Serial.println(outputValueOne);
  Serial.println("sensor2 = ");
  Serial.println(sensorValueTwo);
  Serial.println("\t output = ");
  Serial.println(outputValueTwo);
  
  delay(800);
}
