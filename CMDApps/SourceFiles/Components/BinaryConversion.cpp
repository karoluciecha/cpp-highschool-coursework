#include <iostream>
#include <limits>

using namespace std;

// Function that performs the conversion of a number to binary form
void konwersja(int liczba) {
    int i = 0, tab[64];

    // Special case when the number is 0
    if (liczba == 0) {
        cout << "0";
        return;
    }

    while (liczba) {
        tab[i++] = liczba % 2;
        liczba /= 2;
    }
    for (int r = i - 1; r >= 0; r--) {
        cout << tab[r];
    }
}

void runBinaryConversionProgram() {
    int liczba;
    cout << "Enter a number: ";
    // Loop that allows for multiple conversions until a non-number is entered
    while (cin >> liczba) {
        cout << "The entered number (" << liczba << ") is ";
        konwersja(liczba);
        cout << " after converting to binary form." << endl;
        cout << "Enter another number or any character to exit: ";
    }
    // Reset the input stream after incorrect input
    cin.clear();
    cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
}