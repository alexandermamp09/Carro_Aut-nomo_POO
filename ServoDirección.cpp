#include "ServoDireccion.h"

ServoDireccion: :ServoDireccion(int pin) {
    pinServo = pin;
}

void ServoDireccion: :inicializaer() {
    miservo.attach(pinServo);
    miservo.write(45);
}

void ServoDireccion: :fijarangulo(int grados) {
    int anguloSeguro = constrain(grados, 0, 75);
    miservo.write(anguloSeguro);
}