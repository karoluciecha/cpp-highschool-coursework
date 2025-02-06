#include <iostream>
#include <cstdlib>
#include <string>
#include <cmath>

using namespace std;

int hexdec(string hex);
string dechex(int dec);

void runHexadecimalConversionProgram()
{
    char typ;
    string l_hex;
    int l_dec;

    while (true) {
        cout << "Choose one of the options:\n";
        cout << "D/d - to convert a decimal number to hexadecimal.\n";
        cout << "H/h - to convert a hexadecimal number to decimal.\n";
        cout << "X/x - to exit the program.\n";
        cout << "Choice: ";
        cin >> typ;

        if (typ == 'x' || typ == 'X') {
            cout << "Closing the program...\n";
            break;
        }

        switch (typ)
        {
        case 'd':
        case 'D':
            cout << "Enter a decimal number: ";
            while (!(cin >> l_dec)) {
                cout << "Error: Please enter a valid integer.\n";
                cin.clear(); // Reset error flag
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer
                cout << "Try again: ";
            }
            cout << "The decimal number " << l_dec << " in hexadecimal is: " << dechex(l_dec) << endl;
            break;
        case 'h':
        case 'H':
            cout << "Enter a hexadecimal number: ";
            cin >> l_hex;
            // Check if the number is valid
            try {
                int dec = hexdec(l_hex);
                cout << "The hexadecimal number " << l_hex << " in decimal is: " << dec << endl;
            }
            catch (...) {
                cout << "Error: Please enter a valid hexadecimal number.\n";
            }
            break;
        default:
            cout << "Invalid choice, please try again.\n\n";
        }
    }
}

int hexdec(string hex)
{
    // Return conversion result while handling valid hexadecimal digits.
    for (char& c : hex) {
        if (!((c >= '0' && c <= '9') || (c >= 'A' && c <= 'F') || (c >= 'a' && c <= 'f'))) {
            throw invalid_argument("Error: Contains invalid characters.");
        }
    }
    return strtol(hex.c_str(), NULL, 16);
}

string dechex(int dec)
{
    // If the number is negative, we can add '0x' before the result
    if (dec < 0) return "Error: Number cannot be negative!";

    if (dec == 0) return "0";

    int i;
    string hex = "";
    char znaki[] = { '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F' };

    while (dec > 0)
    {
        i = dec % 16;
        hex = znaki[i] + hex;
        dec = dec / 16;
    }

    return hex;
}