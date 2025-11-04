#include<iostream>
using namespace std;

/*
Approach:
1. Initialize an array with some values.
2. Traverse the array and change every element to 1.
3. Print the modified array.

Dry Run:
Initial array: [1, 2, 3, 4, 5]
After setting all elements to 1: [1, 1, 1, 1, 1]
Output: 1 1 1 1 1
*/

int main(){

    int arr[5] = {1,2,3,4,5}; // Step 1: Initialize array with values

    // Step 2: Traverse array and set each element to 1
    for(int i = 0; i < 5; i++){
        // Logic: Overwrite each element with 1
        arr[i] = 1;
    }

    // Step 3: Print the modified array
    for(int i = 0; i < 5; i++){
        // Logic: Output each element after modification
        cout << arr[i] << " ";
    }

    return 0;
}