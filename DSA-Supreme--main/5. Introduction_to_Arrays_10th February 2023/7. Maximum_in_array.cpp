#include<iostream>
#include<limits.h>
using namespace std;

/*
Approach:
- We are given an array of integers.
- Our goal is to find the maximum element in the array.
- We initialize a variable 'maxi' with the minimum possible integer value (INT_MIN).
- We iterate through the array, and for each element, we check if it is greater than 'maxi'.
- If it is, we update 'maxi' with this element.
- After the loop, 'maxi' will contain the maximum value in the array.
*/

int main(){
    int arr[5] = {3,1,2,5,4}; // initialize array with 5 elements

    int maxi = INT_MIN; // Initialize maxi to the smallest integer value possible

    // Traverse the array to find the maximum element
    for(int i = 0; i < 5; i++){ // loop through each element of the array
        // If current element is greater than current maximum, update maxi
        if(arr[i] > maxi){ // compare current element with maxi
            maxi = arr[i]; // update maxi if current element is greater
        }
    }

    cout << "Maximum element = " << maxi; // Output the maximum element found

    return 0;
}

/*
Dry Run:
arr = [3, 1, 2, 5, 4]
maxi = INT_MIN

Iteration 1: i=0, arr[0]=3
    3 > INT_MIN => maxi = 3

Iteration 2: i=1, arr[1]=1
    1 > 3 => false, maxi remains 3

Iteration 3: i=2, arr[2]=2
    2 > 3 => false, maxi remains 3

Iteration 4: i=3, arr[3]=5
    5 > 3 => true, maxi = 5

Iteration 5: i=4, arr[4]=4
    4 > 5 => false, maxi remains 5

Final Output: Maximum element = 5
*/