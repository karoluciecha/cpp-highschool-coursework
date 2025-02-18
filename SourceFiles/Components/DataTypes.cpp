#include <iostream>
#include <fstream>

using namespace std;

void runDataTypesProgram()
{
    cout << "Data Type Sizes (in bytes):\n";
    cout << "Char: " << sizeof(char) << " bytes." << endl;
    cout << "Int: " << sizeof(int) << " bytes." << endl;
    cout << "Short int: " << sizeof(short int) << " bytes." << endl;
    cout << "Long int: " << sizeof(long int) << " bytes." << endl;
    cout << "Long long: " << sizeof(long long) << " bytes." << endl;
    cout << "Unsigned long int: " << sizeof(unsigned long int) << " bytes." << endl;
    cout << "Float: " << sizeof(float) << " bytes." << endl;
    cout << "Double: " << sizeof(double) << " bytes." << endl;
    cout << "Long double: " << sizeof(long double) << " bytes." << endl;
    cout << "String: " << sizeof(string) << " bytes." << endl;
    cout << "Boolean: " << sizeof(bool) << " bytes." << endl << endl;
    system("PAUSE");

    int octalValue, decimalValue, hexValue;
    octalValue = 024;
    decimalValue = 20;
    hexValue = 0x14;
    cout << "\nSum of given values for variables:" << endl;
    cout << "   Octal variable (024) = " << octalValue << endl;
    cout << "   Decimal variable (20) = " << decimalValue << endl;
    cout << "   Hexadecimal variable (0x14) = " << hexValue << endl;
    cout << "Total sum: " << octalValue + decimalValue + hexValue << "." << endl << endl;
    system("PAUSE");

    octalValue = 024;
    decimalValue = 20;
    hexValue = 0xFF;
    cout << "\nSum of new values for variables:" << endl;
    cout << "   Octal variable (024) = " << octalValue << endl;
    cout << "   Decimal variable (20) = " << decimalValue << endl;
    cout << "   Hexadecimal variable (0xFF) = " << hexValue << endl;
    cout << "Total sum: " << octalValue + decimalValue + hexValue << "." << endl << endl;
    system("PAUSE");

    cout << "\nText formatting examples:\n";
    cout << "Single-line text \n New line \b Backspace one character";
    cout << "\nText moved to a new line \n";
    cout << "\t Horizontal tab \n" << endl;
    system("PAUSE");

    char character;
    character = 'a';
    cout << "\nCharacter 'a' assigned directly: " << character << "." << endl;
    character = 97;
    cout << "Character 'a' assigned using ASCII value (97): " << character << "." << endl;
    character = 0141;
    cout << "Character 'a' assigned using octal (0141): " << character << "." << endl;
    character = 0x61;
    cout << "Character 'a' assigned using hexadecimal (0x61): " << character << "." << endl << endl;
    system("PAUSE");

    cout << "\nEscape character examples:\n";
    cout << "Backslash: \\ " << endl;
    cout << "Apostrophe: \' " << endl;
    cout << "Quotation mark: \" " << endl;
    cout << "Question mark: \? " << endl << endl;
    
    return;
}