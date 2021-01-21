#include <iostream>
#include <fstream>
#include <vector>
#include "src/izhikevichModel.h"
#include "src/izhikevichParams.h"

using namespace std;

int main(int argc, char *argv[])
{
    izhikevichParams params;
    params.a = 0.1;
    cout << params.getA() << "\t" << params.getB() << "\t" << params.getC() << "\t" << params.getD() << endl;
    float vO = -65;
    float uO = vO * params.getB();
    vector<float> p = izhikevichModel(vO, uO, 0.1, params, 1, 1000, 4);

    fstream exampleSimulation;
    exampleSimulation.open("example.txt", ios::out);
    if (!exampleSimulation)
    {
        throw "File not created!";
    }
    else
    {
        int n = p.size();
        cout << "File created successfully!";
        float count = 1;
        for (auto i = p.begin(); i != p.end(); ++i)
        {
            exampleSimulation << *i << "\t" << count << endl;
            count = count + 0.1;
        }
        exampleSimulation.close();
    }
}