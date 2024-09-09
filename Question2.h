#pragma once
#include <iostream>
#include <tuple>
#include <stdexcept>

using namespace std;

// A function that adds a new integer to the end of the array w/ try&catch
void addNewIntegerInArray(int arr[], int value, int& array_size, int maxSize);

// A function that can modify the value of an integer when called with the index of the integer in the array and return the new value and old value back to the user w/ try&catch
tuple<int, int> modifyValueofIntInArray(int arr[], int index, int newValue, int array_size);
