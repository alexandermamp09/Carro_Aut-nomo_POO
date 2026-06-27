#include "ServoDireccion.h"

ServoDireccion::ServoDireccion(int pinServo, int centroServo)
{
    pin = pinServo;
    centro = 45;
    anguloActual = centro;

    anguloMin = 0;
    anguloMax = 80;

    pulsoMin = 500;
    pulsoMax = 2500;
}

void ServoDireccion::inicializar()
{
   const int canalPWM = 0;

ledcSetup(canalPWM, 50, 16);
ledcAttachPin(pin, canalPWM);
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
    const int canalPWM = 0;
    anguloActual = constrain(angulo, anguloMin, anguloMax);
    ledcWrite(canalPWM, convertirMicrosegundos(anguloActual));
}

void ServoDireccion::centrar()
{
    fijarAngulo(centro);
}

int ServoDireccion::obtenerAngulo()
{
    return anguloActual;
}
