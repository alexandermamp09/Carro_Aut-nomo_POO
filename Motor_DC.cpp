#include "MotorDC.h"

MotorDC::MotorDC(int pA, int pB)
{
    pinA = pA;
    pinB = pB;

    canalA = 0;
    canalB = 1;

    freq = 1000;
    resolution = 8;
}

void MotorDC::begin()
{
    ledcSetup(canalA, freq, resolution);
    ledcSetup(canalB, freq, resolution);

    ledcAttachPin(pinA, canalA);
    ledcAttachPin(pinB, canalB);

    stop();
}

int MotorDC::speedToDuty(int speed)
{
    speed = constrain(speed, -100, 100);

    return map(abs(speed), 0, 100, 0, 255);
}

void MotorDC::setSpeed(int speed)
{
    speed = constrain(speed, -100, 100);

    int duty = speedToDuty(speed);

    if (speed > 0) {
        ledcWrite(canalA, duty);
        ledcWrite(canalB, 0);
    }
    else if (speed < 0) {
        ledcWrite(canalA, 0);
        ledcWrite(canalB, duty);
    }
    else {
        stop();
    }
}

void MotorDC::stop()
{
    ledcWrite(canalA, 0);
    ledcWrite(canalB, 0);
}
