#include <iostream>
#include "izhikevichStep.h"
using namespace std;
vector<float> izhikevichModel(float vO, float uO, float dT, izhikevichParams params, int start = 0, int stop = 2000, float I = 0);
