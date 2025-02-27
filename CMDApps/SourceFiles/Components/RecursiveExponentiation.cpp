#include <iostream>

using namespace std;

// Recursive power function.
// Calculates a^b for b >= 0.
long long power(long long a, long long b)
{
    // Base case of recursion: a^0 = 1
    if (b == 0)
        return 1;
    // When the exponent is 1, the result is just a.
    if (b == 1)
        return a;

    // Recursive call
    long long subResult = power(a, b - 1);

    return a * subResult;
}

void runRecurvieExponentiationProgram()
{
    cout << "Recursive Power Calculation" << endl << endl;

    long long a, b;

    cout << "Enter the base of the power: ";
    cin >> a;

    cout << "Enter the exponent (must be non-negative): ";
    while ((cin >> b) && b < 0) {
        // Check if the exponent is non-negative.
        // If the exponent is negative, the program will terminate with a message.
        cout << "Exponent cannot be negative." << endl;
		cout << "Enter the exponent (must be non-negative): ";
    }

    // Calculate the power and display the result.
    long long result = power(a, b);
    cout << "The result of the power calculation is: " << result << endl;
}