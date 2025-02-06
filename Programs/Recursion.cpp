#include <iostream>

using namespace std;

// Function to calculate factorial recursively.
// For n == 0 it returns 1, otherwise it returns n * factorial(n-1).
unsigned long long factorialRecursive(unsigned long long n) {
    return n == 0 ? 1 : n * factorialRecursive(n - 1);
}

void runRecursionProgram() {
    cout << "Recursive Factorial" << endl << endl;

    unsigned long long k;
    cout << "Enter a number to calculate the factorial: ";
    cin >> k;

    // For n > 20, there may be an overflow of the unsigned long long type.
    if (k > 20) {
        cout << "Warning: For values above 20, the result may be incorrect due to overflow." << endl;
    }

    // Calculate and display the factorial for the given number.
    cout << k << "! = " << factorialRecursive(k) << endl << endl;

    // Display factorial values for all numbers from 0 to k.
    for (unsigned long long i = 0; i <= k; i++) {
        cout << i << "! = " << factorialRecursive(i) << endl;
    }
}