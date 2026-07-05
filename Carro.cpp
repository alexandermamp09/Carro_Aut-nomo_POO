#include "Carro.h"

Carro::Carro(ServoDireccion &dir, ToFArray &sens) : direccion(dir), sensoresDistancia(sens) {
    velocidadBase = 100;
}

  void Carro::inicializarCarro() {
    direccion.inicializar();
    sensoresDistancia.begin();
    }

    void Carro::conducirNormal() {
      int distancias[5];
      
      sensoresDistancia.readAll(distancias);
      
      int sensExternoIzq  = distancias[1];
      int sensIzq         = distancias[2];
      int sensCentro      = distancias[3];
      int sensDere        = distancias[4];
      int sensExternoDere = distancias[5];
//---------------------------------\\ 
//#1    
        if (sensExternoIzq < 50){
          direccion.fijarAngulo(95);
        } else {
          direccion.centrar();
        }
//---------------------------------\\ 
//#2       
        if (sensIzq < 30){
          direccion.fijarAngulo(105);
        } else {
          direccion.centrar();
        }
//---------------------------------\\       
//#3    
        if (sensCentro < 200){
          direccion.fijarAngulo(120);
          delay(500);
          direccion.fijarAngulo(120);
          delay(500);
          direccion.fijarAngulo(120);
        } else {
          direccion.centrar();
        }
//---------------------------------\\ 
//#4
        if (sensDere < 30){
          direccion.fijarAngulo(25);
        } else {
          direccion.centrar();
        }
//---------------------------------\\ 
//#5   
        if (sensExternoDere < 50){
          direccion.fijarAngulo(35);
        } else {
          direccion.centrar();
        }
    }
//---------------------------------\\      
