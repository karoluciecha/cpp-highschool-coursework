#include <iostream>
#include <cmath>

using namespace std;

bool method1(int n, int* z);
bool method2(int n, int* z);
bool method3(int n, int* z);

void resetIterations(int* z) {
    *z = 0;  // Dereference pointer to reset value
}

void runPrimeNumberProgram()
{
    int n, z = 0;
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

    resetIterations(&z);
    cout << "Method 1: ";
    if (method1(n, &z)) {
        cout << "The number " << n << " is prime. Iteration count: " << z << "." << endl;
    }
    else {
        cout << "The number " << n << " is not prime. Iteration count: " << z << "." << endl;
    }

    resetIterations(&z);
    cout << "Method 2: ";
    if (method2(n, &z)) {
        cout << "The number " << n << " is prime. Iteration count: " << z << "." << endl;
    }
    else {
        cout << "The number " << n << " is not prime. Iteration count: " << z << "." << endl;
    }

    resetIterations(&z);
    cout << "Method 3: ";
    if (method3(n, &z)) {
        cout << "The number " << n << " is prime. Iteration count: " << z << "." << endl;
    }
    else {
        cout << "The number " << n << " is not prime. Iteration count: " << z << "." << endl;
    }
}

bool method1(int n, int* z) {
    if (n <= 1) return false;
    for (int i = 2; i <= sqrt(n); i++) {
        (*z)++;  // Increment iteration counter using pointer
        if (n % i == 0) return false;
    }
    return true;
}

bool method2(int n, int* z) {
    if (n <= 1) return false;
    if (n > 2 && n % 2 == 0) return false;
    for (int i = 3; i <= sqrt(n); i += 2) {
        (*z)++;  // Increment iteration counter using pointer
        if (n % i == 0) return false;
    }
    return true;
}

bool method3(int n, int* z) {
    if (n <= 1) return false;
    if (n > 2 && n % 2 == 0) return false;
    for (int i = 3; i <= sqrt(n); i += 2) {
        (*z)++;  // Increment iteration counter using pointer
        if (n % i == 0) return false;
    }
    return true;
}