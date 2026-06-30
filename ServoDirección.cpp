#include "ServoDireccion.h"

ServoDireccion::ServoDireccion(int pinServo, int centroServo)
{
    pin = pinServo;
    centro = centroServo;
    anguloActual = centro;

    anguloMin = 0;
    anguloMax = 80;

    pulsoMin = 500;
    pulsoMax = 2500;
}

void ServoDireccion::inicializar()
{
    ledcAttach(pin, 50, 16);  // ESP32 3.x CORRECTO
    centrar();
}

int ServoDireccion::anguloADuty(int angulo)
{
    angulo = constrain(angulo, anguloMin, anguloMax);

    int pulso = map(angulo, anguloMin, anguloMax, pulsoMin, pulsoMax);

    float duty = (float)pulso / 20000.0; 

    return duty * 65535;
}

void ServoDireccion::fijarAngulo(int angulo)
{
    anguloActual = constrain(angulo, anguloMin, anguloMax);
    ledcWrite(pin, anguloADuty(anguloActual));
}

void ServoDireccion::centrar()
{
    fijarAngulo(centro);
}

int ServoDireccion::obtenerAngulo()
{
    return anguloActual;
}
