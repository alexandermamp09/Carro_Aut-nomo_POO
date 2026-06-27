#include "ServoDireccion.h"

ServoDireccion::ServoDireccion(int pinServo, int centroServo)
{
    pin = pinServo;
    centro = centroServo;
    anguloActual = centro;

    anguloMin = 0;
    anguloMax = 180;

    pulsoMin = 500;
    pulsoMax = 2500;
}

void ServoDireccion::inicializar()
{
    ledcAttach(pin, 50, 16);  // ESP32 3.x CORRECTO
    centrar();
}

int ServoDireccion::convertirMicrosegundos(int angulo)
{
    angulo = constrain(angulo, anguloMin, anguloMax);

    int pulso = map(angulo, anguloMin, anguloMax, pulsoMin, pulsoMax);

    return (pulso * 65535) / 20000;
}

void ServoDireccion::fijarAngulo(int angulo)
{
    anguloActual = constrain(angulo, anguloMin, anguloMax);
    ledcWrite(pin, convertirMicrosegundos(anguloActual));
}

void ServoDireccion::centrar()
{
    fijarAngulo(centro);
}

int ServoDireccion::obtenerAngulo()
{
    return anguloActual;
}
