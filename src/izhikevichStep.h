#include <iostream>
#include "izhikevichParams.h"
#include "./../getNextRungeKuta/getNextRungeKuta.h"
using namespace std;
pair<float, float> izhikevichStep(float vO, float uO, float t, float dT, izhikevichParams &params, float I = 0);