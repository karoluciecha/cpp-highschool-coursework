#include <iostream>
#include <string>

using namespace std;

char answer;
string word;

// Function to enter a word
static void enterWord(string &word) {
    cout << "\nEnter a phrase: ";
    cin.ignore(); // Clears any leftover newline characters in the input buffer
    getline(cin, word); // Reads the entire line, including spaces
}

// Function to remove all occurrences of 'h' and 'H' from the word
string removeH(const string &word) {
    string modifiedWord;
    for (char ch : word) {
        if (ch != 'h' && ch != 'H') {
            modifiedWord += ch;
        }
    }
    return modifiedWord;
}

// Function to remove 'a', 'A', 'o', and 'O' from the word
string removeVowels(const string &word) {
    string modifiedWord;
    for (char ch : word) {
        if (ch != 'a' && ch != 'A' && ch != 'o' && ch != 'O') {
            modifiedWord += ch;
        }
    }
    return modifiedWord;
}

// Function to count occurrences of 'a' and 'A' in the word
int countA(const string &word) {
    int count = 0;
    for (char ch : word) {
        if (ch == 'a' || ch == 'A') {
            count++;
        }
    }
    return count;
}

void runWordModificationsProgram() {
    cout << "WELCOME TO THE CHARACTER OPERATIONS PROGRAM!";

    do {
        enterWord(word);

        cout << "\nText without 'h' and 'H': " << removeH(word);
        cout << "\nText without 'a', 'A', 'o', and 'O': " << removeVowels(word);
        cout << "\nNumber of occurrences of 'a' and 'A': " << countA(word);

        cout << "\n\nWould you like to run the program again? (Y/N): ";
        cin >> answer;
        cin.ignore(); // Prevents issues with newline characters
    } while (answer == 'Y' || answer == 'y');

    cout << "\nThank you! See you next time.\n\n";
}