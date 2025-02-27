#include <iostream>
#include <limits> // For input validation

using namespace std;

// Function to validate and get a positive number
double getValidSide(string sideName) {
    double value;
    while (true) {
        cout << "Enter the length of side " << sideName << ": ";
        cin >> value;

        if (cin.fail() || value <= 0) {  // Check for invalid or non-positive values
            cin.clear();  // Clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Ignore invalid input
            cout << "Invalid input! Please enter a positive number.\n";
        } else {
            return value;
        }
    }
}

// Function to calculate rectangle area
double calculateArea(double a, double b) {
    return a * b;
}

void runRectangleAreaProgram() {
    cout << "Rectangle Area Calculation\n\n";

    // Get valid inputs
    double a = getValidSide("a");
    double b = getValidSide("b");

    // Calculate and display the area
    double area = calculateArea(a, b);
    cout << "\nThe area of the rectangle is: " << area << "\n";
}