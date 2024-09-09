#include <iostream>
#include <fstream>
#include "Question1.h"

using namespace std;

// A function to check if a certain integer exists in the array if the number is present return the index where the number is present.
int findNumberInArray(int array[], int array_size, int value) {
	for (int i = 0; i < array_size; i++) { // iterate over the array
		if (array[i] == value) // if the value being searched for matches a number in the array
			return i; // return index
	}
	return -1; // return -1 if not found
}

// A function that can modify the value of an integer when called with the index of the integer in the array and return the new value and old value back to the user.
tuple<int, int> modifyNumberInArray(int arr[], int index, int newValue) {
	int oldValue = arr[index]; // Store the old value
	arr[index] = newValue; // Modify the value
	return make_tuple(oldValue, newValue); // Return old and new value
}

// A function that adds a new integer to the end of the array
void addNewNumberInArray(int arr[], int value, int& array_size, int maxSize) {
	if (array_size < maxSize) { // Ensure that we don't exceed array bounds
		arr[array_size] = value; // Add the new value to the end of the array
		array_size++; // Increment the size of the array
	}
	else {
		cout << "Array is full. Cannot add more elements." << endl;
	}
}

// A function which intakes an index of an array and replaces the value with either 0 or removes the integer altogether
void removeNumber(int array[], int array_size, int index) {

	for (int i = index; i < array_size - 1; i++) { // iterate over the array, starting at the left (backwards)
		array[i] = array[i + 1]; // shift elements one position
	}
	array_size--; // Decrease the size of the array
}

