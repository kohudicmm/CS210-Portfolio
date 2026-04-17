#include "GroceryTracker.h"

// Constructor initializes input and output file names
GroceryTracker::GroceryTracker(string inputFile, string outputFile) {
    inputFileName = inputFile;
    outputFileName = outputFile;
}

// Reads the grocery items from the input file
// and counts how many times each item appears
void GroceryTracker::LoadDataFromFile() {
    ifstream inFS;
    string itemName;

    inFS.open(inputFileName);

    // Check if the file opened correctly
    if (!inFS.is_open()) {
        cout << "Error: Could not open input file." << endl;
        return;
    }

    // Read each item from the file
    while (inFS >> itemName) {
        itemFrequency[itemName]++;
    }

    inFS.close();
}

// Writes the item frequencies to frequency.dat
void GroceryTracker::SaveDataToFile() {
    ofstream outFS;
    outFS.open(outputFileName);

    // Check if the file opened correctly
    if (!outFS.is_open()) {
        cout << "Error: Could not create output file." << endl;
        return;
    }

    // Write each item and its frequency to the file
    for (auto it = itemFrequency.begin(); it != itemFrequency.end(); ++it) {
        outFS << it->first << " " << it->second << endl;
    }

    outFS.close();
}

// Returns the frequency of a specific item
int GroceryTracker::GetItemFrequency(string item) {
    if (itemFrequency.find(item) != itemFrequency.end()) {
        return itemFrequency[item];
    }
    return 0;
}

// Prints all items and frequencies
void GroceryTracker::PrintAllFrequencies() {
    for (auto it = itemFrequency.begin(); it != itemFrequency.end(); ++it) {
        cout << it->first << " " << it->second << endl;
    }
}

// Prints histogram using asterisks
void GroceryTracker::PrintHistogram() {
    for (auto it = itemFrequency.begin(); it != itemFrequency.end(); ++it) {
        cout << it->first << " ";
        for (int i = 0; i < it->second; ++i) {
            cout << "*";
        }
        cout << endl;
    }
}