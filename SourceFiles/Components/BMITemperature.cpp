#include <iostream>
#include <windows.h>

using namespace std;

float weight = 0, height = 0, bmi = 0;
float tempC = 0, tempF = 0;
int choice = 0;

void bmiCalculation() {
    cout << "\nEnter your weight (kg): ";
    cin >> weight;
    cout << "Enter your height (cm): ";
    cin >> height;
    height = height / 100; // Convert cm to meters
    bmi = weight / (height * height);

    cout << "\nYour BMI is: " << bmi << endl;
    if (bmi < 18.5) {
        cout << "Your BMI is too low.\n";
    } else if (bmi >= 18.5 && bmi < 25) {
        cout << "Your BMI is normal.\n";
    } else {
        cout << "Your BMI is too high.\n";
    }
    cout << "\n-------------------------------------------------\n";
    system("pause");
    system("cls"); // Clear screen after displaying results
}

void temperatureConversion() {
    cout << "\nEnter temperature in degrees Celsius: ";
    cin >> tempC;
    tempF = ((tempC * 9) / 5) + 32;
    cout << "\nThe entered temperature is " << tempF << " degrees Fahrenheit.\n";
    cout << "\n-------------------------------------------------\n";
    system("pause");
    system("cls"); // Clear screen after displaying results
}

void runBMITemperatureProgram() {
    while (true) {
        cout << "\n1. BMI Calculation Program\n";
        cout << "2. Temperature Conversion Program\n";
        cout << "3. Exit the program\n\n";
        cout << "Enter the corresponding number to start the selected program: ";
        cin >> choice;

        switch (choice) {
            case 1:
                system("cls"); // Clear screen before displaying results
                bmiCalculation();
                break;
            case 2:
                system("cls"); // Clear screen before displaying results
                temperatureConversion();
                break;
            case 3:
                cout << "\nExiting program...\n";
                return;
            default:
                cout << "Invalid number entered. Please enter a valid number.\n";
                system("pause");
                system("cls");
                break;
        }
    }
}