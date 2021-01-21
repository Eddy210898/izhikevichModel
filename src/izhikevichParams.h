#ifndef MYHEADEFILE_H
#define MYHEADEFILE_H

class izhikevichParams
{

public:
    float a = 0.02, b = 0.2, c = -65, d = 2;
    float getA();
    float getB();
    float getC();
    float getD();
};

#endif