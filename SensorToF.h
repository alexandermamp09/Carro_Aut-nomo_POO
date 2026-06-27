
#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_VL53L0X.h>

#define NUM_SENSORS 5

class ToFArray {

  private:

    Adafruit_VL53L0X sensors[NUM_SENSORS];

    uint8_t addresses[NUM_SENSORS] = {0x30, 0x31, 0x32, 0x33, 0x34};

    uint8_t pinsXshut[NUM_SENSORS];

  public:

    ToFArray(uint8_t xshutPins[NUM_SENSORS]);

    void begin();

    int read(int index);

    void readAll(int distances[NUM_SENSORS]);
};

#endif
