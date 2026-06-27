#ifndef MOTOR_DC_H
#define MOTOR_DC_H

#include <Arduino.h>

class MotorDC {

private:

    int pinA;
    int pinB;
    int canalA;
    int canalB;

    int freq;
    int resolution;

    int speedToDuty(int speed);

public:

    MotorDC(int pinA, int pinB);

    void begin();

    void setSpeed(int speed);

    void stop();
};

#endif
