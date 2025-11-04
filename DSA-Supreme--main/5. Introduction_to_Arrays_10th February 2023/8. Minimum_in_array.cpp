#include<iostream>
#include<limits.h>
using namespace std;

/*
Approach Used:
---------------
- We are given an array of integers.
- Our goal is to find the minimum element in the array.
- We initialize a variable 'mini' with the maximum possible integer value (INT_MAX).
- We iterate through the array, and for each element, we check if it is less than 'mini'.
- If it is, we update 'mini' with this element.
- After the loop, 'mini' will contain the minimum value in the array.

Alternative Detailed Approach:
------------------------------
- Instead of initializing 'mini' with INT_MAX, we can initialize it with the first element of the array (arr[0]).
- Then, we start the loop from the second element (i = 1) and compare each element with 'mini'.
- If any element is smaller than 'mini', we update 'mini' with that element.
- This approach avoids dependency on INT_MAX and works for arrays with only one element as well.

Example of Alternative Approach:
    int mini = arr[0];
    for(int i = 1; i < 5; i++) {
        if(arr[i] < mini) {
            mini = arr[i];
        }
    }
*/

int main(){
    int arr[5] = {3,1,2,5,4}; // initialize array with 5 elements

    int mini = INT_MAX; // Initialize mini to the largest integer value possible

    // Traverse the array to find the minimum element
    for(int i = 0; i < 5; i++){ // loop through each element of the array
        // If current element is less than current minimum, update mini
        if(arr[i] < mini){ // compare current element with mini
            mini = arr[i]; // update mini if current element is smaller
        }
    }

    cout << "Minimum element = " << mini; // Output the minimum element found

    return 0;
}

/*
Dry Run:
arr = [3, 1, 2, 5, 4]
mini = INT_MAX

Iteration 1: i=0, arr[0]=3
    3 < INT_MAX => mini = 3

Iteration 2: i=1, arr[1]=1
    1 < 3 => mini = 1

Iteration 3: i=2, arr[2]=2
    2 < 1 => false, mini remains 1

Iteration 4: i=3, arr[3]=5
    5 < 1 => false, mini remains 1

Iteration 5: i=4, arr[4]=4
    4 < 1 => false, mini remains 1

Final Output: Minimum element = 1
*/