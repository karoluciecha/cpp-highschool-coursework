#include <iostream>
#include <iomanip>  // For std::fixed and std::setprecision

using namespace std;

// Function declaration to calculate the change
double change(double price, double cash);

void runPointersChangeCalculator()
{
    double price, cash;
    double (*changePointer)(double price, double cash) = &change;  // Pointer to function

    cout << "Welcome to our store!" << endl << endl;

    // Loop to read data
    while (true)
    {
        cout << "Enter the total value of purchases (0 to exit): ";
        if (!(cin >> price))  // Check if the price is valid
        {
            cout << "Invalid input. The program is terminating." << endl;
            break;
        }

        // Check if the price is greater than zero
        if (price < 0)
        {
            cout << "Price must be a positive number!" << endl;
            continue;
        }

        // Check if the price equals zero
        if (price == 0)
        {
            cout << "The program is terminating." << endl;
            break;
        }

        cout << "Enter the amount received from the customer: ";
        if (!(cin >> cash))  // Check if the cash amount is valid
        {
            cout << "Invalid input. The program is terminating." << endl;
            break;
        }

        // Check if the cash amount is greater than the price
        if (cash < price)
        {
            cout << "The amount received from the customer must be greater than the price!" << endl;
            continue;
        }

        // Display the change with two decimal places
        cout << "Change to be returned: " << fixed << setprecision(2) << changePointer(price, cash) << " zl." << endl << endl;
    }
}

// Function to calculate the change
double change(double price, double cash)
{
    return cash - price;
}
