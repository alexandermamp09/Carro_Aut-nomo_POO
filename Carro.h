#ifndef CARRO_H 
#define CARRO_H

#include "Motor_DC.h"
#include "ServoDireccion.h"
#include "SensorToF.h"

class Carro {
  private:
    MotorDC motor; 
    ServoDireccion direccion;
    SensorToF sensorFrente;

    int velociodadActual;
    int anguloDireccion;
    bool encendido;

  public:
    Carro(int pinMotor, int pinServo, int pinToF);

    void arrancar();
    void detener();
    void setVelocidad(int nuevaVelocidad);
    void girar(int grados);

    int mirarFrente();
};

#endif

