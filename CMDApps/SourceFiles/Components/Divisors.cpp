#include <iostream>
#include <cmath> // Needed for sqrt>
#include <limits> // Needed for numeric_limits

using namespace std;

void runDivisorsProgram()
{
    int number;
    cout << "Enter a number to display its divisors (or enter 0 to exit): ";

    while (true) // Keep looping until a valid input is received
    {
        cin >> number;

        if (cin.fail()) // If user enters a non-numeric value
        {
            cin.clear(); // Clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            cout << "Invalid input. Please enter a valid number: ";
            continue; // Restart loop
        }

        if (number == 0)
        {
            cout << "Program terminated." << endl;
            break;
        }

        if (number < 0)
        {
            cout << "Please enter a positive number!" << endl;
            cout << "Enter a number to display its divisors (or enter 0 to exit): ";
            continue;
        }

        cout << "The divisors of " << number << " are: ";

        bool isPrime = (number > 1);
        bool firstDivisors = true; // Flag to format output correctly

        for (int i = 1; i <= sqrt(number); i++)
        {
            if (number % i == 0)
            {
                if (!firstDivisors) cout << ", ";
                cout << i;
                firstDivisors = false;

                int secondDivisor = number / i;
                if (secondDivisor != i) // Avoid duplicate output, e.g., for 36: 6 × 6
                {
                    cout << ", " << secondDivisor;
                }

                if (i != 1) isPrime = false; // If the number has a divisor other than 1 and itself, it's not prime
            }
        }

        cout << "." << endl;

        if (isPrime)
        {
            cout << number << " is a prime number." << endl;
        }

        cout << endl << "Enter a number to display its divisors (or enter 0 to exit): ";
    }
}