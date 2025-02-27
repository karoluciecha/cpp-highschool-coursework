#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Candidate {
    int id;
    int power;
};

// Function to get the number of candidates
int getCandidateCount() {
    int count;
    do {
        cout << "\nEnter the number of candidates (1 - 1,000,000): ";
        cin >> count;
        if (count < 1 || count > 1000000) {
            cout << "Invalid number! Please enter a value between 1 and 1,000,000.\n";
        }
    } while (count < 1 || count > 1000000);
    return count;
}

// Function to input candidates' power levels
void getCandidates(vector<Candidate>& candidates, int count) {
    for (int i = 0; i < count; i++) {
        Candidate c;
        c.id = i + 1;
        do {
            cout << "Enter power level for Candidate #" << c.id << " (-1,000,000 to 1,000,000): ";
            cin >> c.power;
            if (c.power < -1000000 || c.power > 1000000) {
                cout << "Invalid power level! Please enter a value between -1,000,000 and 1,000,000.\n";
            }
        } while (c.power < -1000000 || c.power > 1000000);
        candidates.push_back(c);
    }
}

// Function to sort candidates by power (descending)
void sortCandidates(vector<Candidate>& candidates) {
    sort(candidates.begin(), candidates.end(), [](const Candidate& a, const Candidate& b) {
        return a.power > b.power;
    });
}

// Function to display the top 10 (or all) candidates
void displayResults(const vector<Candidate>& candidates) {
    cout << "\n\nContest Results:\n\n";
    int displayCount = min(10, (int)candidates.size());
    for (int i = 0; i < displayCount; i++) {
        cout << i + 1 << ". Candidate #" << candidates[i].id << ": " << candidates[i].power << " power points.\n";
    }
}

void runNumberSorterProgram() {
    cout << "WELCOME TO THE MUSKETEERS CONTEST!";
    char answer;
    
    do {
        vector<Candidate> candidates;
        int candidateCount = getCandidateCount();
        
        getCandidates(candidates, candidateCount);
        sortCandidates(candidates);
        displayResults(candidates);

        cout << "\nWould you like to run the program again? (Y/N): ";
        cin >> answer;
    } while (answer == 'Y' || answer == 'y');

    cout << "\nThank you for using the program!\n";
}