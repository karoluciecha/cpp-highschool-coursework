#include <iostream>
using namespace std;

float result = 0;
int x = 0;
int y = 0;
long long factorialX = 1;
long long factorialY = 1;
long long sumOfFactorials = 0;
int sumOfSequenceY = 0;

void pointerFactorialX(int *x, long long *factorialX)
{
    for (int i = *x; i > 1; i--)
    {
        *factorialX *= i;
    }
    cout << *x << "! = " << *factorialX << endl;
}

void referenceFactorialY(int &y, long long &factorialY)
{
    for (int i = y; i > 1; i--)
    {
        factorialY *= i;
    }
    cout << y << "! = " << factorialY << endl;
}

void pointerSumFactorials(long long *factorialX, long long *factorialY, long long *sumOfFactorials)
{
    *sumOfFactorials = *factorialX + *factorialY;
    cout << "Sum of factorials X and Y: " << *sumOfFactorials << endl;
}

void referenceSumSequenceY(int &y, int &sumOfSequenceY)
{
    for (int i = y; i > 0; i--)
    {
        sumOfSequenceY += i;
    }
    cout << "Sum of sequence Y: " << sumOfSequenceY << endl;
}

void calculateResult(float &result, long long sumOfFactorials, int sumOfSequenceY)
{
    if (sumOfSequenceY == 0)
    {
        cout << "Cannot divide by zero. Result is undefined.\n";
        return;
    }
    result = static_cast<float>(sumOfFactorials) / sumOfSequenceY;
    cout << "Final result: " << result << endl << endl;
}

void runCalculationsProgram()
{
    cout << "Enter X: ";
    cin >> x;
    cout << "\nEnter Y: ";
    cin >> y;
    cout << endl;

    pointerFactorialX(&x, &factorialX);
    referenceFactorialY(y, factorialY);
    pointerSumFactorials(&factorialX, &factorialY, &sumOfFactorials);
    referenceSumSequenceY(y, sumOfSequenceY);
    calculateResult(result, sumOfFactorials, sumOfSequenceY);
}