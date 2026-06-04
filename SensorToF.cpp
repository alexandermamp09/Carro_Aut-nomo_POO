#include SensorToF.h

SensorToF: :SensorToF(int xshut) {
    pinXshut = xshut;   
}

bool SensorToF: :inicializar() {
    pinMode(pinXshut, OUTPUT);
    digitalWrite(pinXshut, HIGH); 
    delay(10); 
    return lox.begin();
}

int SensorToF: :inicializar() {
    piMode(pinXshut, OUTPUT);
    digitalWrite(pinXshut, HIGH);
    delay(10);
    return lox.begin();
}

int SensorToF: :obtenerDistancia() {
    VL53L0X_RangingMeasurementData_t measure;
    lox.rangingTest(&measure, false); 
    if (measure.RangeStatus != 4) { 
        return measure.RangeMilliMeter;
    } else {
        return -1; 
    }
}
//lito :b