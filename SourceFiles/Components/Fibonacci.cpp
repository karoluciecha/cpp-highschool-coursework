#include <iostream>
#include <cstdlib>

using namespace std;

unsigned int fibonacciIteratively(int n)
{
    if (n == 0) return 0;

    unsigned int a = 0, b = 1;

    for (int i = 0; i < (n - 1); i++)
    {
        swap(a, b);
        b += a;
    }
    return b;
}

void runFibonacciProgram()
{
    int n;
    cout << "Enter the Fibonacci sequence term to calculate: ";
    cin >> n;

    cout << "Result: " << fibonacciIteratively(n) << endl;
}