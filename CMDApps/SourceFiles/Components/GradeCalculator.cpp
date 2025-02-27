#include <fstream>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Function to convert character digits to integer values
int convertToNumber(char c) {
    return c - '0'; // Converts '1'-'6' to 1-6
}

// Function to process '+' or '-' modifiers in grades
float calculateFraction(const string& line, float* fractionAdjustment) {
    if (line.find("+") != string::npos) {
        *fractionAdjustment += convertToNumber(line.back()) * 0.25f;
    }
    else if (line.find("-") != string::npos) {
        *fractionAdjustment += convertToNumber(line.back()) * -0.25f;
    }
    return *fractionAdjustment;
}

// Function to process the weight of a grade
void processGradeWeight(char gradeChar, char weightChar, vector<int>* grades, int* totalGrades) {
    int grade = convertToNumber(gradeChar);
    int weight = convertToNumber(weightChar);

    for (int i = 0; i < weight; i++) {
        grades->push_back(grade);
        (*totalGrades)++;  // Increment through pointer
    }
}

void runGradeCalculatorProgram() {
    vector<int> grades;  // Stores grades after conversion
    int totalGrades = 0;
    float totalSum = 0;
    float fractionAdjustment = 0;
    string line;

    cout << "=============================================\n";
    cout << "  Welcome to the Grade Average Calculator!  \n";
    cout << "=============================================\n\n";

    cout << "This program reads grades from a file and calculates the weighted average.\n";
    cout << "The current input file name is: SourceFiles/ResourceFiles/grades.txt\n";
    cout << "Each line in the file should contain a grade (1-6) and its weight (1-5) separated by a space.\n";
    cout << "Example file content:\n";
    cout << "----------------------\n";
    cout << "5 2  (Grade 5 with weight 2)\n";
    cout << "4+ 3 (Grade 4+ with weight 3, '+' increases by 0.25)\n";
    cout << "3- 1 (Grade 3- with weight 1, '-' decreases by 0.25)\n";
    cout << "----------------------\n\n";

    ifstream file("SourceFiles/ResourceFiles/grades.txt");

    system("pause");

    // Check if file opens successfully
    if (!file.is_open()) {
        cout << "Error: Unable to open 'SourceFiles/ResourceFiles/grades.txt'. Please ensure the file exists in the program directory.\n";
        return;
    }

    cout << "\nReading grades from 'SourceFiles/ResourceFiles/grades.txt'...\n";

    // Read each line from the file
    while (getline(file, line)) {
        if (line.empty()) continue; // Ignore empty lines

        char grade = line.front(); // First character is the grade
        char weight = line.back(); // Last character is the weight

        calculateFraction(line, &fractionAdjustment);
        processGradeWeight(grade, weight, &grades, &totalGrades);
    }

    file.close();

    // Calculate the weighted average
    for (int grade : grades) {
        totalSum += grade;
    }

    float average = (totalSum + fractionAdjustment) / totalGrades;

    cout << "\n=============================================\n";
    cout << "           Calculation Results\n";
    cout << "=============================================\n";
    cout << "Fraction adjustments applied: " << fractionAdjustment << endl;
    cout << "Final weighted average: " << average << "\n";
    cout << "=============================================\n\n";
}