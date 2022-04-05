#include <Arduino.h>

class LineSense {
    private:
        int PIN_IR1,PIN_IR2,PIN_IR3,PIN_IR4,PIN_IR5;
    public:
		LineSense(int ir1, int ir2, int ir3, int ir4, int ir5);
        int readIR1();
        int readIR2();
        int readIR3();
        int readIR4();
        int readIR5();
        int weighted_average();
        int distance();
};