#include <Arduino.h>

class tcs3200 {
    private:
        int PIN_S0, PIN_S1, PIN_S2, PIN_S3, PIN_OUTPUT;
    public:
		tcs3200(int s0, int s1, int s2, int s3, int output);
        void scale(int scale);
        int read_red();
        int read_green();
        int read_blue();
        int read_white();
};