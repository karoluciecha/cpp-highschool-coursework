#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> getLongestIncreasingSubsequence(vector<int>& arr) {
    int n = (int)arr.size();
    vector<int> dp(n, 1), prev(n, -1);
    int maxLength = 0, lastIndex = -1;
    
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[j] < arr[i] && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
                prev[i] = j;
            }
        }
        if (dp[i] > maxLength) {
            maxLength = dp[i];
            lastIndex = i;
        }
    }
    
    vector<int> lis;
    while (lastIndex != -1) {
        lis.push_back(arr[lastIndex]);
        lastIndex = prev[lastIndex];
    }
    
    reverse(lis.begin(), lis.end());
    return lis;
}

void runLongestIncreasingSubsequenceProgram() {
    ifstream infile("../ResourceFiles/sequences.txt");
    ofstream outfile("../ResourceFiles/subsequences.txt");
    
    if (!infile) {
        cerr << "Error: Unable to open input file (../ResourceFiles/sequences.txt)." << endl;
        return;
    }
    
    int numSequences;
    infile >> numSequences;
    
    cout << "Processing " << numSequences << " sequences:" << endl << endl;
    
    for (int i = 0; i < numSequences; i++) {
        int n;
        infile >> n;
        vector<int> arr(n);
        
        cout << "Sequence " << (i + 1) << " (size " << n << "): ";
        for (int j = 0; j < n; j++) {
            infile >> arr[j];
            cout << arr[j] << " ";
        }
        cout << endl;
        
        vector<int> lis = getLongestIncreasingSubsequence(arr);
        
        cout << "Longest Increasing Subsequence Length: " << lis.size() << endl;
        cout << "Longest Increasing Subsequence: ";
        outfile << lis.size() << " : ";
        for (int num : lis) {
            cout << num << " ";
            outfile << num << " ";
        }
        cout << "\n" << endl;
        outfile << "\n";
    }
    
    infile.close();
    outfile.close();
    cout << "Results have been saved to ResourceFiles/subsequences.txt." << endl;
    cout << "To calculate different sequences, please edit the file located at ResourceFiles/sequences.txt." << endl;
    return;
}