/*
   Class for controlling the Motor
   drv8838 and
   enconder
*/

#ifndef MOTORDRIVER_h
#define MOTORDRIVER_h

#include "Pins.h"
#include <Encoder.h>

#define FORWARD 0
#define BACKWARD 1

class MotorDriver {
  public:

   //constructor pins for motor Driver
    MotorDriver(uint8_t enable, uint8_t phase) {
      enablePin = enable;
      phasePin = phase;
      pinMode(enablePin, OUTPUT);
      pinMode(phasePin, OUTPUT);
    }

    //set enconder with interrupt pins
    void setEncoder(uint8_t pinA, uint8_t pinB){
      outAPin = pinA;
      outAPin = pinB;
      enconder = new Encoder(outAPin, outAPin);
    }

    void setDirection(bool dir){
      digitalWrite(phasePin, dir);
    }
    
    void setSpeed(uint8_t speed){
      analogWrite(enablePin, speed);
    }

  private:

    //Motor
    uint8_t enablePin;
    uint8_t phasePin;

    //enconder
    uint8_t outAPin;
    uint8_t outBPin;
    Encoder * enconder;
};

#endif
