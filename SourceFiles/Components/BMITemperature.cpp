#include <iostream>
#include <fstream>

using namespace std;

float weight = 0, height = 0, bmi = 0;
float tempC = 0, tempF = 0;
int choice = 0;

void bmiCalculation() {
    float a, b, calculatedBmi;
    ifstream inputFile("../ResourceFiles/bmi.txt");
    ofstream outputFile("../ResourceFiles/bmi.html");
    
    if (!inputFile) {
        cout << "Cannot open the file.\n";
    } else {
        cout << "BMI calculations from file:\n";
        outputFile << "<!DOCTYPE html>\n<html>\n<head>\n<meta charset='UTF-8'>\n";
        outputFile << "<title>BMI Results</title>\n</head>\n<body>\n";
        outputFile << "<h1>BMI Calculation Results</h1>\n<table border='1'>\n<tr><th>Weight (kg)</th><th>Height (cm)</th><th>BMI</th></tr>\n";
        
        while (inputFile >> a >> b) {
            b /= 100; // Convert cm to meters
            calculatedBmi = a / (b * b);
            cout << "Weight: " << a << " kg, Height: " << (b * 100) << " cm, BMI: " << calculatedBmi << endl;
            outputFile << "<tr><td>" << a << "</td><td>" << (b * 100) << "</td><td>" << calculatedBmi << "</td></tr>\n";
        }
        
        inputFile.close();
    }
    
    while (true) {
        cout << "Do you want to calculate another BMI? (Y/N): ";
        char userChoice;
        cin >> userChoice;
        if (userChoice != 'Y' && userChoice != 'y') break;
        
        cout << "\nEnter your weight (kg): ";
        cin >> weight;
        cout << "Enter your height (cm): ";
        cin >> height;
        height /= 100; // Convert cm to meters
        bmi = weight / (height * height);
        
        cout << "\nYour BMI is: " << bmi << endl;
        
        ofstream appendFile("bmi.txt", ios::app);
        appendFile << weight << " " << height * 100 << endl;
        appendFile.close();
        
        outputFile << "<tr><td>" << weight << "</td><td>" << height * 100 << "</td><td>" << bmi << "</td></tr>\n";
    }
    
    outputFile << "</table>\n</body>\n</html>\n";
    outputFile.close();
    
    cout << "BMI results have been saved to bmi.html\n";
}

void temperatureConversion() {
    cout << "\nEnter temperature in degrees Celsius: ";
    cin >> tempC;
    tempF = ((tempC * 9) / 5) + 32;
    cout << "\nThe entered temperature is " << tempF << " degrees Fahrenheit.\n";
}

void runBMITemperatureProgram() {
    while (true) {
        cout << "\n1. BMI Calculation\n";
        cout << "2. Temperature Conversion\n";
        cout << "3. Exit\n";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                bmiCalculation();
                break;
            case 2:
                temperatureConversion();
                break;
            case 3:
                cout << "\nExiting program...\n";
                return;
            default:
                cout << "Invalid choice. Please enter a valid number.\n";
                break;
        }
    }
}