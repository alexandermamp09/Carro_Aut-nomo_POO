#ifndef CARRO_H
#define CARRO_H

#include <Arduino.h>
//Llamo a las librerías para que el carro pueda existir jeje
#include "ServoDireccion.h"
#include "ToFArray.h"
//Falta la clase del MotorDC\\
class Carro {
 private:

  ServoDireccion &direccion;
  ToFArray &sensoresDistancia;
  int velocidadBase; 

 public:
  Carro(ServoDireccion &dir, ToFArray &xsens);

  void inicializarCarro();
  void conducirNormal();
  void esquivarObstaculos();
  };

  #endif

