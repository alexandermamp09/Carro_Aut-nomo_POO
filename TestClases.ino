1) Test de servo:

#include "ServoDireccion.h"

ServoDireccion servo(18);

void setup() {
    servo.inicializar();
}

void loop() {
    servo.fijarAngulo(60);
    delay(1000);

    servo.fijarAngulo(120);
    delay(1000);
}

2) Test del Motor DC:


3) Test de los ToF:

