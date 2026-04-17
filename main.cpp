#include <iostream>
#include <limits>
#include "GroceryTracker.h"
using namespace std;

// Displays the menu options
void DisplayMenu() {
    cout << "\n===============================" << endl;
    cout << " Corner Grocer Tracking Program" << endl;
    cout << "===============================" << endl;
    cout << "1. Search for an item frequency" << endl;
    cout << "2. Print all item frequencies" << endl;
    cout << "3. Print histogram" << endl;
    cout << "4. Exit program" << endl;
    cout << "Enter your choice: ";
}

int main() {
    int userChoice = 0;
    string itemToSearch;

    // Create GroceryTracker object
    GroceryTracker tracker("CS210_Project_Three_Input_File.txt", "frequency.dat");

    // Load data from input file
    tracker.LoadDataFromFile();

    // Create backup file automatically at the start
    tracker.SaveDataToFile();

    // Keep showing menu until user chooses 4
    while (userChoice != 4) {
        DisplayMenu();
        cin >> userChoice;

        // Validate numeric input
        while (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number from 1 to 4: ";
            cin >> userChoice;
        }

        switch (userChoice) {
        case 1:
            cout << "Enter the item name: ";
            cin >> itemToSearch;
            cout << itemToSearch << " was purchased "
                << tracker.GetItemFrequency(itemToSearch)
                << " time(s)." << endl;
            break;

        case 2:
            cout << "\nItem Frequencies:\n" << endl;
            tracker.PrintAllFrequencies();
            break;

        case 3:
            cout << "\nHistogram:\n" << endl;
            tracker.PrintHistogram();
            break;

        case 4:
            cout << "Exiting program. Goodbye!" << endl;
            break;

        default:
            cout << "Invalid choice. Please select 1, 2, 3, or 4." << endl;
            break;
        }
    }

    return 0;
}