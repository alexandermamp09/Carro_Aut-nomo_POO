#ifndef PISTA_WRO_H
#define PISTA_WRO_H

#include <Arduino.h>

enum ColorObstaculo { NINGUNO, VERDE, ROJO };

class PistaWRO {
    private:
        int vueltasObjetivo;
        int vueltasCompletadas;
        int obstaculosEsquivados;

        unsigned long tiempoInicioaCarrera;
        bool carreraEnProgreso;

    public:
        PistaWRO(int vueltasACompletadar);

        void iniciarCarrera();
        void registrarVuelta();

        int calcularDireccionEsquiva(ColorObstaculo colorDetectado);

        bool esCarreraTerminada();
        void mostrarTelemetria();
        
        int getVueltas() { return vueltasCompletadas; }

};

#endif