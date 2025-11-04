#include<iostream>
using namespace std;

/*
Approach Used:
---------------
1. We have an integer array of size 5 initialized with values {1,2,3,4,5}.
2. We iterate through each element of the array using a for loop.
3. For each element, we multiply it by 2 and print the result.

Key Logic:
----------
- The multiplication by 2 is done inside the loop for each element.
- The output is printed in a single line, separated by spaces.

Alternative Detailed Approach:
-----------------------------
- Instead of printing the doubled values directly, we could create a new array to store the doubled values.
- First, iterate through the original array, multiply each element by 2, and store it in the new array.
- Then, iterate through the new array and print its elements.
- This approach is useful if we need to use the doubled values later in the program.

Example of Alternative Approach (in code):
------------------------------------------
    int arr[5] = {1,2,3,4,5};
    int doubledArr[5];
    for(int i = 0; i < 5; i++) {
        doubledArr[i] = 2 * arr[i]; // Store doubled value
    }
    for(int i = 0; i < 5; i++) {
        cout << doubledArr[i] << " ";
    }

Dry Run:
--------
arr = [1, 2, 3, 4, 5]
Iteration 1: i=0, arr[0]=1, 2*1=2, print 2
Iteration 2: i=1, arr[1]=2, 2*2=4, print 4
Iteration 3: i=2, arr[2]=3, 2*3=6, print 6
Iteration 4: i=3, arr[3]=4, 2*4=8, print 8
Iteration 5: i=4, arr[4]=5, 2*5=10, print 10
Final Output: 2 4 6 8 10

*/

int main(){

    int arr[5] = {1,2,3,4,5}; // Initialize array with 5 elements

    // Loop through each element of the array
    for(int i = 0; i < 5; i++){
        // Multiply current element by 2 and print it
        cout << 2 * arr[i] << " ";
    }

    return 0; // Indicate successful program termination
}