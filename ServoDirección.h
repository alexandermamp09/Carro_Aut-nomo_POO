#ifndef SERVO_DIRECCION_H
#define SERVO_DIRECCION_H

#include <ESP32servo.h>

class ServoDireccion {
    private:
        Servo miservo;
        int pinServo;

    public:
        ServoDireccion(int pin) {
        void inicializaer();
        void fijarAngulo(int grados);
        };

#endif