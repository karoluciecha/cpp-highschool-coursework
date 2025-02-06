#include <iostream>

using namespace std;

// Declarations of functions from individual modules
void runCosineProgram();
void runConversionProgram();
void runEuclidProgram();
void runFibonacciProgram();
void runRecursionProgram();
void runPrimeNumberProgram();
void runRecurvieExponentiationProgram();

int main() {
    int choice;
    do {
        cout << "==== MENU ====\n\n";
        cout << "1. Program calculating cosine\n";
        cout << "2. Program converting a number to binary form\n";
        cout << "3. Program calculating GCD (Euclid's algorithm)\n";
		cout << "4. Program calculating Fibonacci number\n";
		cout << "5. Program calculating factorial\n";
		cout << "6. Program checking if a number is prime\n";
		cout << "7. Program calculating exponentiation\n";
        cout << "0. Exit\n\n";
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
            runConversionProgram();
            system("CLS");
            break;
        case 3:
            system("CLS");
            runEuclidProgram();
            system("PAUSE");
            system("CLS");
            break;
        case 4:
			system("CLS");
			runFibonacciProgram();
			system("PAUSE");
			system("CLS");
			break;
        case 5:
			system("CLS");
			runRecursionProgram();
			system("PAUSE");
			system("CLS");
			break;
		case 6:
			system("CLS");
			runPrimeNumberProgram();
			system("PAUSE");
			system("CLS");
			break;
		case 7:
			system("CLS");
			runRecurvieExponentiationProgram();
			system("PAUSE");
			system("CLS");
			break;
        case 0:
            cout << "Program terminated.\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);
    return 0;
}