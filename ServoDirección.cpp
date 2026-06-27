#ifndef SERVO_DIRECCION_H
#define SERVO_DIRECCION_H

#include <Arduino.h>

class ServoDireccion {

private:

    int pin;

    int centro;

    int anguloActual;

    int anguloMin;

    int anguloMax;

    int pulsoMin;

    int pulsoMax;

    int convertirMicrosegundos(int angulo);

public:

    ServoDireccion(int pinServo, int centroServo = 90);

    void inicializar();

    void fijarAngulo(int angulo);

    void centrar();

    int obtenerAngulo();

};

#endif
