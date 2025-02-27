#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

char userChoice;
double amount = 0.0;

// Function to exchange money into available denominations
void exchangeMoney(double amount, const vector<double> &denominations) {
    vector<int> counts(denominations.size(), 0);
    
    // Convert amount to cents to avoid floating-point precision issues
    int amountCents = (int)round(amount * 100);
    
    for (size_t i = 0; i < denominations.size(); i++) {
        int denomCents = (int)round(denominations[i] * 100);
        
        while (amountCents >= denomCents) {
            counts[i]++;
            amountCents -= denomCents;
        }
    }

    // Display result
    cout << fixed << setprecision(2);
    cout << "\nThe amount of " << amount << " PLN can be exchanged into:\n";
    for (size_t i = 0; i < denominations.size(); i++) {
        if (counts[i] > 0) {
            cout << "- " << counts[i] << " x " << denominations[i] << " PLN\n";
        }
    }
    cout << "\n";
}

// Function to ask the user if they want to continue
void askUserToContinue() {
    cout << "\nWould you like to run the program again? (Y/N): ";
    cin >> userChoice;
}

void runMoneyChangerProgram() {
    // Denominations including fractional values
    vector<double> denominations = {200, 100, 50, 20, 10, 5, 2, 1, 0.50, 0.20, 0.10, 0.05, 0.02, 0.01};

    cout << "\nWelcome to the Money Changer Program!\n";

    do {
        cout << "\nEnter the amount to be exchanged: ";
        cin >> amount;

        if (amount <= 0) {
            cout << "Invalid amount. Please enter a positive number.\n";
            continue;
        }

        exchangeMoney(amount, denominations);
        askUserToContinue();

    } while (userChoice == 'Y' || userChoice == 'y');

    cout << "\nThank you for using the Money Changer Program! Goodbye.\n";
}