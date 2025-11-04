#include<iostream>
using namespace std;

/*
Approach:
We want to print elements of the array from both ends alternately: first from the start, then from the end, then next start, next end, and so on.
We use two pointers: 'start' (beginning of array) and 'end' (end of array).
In each iteration, we print arr[start] and arr[end], then move start forward and end backward.
If start and end meet (for odd length arrays), print the middle element once and stop.
*/

int main(){
    int arr[6] = {1,2,3,4,5,6}; // initialize array of size 6
    int start = 0; // pointer to start of array
    int end = 5;   // pointer to end of array (size-1)

    while(start <= end){ // loop until start crosses end
        if(start == end){ // if both pointers meet (for odd length arrays)
            cout << arr[start] << " "; // print the middle element only once
            break; // exit loop as all elements are printed
        }
        cout << arr[start] << " "; // print element from start
        cout << arr[end] << " ";   // print element from end
        start++; // move start pointer forward
        end--;   // move end pointer backward
    }
    return 0;
}

/*
Dry Run:
arr = {1,2,3,4,5,6}
start = 0, end = 5

Iteration 1: start=0, end=5 -> print arr[0]=1, arr[5]=6
Iteration 2: start=1, end=4 -> print arr[1]=2, arr[4]=5
Iteration 3: start=2, end=3 -> print arr[2]=3, arr[3]=4
Iteration 4: start=3, end=2 -> loop ends

Output: 1 6 2 5 3 4
*/