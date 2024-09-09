#include "Question2.h"

// A function that adds a new integer to the end of the array w/ try&catch
void addNewIntegerInArray(int arr[], int value, int& array_size, int maxSize) {
	try {
		if (array_size >= maxSize) { // Check if the array is full
			throw overflow_error("Array is full. Cannot add new number.");
		}

		arr[array_size] = value; // Add the new value to the end of the array
		array_size++; // Increment the size of the array
	}
	catch (const overflow_error& e) {
		cout << "Error: " << e.what() << endl;
	}
}

// A function that can modify the value of an integer when called with the index of the integer in the array and return the new value and old value back to the user w/ try&catch
tuple<int, int> modifyValueofIntInArray(int arr[], int index, int newValue, int array_size) {
	try {
		if (index < 0 || index >= array_size) { // Check for an invalid index number
			throw out_of_range("Index out of bounds.");
		}

		int oldValue = arr[index]; // Store the old value
		arr[index] = newValue; // Modify the value
		return make_tuple(oldValue, newValue); // Return old and new value
	}

	catch (const out_of_range& e) {
		cout << "Error: " << e.what() << endl;
		return make_tuple(-1, -1); // Return -1 for both old and new value
	}
}
