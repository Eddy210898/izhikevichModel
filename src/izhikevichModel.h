#include <iostream>
#include "izhikevichStep.h"
using namespace std;
pair<float[], int[]> izhikevichModel(float vO, float uO, float t, float dT, izhikevichParams params, int start = 0, int stop = 2000, float I = 0);
