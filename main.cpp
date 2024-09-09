#include "Question1.h"
#include "Question2.h"

#include <fstream>
#include <sstream>
#include <iostream>
#include<tuple>

using namespace std;

int main() {
    const int MAX_SIZE = 100;
    int array[MAX_SIZE]; // Array to store the numbers
    int size = 0; // Size of the array

    ifstream inputFile("A1input.txt"); // Open the input file

    if (!inputFile) {
        cout << "Error Opening File." << endl;
    }

    // Read numbers from the file into the array, line by line
    string line;
    while (getline(inputFile, line)) {
        stringstream ss(line); // Use stringstream to extract numbers from the line
        int num;
        while (ss >> num && size < MAX_SIZE) {
            array[size] = num;
            size++;
        }
    }

    inputFile.close(); // Close the input file after reading

    // Output the array contents
    cout << "Array loaded from file:" << endl;
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    int choice;
    cout << "\nChoose an operation: " << endl;
    cout << "1. Find a number in the array" << endl;
    cout << "2. Modify a number in the array" << endl;
    cout << "3. Add a new number to the array" << endl;
    cout << "4. Remove a number from the array" << endl;
    cout << "5. Exit" << endl;

    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
    case 1: {
        int value;
        cout << "Enter the value to find: ";
        cin >> value;

        int index = findNumberInArray(array, size, value);

        if (index != -1) {
            cout << "Value found at index: " << index << endl;
        }
        else {
            cout << "Value not found in the array." << endl;
        }
        break;
    }

    case 2: {
        int index, newValue;
        cout << "Enter the index to modify (0 to " << size - 1 << "): ";
        cin >> index;

        cout << "Enter the new value: ";
        cin >> newValue;

        tuple<int, int> result = modifyValueofIntInArray(array, index, newValue, size);
        int oldValue = get<0>(result);

        cout << "The value at index " << index << " was modified from " << oldValue << " to " << newValue << endl;
        break;
    }

    case 3: {
        int newValue;
        cout << "Enter the new number to add: ";
        cin >> newValue;

        addNewIntegerInArray(array, newValue, size, MAX_SIZE);
        cout << "Number added successfully. New size: " << size << endl;
        break;
    }

    case 4: {
        int index;
        cout << "Enter the index to remove (0 to " << size - 1 << "): ";
        cin >> index;

        removeNumber(array, size, index);
        cout << "Number removed successfully. New size: " << size << endl;
        break;
    }

    case 5: {
        // Exit the program
        cout << "Exiting the program..." << endl;
        break;
    }

    default: {
        cout << "Invalid choice. Please choose a valid option." << endl;
        break;
    }
    }

    cout << "UPDATED ARRAY:" << endl;
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}
