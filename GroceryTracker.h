#ifndef GROCERYTRACKER_H
#define GROCERYTRACKER_H

#include <iostream>
#include <fstream>
#include <string>
#include <map>
using namespace std;

class GroceryTracker {
private:
    // Stores each grocery item and the number of times it appears
    map<string, int> itemFrequency;

    // Input file name
    string inputFileName;

    // Backup output file name
    string outputFileName;

public:
    // Constructor
    GroceryTracker(string inputFile, string outputFile);

    // Reads the input file and counts item frequencies
    void LoadDataFromFile();

    // Writes the frequency data to a backup file
    void SaveDataToFile();

    // Returns the frequency of one specific item
    int GetItemFrequency(string item);

    // Prints all items and their frequencies
    void PrintAllFrequencies();

    // Prints a histogram using asterisks
    void PrintHistogram();
};

#endif
