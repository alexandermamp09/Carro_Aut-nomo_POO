#ifndef MOTOR_DC_H
#define MOTOR_DC_H

#include <Arduino.h>

class MotorDC {
    private:
        int pinIN1; 
        int pinin2,
        int pinPWM;
        int canalPWM; 

    public: 
    MotorDC(int in1, int in2, int pwm, int canal) {
    void inicializar();
    void setVelocidad(int velocidad);
    }};

    #endif