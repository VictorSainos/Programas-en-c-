#include <iostream>
#include <cmath>
#include <random>

using namespace std;

random_device rd;
mt19937 genMT19937(rd());
uniform_real_distribution<double> U01{0.0, 1.0};

double Uniforme()
{
    return U01(genMT19937);
}


int Dado()
{
    return ceil(6*Uniforme());
}

int main()
{
    int i,n = 10;
    for(i=0; i<n; i++)
        cout << Dado() << endl;
}
//<>
