#include <iostream>

using namespace std;

// Declarations of functions from individual modules
void displayMainMenu();
void runMathPrograms();
void runGeometryPrograms();
void runConversionPrograms();
void runGamePrograms();
void runUtilityPrograms();
void runCosineProgram();
void runBinaryConversionProgram();
void runEuclidProgram();
void runFibonacciProgram();
void runRecursionProgram();
void runPrimeNumberProgram();
void runRecurvieExponentiationProgram();
void runHexadecimalConversionProgram();
void runDivisorsProgram();
void runPointersChangeCalculator();
void runGenderBasedGreetingProgram();
void runEvenOddProgram();
void runRectangleAreaProgram();
void runRectangleDrawProgram();
void runTriangleTestProgram();
void runBattleShipProgram();
void runBMITemperatureProgram();
void runCalculationsProgram();
void runChocolateShareProgram();
void runGradeCalculatorProgram();
void runMoneyChangerProgram();
void runNumberSorterProgram();
void runSubsetSumSortProgram();
void runWordModificationsProgram();
void runWordTransformationsProgram();
void runBinaryOperationsProgram();
void runDataOperationsProgram();
void runDataTypesProgram();
void runLongestIncreasingSubsequenceProgram();

int main() {
	int choice;

	do {
		displayMainMenu();
		cin >> choice;
		system("CLS");

		switch (choice) {
		case 1:
			runMathPrograms();
			break;
		case 2:
			runGeometryPrograms();
			break;
		case 3:
			runConversionPrograms();
			break;
		case 4:
			runGamePrograms();
			break;
		case 5:
			runUtilityPrograms();
			break;
		case 0:
			cout << "Program terminated." << endl;
			break;
		default:
			cout << "Invalid choice. Please try again." << endl;
			break;
		}
	} while (choice != 0);
	return 0;
}

void displayMainMenu() {
	cout << "==== MAIN MENU ====" << endl;
	cout << "1. Mathematical Calculations" << endl;
	cout << "2. Geometry & Shapes" << endl;
	cout << "3. Conversions" << endl;
	cout << "4. Games & Fun" << endl;
	cout << "5. Miscellaneous Utilities" << endl;
	cout << "0. Exit" << endl;
	cout << "Select a category: ";
}

void runMathPrograms() {
	int choice;
	do {
		cout << "==== MATHEMATICAL CALCULATIONS ====" << endl;
		cout << "1. Cosine Calculation" << endl;
		cout << "2. GCD (Euclid's Algorithm)" << endl;
		cout << "3. Fibonacci Sequence" << endl;
		cout << "4. Factorial Calculation" << endl;
		cout << "5. Prime Number Check" << endl;
		cout << "6. Exponentiation" << endl;
		cout << "7. Divisors Calculation" << endl;
		cout << "8. Weighted Grade Calculation" << endl;
		cout << "9. Sorting Numbers" << endl;
		cout << "10. Subset Sum Check" << endl;
		cout << "11. Longest Increasing Subsequence" << endl;
		cout << "0. Back to Main Menu" << endl;
		cout << "Select an option: ";
		cin >> choice;

		switch (choice) {
		case 1:
			system("CLS");
			runCosineProgram();
			system("PAUSE");
			system("CLS");
			break;
		case 2:
			system("CLS");
			runEuclidProgram();
			system("PAUSE");
			system("CLS");
			break;
		case 3:
			system("CLS");
			runFibonacciProgram();
			system("PAUSE");
			system("CLS");
			break;
		case 4:
			system("CLS");
			runRecursionProgram();
			system("PAUSE");
			system("CLS");
			break;
		case 5:
			system("CLS");
			runPrimeNumberProgram();
			system("PAUSE");
			system("CLS");
			break;
		case 6:
			system("CLS");
			runRecurvieExponentiationProgram();
			system("PAUSE");
			system("CLS");
			break;
		case 7:
			system("CLS");
			runDivisorsProgram();
			system("PAUSE");
			system("CLS");
			break;
		case 8:
			system("CLS");
			runGradeCalculatorProgram();
			system("PAUSE");
			system("CLS");
			break;
		case 9:
			system("CLS");
			runNumberSorterProgram();
			system("PAUSE");
			system("CLS");
			break;
		case 10:
			system("CLS");
			runSubsetSumSortProgram();
			system("PAUSE");
			system("CLS");
			break;
		case 11:
			system("CLS");
			runLongestIncreasingSubsequenceProgram();
			system("PAUSE");
			system("CLS");
			break;
		case 0:
			system("CLS");
			return;
		default:
			cout << "Invalid choice. Please try again." << endl;
			break;
		}
	} while (choice != 0);
}

