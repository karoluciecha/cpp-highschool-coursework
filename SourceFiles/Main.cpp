#include <iostream>

using namespace std;

// Declarations of functions from individual modules
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
		cout << "8. Program converting a number to hexadecimal form\n";
		cout << "9. Program calculating divisors\n";
		cout << "10. Program calculating change using pointers\n";
		cout << "11. Gender-Based Greeting Program\n";
		cout << "12. Program checking if a number is even or odd\n";
		cout << "13. Program calculating the area of a rectangle\n";
		cout << "14. Program drawing a rectangle\n";
		cout << "15. Program checking if a triangle can be formed\n";
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
            runBinaryConversionProgram();
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
		case 8:
			system("CLS");
			runHexadecimalConversionProgram();
			system("PAUSE");
			system("CLS");
			break;
        case 9:
			system("CLS");
			runDivisorsProgram();
			system("PAUSE");
			system("CLS");
			break;
		case 10:
			system("CLS");
			runPointersChangeCalculator();
			system("PAUSE");
			system("CLS");
			break;
		case 11:
			system("CLS");
			runGenderBasedGreetingProgram();
			system("PAUSE");
			system("CLS");
			break;
		case 12:
			system("CLS");
			runEvenOddProgram();
			system("PAUSE");
			system("CLS");
			break;
		case 13:
			system("CLS");
			runRectangleAreaProgram();
			system("PAUSE");
			system("CLS");
			break;
		case 14:
			system("CLS");
			runRectangleDrawProgram();
			system("PAUSE");
			system("CLS");
			break;
		case 15:
			system("CLS");
			runTriangleTestProgram();
			system("PAUSE");
			system("CLS");
			break;
        case 0:
            cout << "Program terminated.\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
			break;
        }
    } while (choice != 0);
    return 0;
}