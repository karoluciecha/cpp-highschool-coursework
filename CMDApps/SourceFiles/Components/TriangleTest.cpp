#include <iostream>

using namespace std;

// Function to check if a triangle can be formed
bool isTriangle(float a, float b, float c) {
    return (a + b > c && a + c > b && b + c > a);
}

// Function to validate user input
float getValidSide(string sideName) {
    float value;
    while (true) {
        cout << "Enter " << sideName << ": ";
        cin >> value;

        if (cin.fail() || value <= 0) {  // Check for invalid input or non-positive values
            cin.clear();  // Clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Ignore invalid input
            cout << "Invalid input! Please enter a positive number.\n";
        } else {
            return value;
        }
    }
}

void runTriangleTestProgram() {
    cout << "Checking the conditions for the existence of a triangle\n\n";

    // Get valid inputs
    float a = getValidSide("side a");
    float b = getValidSide("side b");
    float c = getValidSide("side c");

    // Check and display the result
    if (isTriangle(a, b, c)) {
        cout << "\nA triangle can be formed with sides (" << a << ", " << b << ", " << c << ").\n";
    } else {
        cout << "\nA triangle cannot be formed with these sides!\n";
        cout << "The sum of any two sides must be greater than the third.\n";
    }
}