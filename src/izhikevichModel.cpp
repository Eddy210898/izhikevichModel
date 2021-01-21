#include "izhikevichModel.h"
#include "izhikevichStep.h"
vector<float> izhikevichModel(float vO, float uO, float dT, izhikevichParams params, int start /*= 0*/, int stop /*= 2000*/, float I /*= 0*/)
{
    int t = stop - start;
    int steps = t / dT;
    vector<float> vMatrix;
    vMatrix.push_back(vO);
    for (int i = 1; i < steps; i++)
    {
        pair<float, float> p = izhikevichStep(vMatrix.at(i - 1), uO, i, dT, params, I);
        vMatrix.push_back(p.first);
        uO = p.second;
    }
    return vMatrix;
}