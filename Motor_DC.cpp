#include Motor_DC.h

MotorDC: :MotorDC(int in1, int in2, int pwm, int canal) {
    pinIN1 = in1; pinIN2 = in2; pinPWM = pwm; canalPWM = canal;
}

void MotorDC: :inicializar() {
    pinMode(pinIN1, OUTPUT);
    pinMode(pinIN2, OUTPUT);
    pinMode(pinPWM, OUTPUT);
    ledcSetup(canalPWM, 5000, 8); 
    ledcAttachPin(pinPWM, canalPWM); 
}

void MotorDC: :setVelocidad(int velocidad) {
    ledcWrite(canalPWM, velocidad);
}
