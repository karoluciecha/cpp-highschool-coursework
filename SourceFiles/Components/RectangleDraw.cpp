#include <iostream>
#include <limits> // For input validation

using namespace std;

// Function to get a valid positive integer
int getValidDimension(string dimensionName) {
    int value;
    while (true) {
        cout << "Enter " << dimensionName << ": ";
        cin >> value;

        if (cin.fail() || value <= 0) {  // Check for invalid or non-positive values
            cin.clear();  // Clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Ignore invalid input
            cout << "Invalid input! Please enter a positive integer.\n";
        } else {
            return value;
        }
    }
}

// Function to draw a filled rectangle
void drawFilledRectangle(int width, int height) {
    cout << "\nFilled Rectangle:\n";
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            cout << "*";
        }
        cout << "\n";
    }
}

// Function to draw a hollow rectangle
void drawHollowRectangle(int width, int height) {
    cout << "\nHollow Rectangle:\n";
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (i == 0 || i == height - 1 || j == 0 || j == width - 1)
                cout << "*";
            else
                cout << " ";
        }
        cout << "\n";
    }
}

void runRectangleDrawProgram() {
    cout << "Rectangle Drawing Program\n\n";

    // Get valid rectangle dimensions
    int width = getValidDimension("width");
    int height = getValidDimension("height");

    // Draw the rectangles
    drawFilledRectangle(width, height);
    drawHollowRectangle(width, height);
}