#include<iostream>
using namespace std;

/*
Approach:
- We want to demonstrate how arrays are passed to functions in C++.
- When an array is passed to a function, the function receives a pointer to the original array, not a copy.
- Any changes made to the array inside the function will affect the original array in main().
- We'll create a function 'incr' that increases the first element of the array by 10.
*/

// Function to increment the first element of the array by 10
void incr(int arr[], int size) { // Passing array and its size (good practice)
    // arr points to the original array, so changes here affect the original array
    arr[0] = arr[0] + 10; // Increment the first element by 10
}

int main() {
    int arr[5] = {1,2,3,4,5}; // Declare and initialize array

    cout << arr[0] << endl; // Print the first element before function call (Expected: 1)

    incr(arr, 5); // Call function to increment first element

    cout << arr[0]; // Print the first element after function call (Expected: 11)

    return 0;
}

/*
Dry Run:
----------
Step 1: arr = {1,2,3,4,5}
        arr[0] = 1
        Output: 1

Step 2: Call incr(arr, 5)
        Inside incr:
            arr[0] = arr[0] + 10 => arr[0] = 1 + 10 = 11
        Now arr = {11,2,3,4,5}

Step 3: Output arr[0] again
        Output: 11

Final Output:
1
11
*/