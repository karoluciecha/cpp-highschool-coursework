#include <iostream>
#include <cmath>

using namespace std;

int n, z = 0;

bool method1(int n);
bool method2(int n);
bool method3(int n);

void resetIterations() {
    z = 0;
}

void runPrimeNumberProgram()
{
    cout << "Efficiency of the prime number determination algorithm" << endl << endl;
    cout << "0 for iteration count means that the for loop was not used." << endl << endl;
    cout << "Enter a number to check if it's prime: ";

    while ((cin >> n) && n <= 1)
    {
        if (n <= 1) {
            cout << endl << "The number must be greater than 1!" << endl;
            cout << "Enter a number to check if it's prime: ";
            continue;
        }
    }
    resetIterations();
    cout << "Method 1: ";
    if (method1(n)) {
        cout << "The number " << n << " is prime. Iteration count: " << z << "." << endl;
    }
    else {
        cout << "The number " << n << " is not prime. Iteration count: " << z << "." << endl;
    }

    resetIterations();
    cout << "Method 2: ";
    if (method2(n)) {
        cout << "The number " << n << " is prime. Iteration count: " << z << "." << endl;
    }
    else {
        cout << "The number " << n << " is not prime. Iteration count: " << z << "." << endl;
    }

    resetIterations();
    cout << "Method 3: ";
    if (method3(n)) {
        cout << "The number " << n << " is prime. Iteration count: " << z << "." << endl;
    }
    else {
        cout << "The number " << n << " is not prime. Iteration count: " << z << "." << endl;
    }
}

bool method1(int n) {
    if (n <= 1) return false;
    for (int i = 2; i <= sqrt(n); i++) {
        z++;
        if (n % i == 0) return false;
    }
    return true;
}

bool method2(int n) {
    if (n <= 1) return false;
    if (n > 2 && n % 2 == 0) return false;
    for (int i = 3; i <= sqrt(n); i += 2) {
        z++;
        if (n % i == 0) return false;
    }
    return true;
}

bool method3(int n) {
    if (n <= 1) return false;
    if (n > 2 && n % 2 == 0) return false;
    for (int i = 3; i <= sqrt(n); i += 2) {
        z++;
        if (n % i == 0) return false;
    }
    return true;
}