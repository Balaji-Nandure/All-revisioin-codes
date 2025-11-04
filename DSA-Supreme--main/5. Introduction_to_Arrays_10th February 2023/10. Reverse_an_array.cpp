#include<iostream>
using namespace std;

/*
Approach Used:
---------------
We use the two-pointer approach to reverse the array in-place.
- One pointer (start) begins at the start of the array.
- The other pointer (end) begins at the end of the array.
- We swap the elements at these pointers and move them towards each other until they meet or cross.

Key Points:
- This approach reverses the array in O(n) time and O(1) extra space.
- No extra array is used; the reversal is done in-place.
*/

int main(){
    int arr[5] = {1,2,3,4,5}; // Initialize array with 5 elements
    int start = 0;             // Pointer to the beginning of the array
    int end = 4;               // Pointer to the end of the array (size-1)

    // Swapping logic to reverse the array
    while(start <= end){ // Continue until start and end pointers meet or cross
        // Swapping elements at start and end positions
        swap(arr[start], arr[end]);
        start++; // Move start pointer forward
        end--;   // Move end pointer backward
    }

    // Printing the reversed array
    for(int i = 0; i < 5; i++){
        cout << arr[i] << " ";
    }
    return 0;
}

/*
Alternative Approach (using extra array):
-----------------------------------------
1. Create a new array of the same size.
2. Copy elements from the original array to the new array in reverse order.
   Example:
   for(int i = 0; i < n; i++){
       newArr[i] = arr[n-1-i];
   }
3. Copy newArr back to arr if needed, or print newArr.

This approach uses O(n) extra space.

Dry Run of Current Code:
------------------------
Initial array: [1, 2, 3, 4, 5]
start = 0, end = 4

Iteration 1:
    swap(arr[0], arr[4]) => [5, 2, 3, 4, 1]
    start = 1, end = 3

Iteration 2:
    swap(arr[1], arr[3]) => [5, 4, 3, 2, 1]
    start = 2, end = 2

Iteration 3:
    swap(arr[2], arr[2]) => [5, 4, 3, 2, 1] (no change)
    start = 3, end = 1

Loop ends (start > end).

Final array: [5, 4, 3, 2, 1]
Output: 5 4 3 2 1
*/