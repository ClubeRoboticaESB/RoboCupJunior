#include <Arduino.h>

class MDriver {
    private:
        int PIN_IN1, PIN_IN2, PIN_IN3, PIN_IN4;
    public:
		MDriver(int in1, int in2, int in3, int in4);
        // A is left, B is left
        void foward_a(int speed);
        void reverse_a(int speed);
        void foward_b(int speed);
        void reverse_b(int speed);
        void stop_a();
        void stop_b();
        void stop();
};