#include <iostream>
#include <limits> // For input validation

using namespace std;

// Function to validate user input
int getValidNumber() {
    int num;
    while (true) {
        cout << "Enter a number: ";
        cin >> num;

        if (cin.fail()) {  // If input is invalid (not an integer)
            cin.clear();  // Clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Ignore invalid input
            cout << "Invalid input! Please enter a valid integer.\n";
        } else {
            return num;
        }
    }
}

// Function to check if a number is even or odd
void checkEvenOdd(int num) {
    if (num % 2 == 0)
        cout << "\nThe number " << num << " is even.\n";
    else
        cout << "\nThe number " << num << " is odd.\n";
}

void runEvenOddProgram() {
    cout << "Even or Odd Number Checker\n\n";

    int l = getValidNumber();  // Get a valid number from user
    checkEvenOdd(l);  // Check and display result
}