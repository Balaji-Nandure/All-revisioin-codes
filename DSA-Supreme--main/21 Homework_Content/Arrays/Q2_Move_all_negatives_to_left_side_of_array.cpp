/*
    Approach Used in this Code:
    ---------------------------------
    - The goal is to move all negative numbers to the left side of the array and positive numbers to the right side.
    - Order of elements is NOT required to be maintained.
    - This is a variation of the partition process of QuickSort (two-pointer approach).
    - We use two pointers: 
        - 's' starts from the beginning (left), 
        - 'e' starts from the end (right).
    - We increment 's' until we find a positive number.
    - We decrement 'e' until we find a negative number.
    - When both are at wrong positions, we swap arr[s] and arr[e].
    - Continue until s >= e.

    Better Alternatives (with code in comments):
    --------------------------------------------
    1. Using std::stable_partition (C++ STL) - maintains order (if required):
        // #include <algorithm>
        // std::stable_partition(arr, arr+n, [](int x){ return x < 0; });

    2. Using Lomuto Partition Scheme (like QuickSort):
        // int j = 0;
        // for(int i = 0; i < n; i++) {
        //     if(arr[i] < 0) {
        //         swap(arr[i], arr[j]);
        //         j++;
        //     }
        // }
        // This also does not maintain order, but is a single pass.

    3. Using Extra Array (if order is required and space is not a concern):
        // int temp[n], idx = 0;
        // for(int i = 0; i < n; i++)
        //     if(arr[i] < 0) temp[idx++] = arr[i];
        // for(int i = 0; i < n; i++)
        //     if(arr[i] >= 0) temp[idx++] = arr[i];
        // for(int i = 0; i < n; i++)
        //     arr[i] = temp[i];

    Time Complexity: O(n)
    Space Complexity: O(1) (in-place)
*/

#include<iostream>
#include<algorithm>
using namespace std;

// Function to move all negative numbers to left side of array
void moveNegatives(int arr[], int n) {
    int s = 0;           // Pointer from start, to find positive numbers
    int e = n - 1;       // Pointer from end, to find negative numbers

    while (s < e) {
        // If current element at 's' is negative, it's already on left, move 's' forward
        if (arr[s] < 0) {
            s++;
        }
        // If current element at 'e' is positive, it's already on right, move 'e' backward
        else if (arr[e] >= 0) {
            e--;
        }
        // If arr[s] is positive and arr[e] is negative, swap them
        else {
            swap(arr[s], arr[e]);
            s++;
            e--;
        }
    }
}

int main() {
    int arr[] = {1, 2, -3, 4, -5, 6};
    int n = sizeof(arr) / sizeof(arr[0]); // Calculate size of array

    moveNegatives(arr, n); // Move all negatives to left

    // Print the modified array
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    /*
        Dry Run:
        --------
        Initial: arr = [1, 2, -3, 4, -5, 6]
        s = 0, e = 5

        Iteration 1:
            arr[s]=1 (positive), arr[e]=6 (positive)
            arr[e] is positive, so e--
            s=0, e=4

        Iteration 2:
            arr[s]=1 (positive), arr[e]=-5 (negative)
            arr[s] is positive, arr[e] is negative, swap
            arr = [-5, 2, -3, 4, 1, 6]
            s=1, e=3

        Iteration 3:
            arr[s]=2 (positive), arr[e]=4 (positive)
            arr[e] is positive, so e--
            s=1, e=2

        Iteration 4:
            arr[s]=2 (positive), arr[e]=-3 (negative)
            arr[s] is positive, arr[e] is negative, swap
            arr = [-5, -3, 2, 4, 1, 6]
            s=2, e=1

        Loop ends (s >= e)
        Final array: [-5, -3, 2, 4, 1, 6]
        All negatives are on the left side.
    */

    return 0;
}