#include <Arduino.h>

class DistSense {
    private:
        int ECHO, TRIG;
    public:
		DistSense(int ECHO, int TRIG);
        void reset();
        int distance();
};