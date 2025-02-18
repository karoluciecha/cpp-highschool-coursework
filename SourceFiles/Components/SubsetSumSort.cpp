#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <windows.h>

using namespace std;

string fileName, line, ks, values, ns, tempStr, combinationArray[1000000];
int k, n, temp, i = 0, valueArray[1000000], indexArray[1000000], computedValues[1000000];
vector<string> combinationList;
vector<string> sortingTemp;

void generateCombinationsUtil(int arr[], int n, int r, int index, vector<int>& data, int i, vector<string>& combinationList);
void generateCombinations(int arr[], int n, int r, vector<string>& combinationList)
{
    vector<int> data(r);
    generateCombinationsUtil(arr, n, r, 0, data, 0, combinationList);
}

void generateCombinationsUtil(int arr[], int n, int r, int index, vector<int>& data, int i, vector<string>& combinationList)
{
    if (index == r)
    {
        stringstream ss;
        for (int j = 0; j < r; j++) {
            ss << data[j] << " ";
        }
        combinationList.push_back(ss.str());
        return;
    }
    if (i >= n)
        return;

    data[index] = arr[i];
    generateCombinationsUtil(arr, n, r, index + 1, data, i + 1, combinationList);
    generateCombinationsUtil(arr, n, r, index, data, i + 1, combinationList);
}

bool compareStrings(string a, string b) {
    return a < b;
}

vector<string> sortAlphabetically(vector<string> a) {
    sort(a.begin(), a.end(), compareStrings);
    return a;
}

void runSubsetSumSortProgram() {
    // Explanation of the program for the user
    cout << "This program reads an input file containing numbers, generates all possible subsets," << endl;
    cout << "calculates their sums, and sorts them in ascending order." << endl;
    cout << "Then, it finds and displays the k-th smallest sum with its subset." << endl;
    cout << "\nInput file format example (if it does not exist, create a file with these contents):" << endl;
    cout << "---------------------------------" << endl;
    cout << "10 15" << endl;
    cout << "1 1 1 1 1 1 1 1 1 1" << endl;
    cout << "---------------------------------" << endl;
    cout << "Current input file name: ../ResourceFiles/subsetSumSortInput.txt" << endl;
    
    // FILE OPERATION
    // Asking user for the input file
    char buffer[MAX_PATH];
    GetCurrentDirectoryA(MAX_PATH, buffer);
    cout << "Current Working Directory: " << buffer << endl;
    cout << "\nPlease enter the input file name: ";
    cin >> fileName;

    ifstream inputFile(fileName, ios::in);
    if (!inputFile) {
        cerr << "Error opening file!" << endl;
        return;
    }

    getline(inputFile, line);
    ks = line;
    getline(inputFile, line);
    values = line;
    inputFile.close();

    // STRING SPLITTING AND CONVERSION
    string delimiter = " ";
    size_t pos = 0;
    while ((pos = ks.find(delimiter)) != string::npos) {
        ns = ks.substr(0, pos);
        ks.erase(0, pos + delimiter.length());
    }

    k = stoi(ks);
    n = stoi(ns);

    stringstream ssin(values);
    while (ssin.good() && i < n) {
        ssin >> valueArray[i];
        ++i;
    }
    i = 0;

    // GENERATING COMBINATIONS
    for (int i = 1; i <= n; i++) {
        indexArray[i - 1] = i;
    }
    for (int i = 0; i <= n; i++) {
        generateCombinations(indexArray, n, i, combinationList);
    }

    // COMPUTING SUMS FOR COMBINATIONS
    for (int i = 0; i < combinationList.size(); i++) {
        size_t pos = 0;
        while ((pos = combinationList[i].find(delimiter)) != string::npos) {
            tempStr = combinationList[i].substr(0, pos);
            temp = stoi(tempStr);
            computedValues[i] += valueArray[temp - 1];
            combinationList[i].erase(0, pos + delimiter.length());
            combinationArray[i] += tempStr + " ";
        }
    }

    // SORTING RESULTS
    for (int i = 0; i < combinationList.size(); i++) {
        for (int j = i + 1; j < combinationList.size(); j++) {
            if (computedValues[i] > computedValues[j]) {
                swap(computedValues[i], computedValues[j]);
                swap(combinationArray[i], combinationArray[j]);
            } else if (computedValues[i] == computedValues[j]) {
                sortingTemp.clear();
                sortingTemp.push_back(combinationArray[i]);
                sortingTemp.push_back(combinationArray[j]);
                sortingTemp = sortAlphabetically(sortingTemp);

                if (combinationArray[i] != sortingTemp[0]) {
                    combinationArray[i] = sortingTemp[0];
                    combinationArray[j] = sortingTemp[1];
                }
            }
        }
    }

    // DISPLAY RESULTS
    for (int i = 0; i < combinationList.size(); i++) {
        cout << computedValues[i] << " : " << combinationArray[i] << endl;
    }

    cout << computedValues[k - 1] << endl;
    cout << combinationArray[k - 1] << endl;
}