void runGeometryPrograms() {
	int choice;
	do {
		cout << "==== GEOMETRY & SHAPES ====" << endl;
		cout << "1. Rectangle Area Calculation" << endl;
		cout << "2. Rectangle Drawing" << endl;
		cout << "3. Triangle Validity Check" << endl;
		cout << "0. Back to Main Menu" << endl;
		cout << "Select an option: ";
		cin >> choice;

		switch (choice) {
		case 1:
			system("CLS");
			runRectangleAreaProgram();
			system("PAUSE");
			system("CLS");
			break;
		case 2:
			system("CLS");
			runRectangleDrawProgram();
			system("PAUSE");
			system("CLS");
			break;
		case 3:
			system("CLS");
			runTriangleTestProgram();
			system("PAUSE");
			system("CLS");
			break;
		case 0:
			system("CLS");
			return;
		default:
			cout << "Invalid choice. Please try again." << endl;
			break;
		}
	} while (choice != 0);
}

void runConversionPrograms() {
	int choice;
	do {
		cout << "==== CONVERSIONS ====" << endl;
		cout << "1. Binary Number Conversion" << endl;
		cout << "2. Hexadecimal Conversion" << endl;
		cout << "3. BMI & Temperature Conversion" << endl;
		cout << "0. Back to Main Menu" << endl;
		cout << "Select an option: ";
		cin >> choice;

		switch (choice) {
		case 1:
			system("CLS");
			runBinaryConversionProgram();
			system("PAUSE");
			system("CLS");
			break;
		case 2:
			system("CLS");
			runHexadecimalConversionProgram();
			system("PAUSE");
			system("CLS");
			break;
		case 3:
			system("CLS");
			runBMITemperatureProgram();
			system("PAUSE");
			system("CLS");
			break;
		case 0:
			system("CLS");
			return;
		default:
			cout << "Invalid choice. Please try again." << endl;
			break;
		}
	} while (choice != 0);
}

void runGamePrograms() {
	int choice;
	do {
		cout << "==== GAMES & FUN ====" << endl;
		cout << "1. Battleship Game" << endl;
		cout << "2. Chocolate Bar Division" << endl;
		cout << "3. Word Transformations" << endl;
		cout << "4. Word Modifications" << endl;
		cout << "5. Change Calculation" << endl;
		cout << "0. Back to Main Menu" << endl;
		cout << "Select an option: ";
		cin >> choice;

		switch (choice) {
		case 1:
			system("CLS");
			runBattleShipProgram();
			system("PAUSE");
			system("CLS");
			break;
		case 2:
			system("CLS");
			runChocolateShareProgram();
			system("PAUSE");
			system("CLS");
			break;
		case 3:
			system("CLS");
			runWordTransformationsProgram();
			system("PAUSE");
			system("CLS");
			break;
		case 4:
			system("CLS");
			runWordModificationsProgram();
			system("PAUSE");
			system("CLS");
			break;
		case 5:
			system("CLS");
			runMoneyChangerProgram();
			system("PAUSE");
			system("CLS");
			break;
		case 0:
			system("CLS");
			return;
		default:
			cout << "Invalid choice. Please try again." << endl;
			break;
		}
	} while (choice != 0);
}

void runUtilityPrograms() {
	int choice;
	do {
		cout << "==== MISCELLANEOUS UTILITIES ====" << endl;
		cout << "1. Gender-Based Greeting" << endl;
		cout << "2. Even or Odd Check" << endl;
		cout << "3. Pointers Money Changer" << endl;
		cout << "4. Binary Operations" << endl;
		cout << "5. Data Operations" << endl;
		cout << "6. Data Types" << endl;
		cout << "7. Various Calculations" << endl;
		cout << "0. Back to Main Menu" << endl;
		cout << "Select an option: ";
		cin >> choice;

		switch (choice) {
		case 1:
			system("CLS");
			runGenderBasedGreetingProgram();
			system("PAUSE");
			system("CLS");
			break;
		case 2:
			system("CLS");
			runEvenOddProgram();
			system("PAUSE");
			system("CLS");
			break;
		case 3:
			system("CLS");
			runPointersChangeCalculator();
			system("PAUSE");
			system("CLS");
			break;
		case 4:
			system("CLS");
			runBinaryOperationsProgram();
			system("PAUSE");
			system("CLS");
			break;
		case 5:
			system("CLS");
			runDataOperationsProgram();
			system("PAUSE");
			system("CLS");
			break;
		case 6:
			system("CLS");
			runDataTypesProgram();
			system("PAUSE");
			system("CLS");
			break;
		case 7:
			system("CLS");
			runCalculationsProgram();
			system("PAUSE");
			system("CLS");
			break;
		case 0:
			system("CLS");
			return;
		default:
			cout << "Invalid choice. Please try again." << endl;
			break;
		}
	} while (choice != 0);
}