/*
Approach:
-----------
- We want to search for a given key in an array using the linear search algorithm.
- Linear search works by traversing the array from the beginning and comparing each element with the key.
- If the key is found, we return true; otherwise, after checking all elements, we return false.
- We'll use a function `findElement` that takes the array, its size, and the key to search for.
- The function will return a boolean indicating whether the key is present in the array.
*/

#include<iostream>
using namespace std;

// Function to search for a key in the array using linear search
bool findElement(int arr[], int size, int key) {
    // Loop through each element of the array
    for(int i = 0; i < size; i++) { // i is the index, loop runs from 0 to size-1
        if(arr[i] == key) { // If current element matches the key
            return true;    // Key found, return true immediately
        }
    }
    // If loop completes and key is not found
    return false; // Key not found, return false
}

int main() {
    int arr[] = {2, 9, 6, 7, 4, 12, 15}; // Declare and initialize array
    int size = 7; // Size of the array
    int key = 16; // Key to search for

    // Call the function to search for the key in the array
    if(findElement(arr, size, key)) { // If function returns true (key found)
        cout << "Found element"; // Print found message
    }
    else {
        cout << "Not Found"; // Print not found message
    }
    return 0; // End of program
}

/*
Dry Run:
-----------
arr = {2, 9, 6, 7, 4, 12, 15}
size = 7
key = 16

Step 1: i = 0, arr[0] = 2, 2 != 16
Step 2: i = 1, arr[1] = 9, 9 != 16
Step 3: i = 2, arr[2] = 6, 6 != 16
Step 4: i = 3, arr[3] = 7, 7 != 16
Step 5: i = 4, arr[4] = 4, 4 != 16
Step 6: i = 5, arr[5] = 12, 12 != 16
Step 7: i = 6, arr[6] = 15, 15 != 16

All elements checked, key not found.
Output: Not Found
*/