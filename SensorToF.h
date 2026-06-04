#ifndef SENSOR_TOF_H
#define SENSOR_TOF_H

#include <Wire.h>
#include <Adafruit_VL53l0X.h>

class SensorToF {
    private:
        Adafruit_VL53l0X lox;

    public:
        SensorToF(int xshut);
        bool inicializar();
        int obtenerDistancia();
        };
#endif