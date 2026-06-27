#include "ToFArray.h"

ToFArray::ToFArray(uint8_t xshutPins[NUM_SENSORS])
{
    for (int i = 0; i < NUM_SENSORS; i++) {
        pinsXshut[i] = xshutPins[i];
    }
}

void ToFArray::begin()
{
    Wire.begin();

    // apagar todos los sensores
    for (int i = 0; i < NUM_SENSORS; i++) {
        pinMode(pinsXshut[i], OUTPUT);
        digitalWrite(pinsXshut[i], LOW);
    }

    delay(10);

    // inicializar uno por uno
    for (int i = 0; i < NUM_SENSORS; i++) {

        digitalWrite(pinsXshut[i], HIGH);
        delay(10);

        if (!sensors[i].begin(addresses[i])) {
            Serial.print("Error ToF ");
            Serial.println(i);
        }

        sensors[i].setAddress(addresses[i]);
    }
}

int ToFArray::read(int index)
{
    VL53L0X_RangingMeasurementData_t measure;

    sensors[index].rangingTest(&measure, false);

    if (measure.RangeStatus != 4) {
        return measure.RangeMilliMeter;
    }

    return -1;
}

void ToFArray::readAll(int distances[NUM_SENSORS])
{
    for (int i = 0; i < NUM_SENSORS; i++) {
        distances[i] = read(i);
    }
}
//lito :b
