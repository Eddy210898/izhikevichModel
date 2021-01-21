#include "izhikevichModel.h"
#include "izhikevichStep.h"
float *izhikevichModel(float vO, float uO, float dT, izhikevichParams params, int start = 0, int stop = 2000, float I = 0)
{
    int t = stop - start;
    float *vMatrix = new float[t];
    vMatrix[0] = vO;
    for (int i = 1; i < t; i++)
    {
        pair<float, float> p = izhikevichStep(vMatrix[i - 1], uO, i, dT, params, I);
        vMatrix[i] = p.first;
        uO = p.second;
    }
    return vMatrix;
}