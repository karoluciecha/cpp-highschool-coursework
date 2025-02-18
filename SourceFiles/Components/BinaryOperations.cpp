#include <iostream>
#include <fstream>
#include <string>

using namespace std;

char choice;

void binaryToDecimalRight() {
    ofstream output("results.txt", ios_base::app);
    int bin, decimal = 0, weight = 128;
    output << "Binary number: ";
    while (weight >= 1) {
        cout << "Enter 0 or 1: ";
        cin >> bin;
        if (bin == 1) {
            decimal += weight;
        }
        weight /= 2;
        output << bin;
    }
    cout << "Result: " << decimal << "\n\n";
    output << " equals " << decimal << " in decimal.\n\n";
    output.close();
}

void binaryToDecimalLeft() {
    ofstream output("results.txt", ios_base::app);
    int bin, decimal = 0, weight = 1;
    int binaryArray[8], index = 7;
    while (weight <= 128) {
        cout << "Enter 0 or 1: ";
        cin >> bin;
        if (bin == 1) {
            decimal += weight;
        }
        weight *= 2;
        binaryArray[index] = bin;
        index--;
    }
    cout << "Result: " << decimal << "\n\n";
    output << "Binary number: ";
    for (int i = 0; i < 8; i++) {
        output << binaryArray[i];
    }
    output << " equals " << decimal << " in decimal.\n\n";
    output.close();
}

void binaryIPAddress() {
    ofstream output("results.txt", ios_base::app);
    int bin, weight = 128, segment = 0;
    string ipAddress;
    output << "Binary IP address: ";
    for (int i = 1; i <= 4; i++) {
        cout << "Enter " << i << "th octet:" << endl;
        while (weight >= 1) {
            cout << "0 or 1: ";
            cin >> bin;
            if (bin == 1) {
                segment += weight;
            }
            weight /= 2;
            output << bin;
        }
        ipAddress += to_string(segment);
        if (i < 4) {
            ipAddress += ".";
            output << ".";
        }
        weight = 128;
        segment = 0;
    }
    cout << "Result: " << ipAddress << "\n\n";
    output << " equals " << ipAddress << " in decimal.\n\n";
    output.close();
}

void bitReversal() {
    int base = 65536, bin[17], i = 16, j = 0;
    long long inputDec = 0, reversedDec = 0;
    ofstream output("results.txt", ios_base::app);
    cout << "Enter a positive decimal number: ";
    cin >> inputDec;
    while (inputDec < 0) {
        cout << "Error. Number must be non-negative. Try again: ";
        cin >> inputDec;
    }
    output << "Decimal number: " << inputDec << " in binary: ";
    while (inputDec < base) {
        base /= 2;
        i--;
    }
    while (i >= 0) {
        if (inputDec >= base) {
            bin[i] = 1;
            inputDec -= base;
        } else {
            bin[i] = 0;
        }
        base /= 2;
        i--;
        j++;
    }
    j--;
    base = 1;
    for (int f = 0; f < j; f++) base *= 2;
    for (int f = 0; f <= j; f++) {
        if (bin[f] == 1) {
            reversedDec += base;
        }
        base /= 2;
    }
    for (int f = j; f >= 0; f--) output << bin[f];
    output << "\nReversed binary value: " << reversedDec << " in binary: ";
    for (int f = 0; f <= j; f++) output << bin[f];
    output << "\n\n";
    cout << "Result: " << reversedDec << "\n\n";
    output.close();
}

void runBinaryOperationsProgram() {
    ofstream output("results.txt", ios_base::trunc);
    char choice;

    do {
        cout << ":: Main Menu" << endl;
        cout << "=======================================" << endl;
        cout << "1. Binary to Decimal (Right) (P/p)" << endl;
        cout << "2. Binary to Decimal (Left) (L/l)" << endl;
        cout << "3. Binary IP Address to Decimal (I/i)" << endl;
        cout << "4. Bit Reversal (B/b)" << endl;
        cout << "5. Exit (X/x)" << endl;
        cout << "=======================================" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 'P': case 'p':
                binaryToDecimalRight();
                break;
            case 'L': case 'l':
                binaryToDecimalLeft();
                break;
            case 'I': case 'i':
                binaryIPAddress();
                break;
            case 'B': case 'b':
                bitReversal();
                break;
            case 'X': case 'x':
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice. Please enter a valid option.\n";
                break;
        }
    } while (choice != 'X' && choice != 'x');
    
    output.close();
    return;
}