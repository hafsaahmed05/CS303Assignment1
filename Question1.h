#pragma once
#include <iostream>
#include <tuple>

using namespace std;

/*Write a C++ program that can read data from an input file (link is provided above) into a
one dimensional array (don�t use vector) and perform the following functions:*/

// A function to check if a certain integer exists in the array if the number is present return the index where the number is present.
int findNumberInArray(int array[], int array_size, int value);

// A function that can modify the value of an integer when called with the index of the integer in the array and return the new value and old value back to the user.
tuple<int, int> modifyNumberInArray(int arr[], int index, int newValue);

// A function that adds a new integer to the end of the array
void addNewNumberInArray(int arr[], int value, int& array_size, int maxSize);

//  A function which intakes an index of an array and replaces the value with either 0 or removes the integer altogether
void removeNumber(int array[], int array_size, int index);