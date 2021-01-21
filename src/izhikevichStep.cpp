#include "izhikevichStep.h"

pair<float, float> izhikevichStep(float vO, float uO, float t, float dT, izhikevichParams &params, float I = 0)
{
    if (vO >= 30)
    {
        vO = params.getC();
        uO = uO + params.getD();
        return make_pair(vO, uO);
    }
    float arg[] = {
        params.getA(), //0
        params.getB(), //1
        params.getC(), //2
        params.getD(), //3
        vO,            //4
        uO,            //5
        I              //6

    };
    float v = getNextRungeKuta(
        t, vO, dT, [](float t, float v, float args[]) {
            float fE = 0.04 * v * v;
            float sE = 5 * v;
            return fE + sE + 140 - args[5] + args[6];
        },
        arg);

    float u = getNextRungeKuta(
        t, uO, dT, [](float t, float u, float args[]) {
            float fE = args[1] * args[4];
            float sE = fE - u;
            return args[0] * sE;
        },
        arg);
    return make_pair(v, u);
}