#include <Arduino.h>

class MDriver {
    private:
        int PIN_IN1, PIN_IN2, PIN_IN3, PIN_IN4, PWM1, PWM2;
    public:
		MDriver(int in1, int in2, int in3, int in4, int pwm1, int pwm2);
        // A is left, B is 
        void move(int rightSpeed, int leftSpeed);
        void stop_a();
        void stop_b();
        void stop();
};