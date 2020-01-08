#include "Pins.h"
#include "MotorDriver.h"

#include <Adafruit_NeoPixel.h>

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, LED_NEO, NEO_GRBW + NEO_KHZ800);



MotorDriver motor1(MENABLE_1, MPHASE_1);

MotorDriver motor2(MENABLE_2, MPHASE_2);

MotorDriver motor3(MENABLE_3, MPHASE_3);

MotorDriver motor4(MENABLE_4, MPHASE_4);


void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);

  pixels.begin();
  pixels.show();

  pinMode(13, OUTPUT);
  pinMode(LED_DEBUG, OUTPUT);
  pinMode(SWITCH, INPUT);

  digitalWrite(LED_DEBUG, HIGH);
  delay(2000);
  digitalWrite(LED_DEBUG, LOW);

  digitalWrite(13, HIGH);
  delay(2000);
  digitalWrite(13, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:


  for (int i = 0; i < NUMPIXELS; i++) {

    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixels.setPixelColor(i, pixels.Color(0, 0, 255)); // Moderately bright green color.

    pixels.show(); // This sends the updated pixel color to the hardware.

    //delay(50); // Delay for a period of time (in milliseconds).
  }

  int analogSwitch = digitalRead(SWITCH);
  Serial.println(analogSwitch);

  //
  motor1.setDirection(true);
  motor1.setSpeed(255);

  motor2.setDirection(true);
  motor2.setSpeed(0);

  motor3.setDirection(true);
  motor3.setSpeed(255);

  motor4.setDirection(true);
  motor4.setSpeed(0);
  delay(2000);

  
  motor1.setDirection(true);
  motor1.setSpeed(0);

  motor2.setDirection(true);
  motor2.setSpeed(255);

  motor3.setDirection(true);
  motor3.setSpeed(0);

  motor4.setDirection(true);
  motor4.setSpeed(255);
  delay(2000);

  
}
