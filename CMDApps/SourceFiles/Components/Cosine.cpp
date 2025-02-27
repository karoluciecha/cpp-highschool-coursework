#include <iostream>
#include <iomanip>
#include <cmath>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

using namespace std;

void runCosineProgram() {
    double st = 0.0, rad, cos_wartosc;

    do {
        rad = st * M_PI / 180; // Convert degrees to radians
        cos_wartosc = cos(rad); // Calculate the cosine value
        cout << "cos(" << fixed << setprecision(0) << st << ") = "
            << setprecision(4) << cos_wartosc << endl;
        st += 10.0;
    } while (cos_wartosc >= 0.1);
}