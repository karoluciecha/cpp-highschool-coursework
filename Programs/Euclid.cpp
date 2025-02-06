#include <iostream>

using namespace std;

unsigned int EuclidR(unsigned int a, unsigned int b) {
    if (b == 0) return a;
    return EuclidR(b, a % b);
}

void runEuclidProgram() {
    unsigned int a, b;
    cout << "Euclid's Algorithm - Calculating GCD" << endl;
    cout << "a = ";
    cin >> a;
    cout << "b = ";
    cin >> b;
    cout << "GCD = " << EuclidR(a, b) << endl;
}