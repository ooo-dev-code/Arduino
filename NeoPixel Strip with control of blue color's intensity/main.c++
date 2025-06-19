#include <Adafruit_NeoPixel.h>

#define PIN 2
#define NUMPIXELS 8

int sensorValue = 0;
int delayval = 100;
int redColor = 0;
int greenColor = 0;
int blueColor = 0;

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  pinMode(A0, INPUT);
  Serial.begin(9600);
  pixels.begin();
}

void loop() {
  sensorValue = analogRead(A0);
  int blueValue = map(sensorValue, 0, 1023, 0, 255);
  Serial.println(blueValue);

  setColor();  // Optional: Call less frequently if desired

  for (int i = 0; i < NUMPIXELS; i++) {
    pixels.setPixelColor(i, pixels.Color(redColor, greenColor, blueValue));
  }
  pixels.show();

  delay(delayval);
}

void setColor() {
  redColor = random(0, 256);
  greenColor = random(0, 256);
  // blueColor will be set from sensor instead
}
