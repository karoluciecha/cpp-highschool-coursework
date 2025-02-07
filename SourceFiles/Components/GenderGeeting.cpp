#include <iostream>
#include <string>
#include <cctype> // For the tolower() function

using namespace std;

class Guest {
public:
    void hello(const string& firstName, const string& lastName);
};

void Guest::hello(const string& firstName, const string& lastName)
{
    if (firstName.empty()) {
        cout << "Invalid first name!" << endl;
        return;
    }

    char lastChar = tolower(firstName[firstName.length() - 1]); // Convert to lowercase

    if (lastChar == 'a') {
        cout << "A warm welcome to you, Madam: " << firstName << " " << lastName << " in our course." << endl;
    }
    else {
        cout << "A warm welcome to you, Sir: " << firstName << " " << lastName << " in our course." << endl;
    }
}

void runGenderBasedGreetingProgram()
{
    string firstName, lastName;
    Guest person;
	cout << "Attention! Program works correctly only with Polish names." << endl << endl;
    cout << "Please enter your first name (0 to terminate): ";

    while (cin >> firstName) {
		if (firstName == "0") {
			cout << "Program terminated." << endl;
			break;
		}

        cout << "Please enter your last name: ";

        if (!(cin >> lastName)) {
            cout << "Invalid input. Program terminated." << endl;
            break;
        }

        person.hello(firstName, lastName);
        cout << endl << "Please enter your first name: ";
    }
}
