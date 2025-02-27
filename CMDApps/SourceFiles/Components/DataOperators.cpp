#include <iostream>
#include <fstream>

using namespace std;

void runDataOperationsProgram()
{
    int a, b;
    float c, d;
    
    cout << "Enter first integer (a): ";
    cin >> a;
    cout << "Enter second integer (b): ";
    cin >> b;
    cout << "Enter first float (c): ";
    cin >> c;
    cout << "Enter second float (d): ";
    cin >> d;
    
    cout << "\nint a / int b = " << a / b << endl;
    cout << "float c / int b = " << c / b << endl;
    cout << "int a % int b = " << a % b << endl << endl;

    float x;
    cout << "Enter a float value for x: ";
    cin >> x;
    cout << "x = " << x << endl;
    x += 50;
    cout << "x += 50 -> " << x << endl;
    x -= 30;
    cout << "x -= 30 -> " << x << endl;
    x *= 600;
    cout << "x *= 600 -> " << x << endl;
    x /= 30;
    cout << "x /= 30 -> " << x << endl;
    cout << "Final x value: " << x << endl;
    
    // BITWISE OPERATORS
    int bit_a, bit_b;
    cout << "\nEnter first integer for bitwise operations: ";
    cin >> bit_a;
    cout << "Enter second integer for bitwise operations: ";
    cin >> bit_b;
    
    int wynik = 0;
    wynik = bit_a & bit_b;
    cout << "Bitwise AND: " << wynik << "." << endl;
    wynik = bit_a | bit_b;
    cout << "Bitwise OR: " << wynik << "." << endl;
    wynik = ~bit_a;
    cout << "Bitwise NOT (first integer): " << wynik << "." << endl;
    wynik = ~bit_b;
    cout << "Bitwise NOT (second integer): " << wynik << "." << endl;
    wynik = bit_a ^ bit_b;
    cout << "Bitwise XOR: " << wynik << "." << endl;
    wynik = bit_a >> bit_b;
    cout << "Bitwise shift right: " << wynik << "." << endl;
    wynik = bit_a << bit_b;
    cout << "Bitwise shift left: " << wynik << "." << endl;

    return;
}