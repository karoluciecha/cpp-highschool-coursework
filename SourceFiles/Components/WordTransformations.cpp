#include <iostream>
#include <string>

using namespace std;

// Function to input a word
static void enterWord(string& word) {
    cout << "Enter a word: ";
    cin.ignore(); // Clears any leftover newline characters in the input buffer
    getline(cin, word);
}

// Function to insert spaces between each letter
string addSpaces(const string& word) {
    string result;
    for (char c : word) {
        result += c;
        result += ' ';
    }
    return result;
}

// Function to reverse the string and add spaces after every second letter
string reverseWithSpaces(const string& word) {
    string result;
    for (int i = static_cast<int>(word.length()) - 1; i >= 0; i--) {  // FIXED: use int
        result += word[i];
        result += ' ';
    }
    return result;
}

// Function to insert spaces after every two characters
string addSpacesEveryTwoLetters(const string& word) {
    string result;
    for (size_t i = 0; i < word.length(); i++) {
        result += word[i];
        if (i % 2 == 1) {
            result += ' ';
        }
    }
    return result;
}

// Function to reverse the word and insert spaces every four characters
string reverseWithGroupSpacing(const string& word) {
    string result;
    int count = 0;

    for (int i = static_cast<int>(word.length()) - 1; i >= 0; i--) {  // FIXED: use int
        result += word[i];
        count++;

        if (count == 4) {
            result += "  "; // Double space for grouping
            count = 0;
        }
    }
    return result;
}

void runWordTransformationsProgram() {
    string word;
    enterWord(word);

    cout << "\nText after first transformation: " << addSpaces(word) << endl;
    cout << "\nText after second transformation: " << reverseWithSpaces(word) << endl;
    cout << "\nText after third transformation: " << addSpacesEveryTwoLetters(word) << endl;
    cout << "\nText after fourth transformation: " << reverseWithGroupSpacing(word) << endl << endl;
}