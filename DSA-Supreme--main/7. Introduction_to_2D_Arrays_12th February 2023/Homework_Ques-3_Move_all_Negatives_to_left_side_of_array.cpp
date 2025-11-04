#include<iostream>
#include<vector>
using namespace std;

/*
Approach Used: Two Pointer Partitioning (Similar to Dutch National Flag for 0/1/2)
----------------------------------------------------------------------------------
- The goal is to move all negative numbers to the left side of the array, and all non-negative numbers to the right.
- We use two pointers:
    i: starts from the left (beginning of array)
    j: starts from the right (end of array)
- We scan from both ends:
    - If arr[i] is negative, it's already on the left, so increment i.
    - If arr[j] is negative and arr[i] is not, swap arr[i] and arr[j], then move both pointers.
    - If arr[j] is non-negative, decrement j.
- This is done in-place and in a single pass (O(n) time, O(1) space).

Better/Alternative Approaches:
------------------------------
1. Stable Partition using Extra Space (Preserves order of negatives and non-negatives):
    - Create a new array.
    - First copy all negatives, then all non-negatives.
    - Copy back to original array if needed.
    - Code:
        vector<int> temp;
        for(int x : arr) if(x < 0) temp.push_back(x);
        for(int x : arr) if(x >= 0) temp.push_back(x);
        arr = temp;
    - Time: O(n), Space: O(n), Stable.

2. Stable In-Place Partition (Insertion Sort Style, Preserves Order, O(n^2)):
    - For each element, if negative, shift all previous non-negatives right and insert negative at correct position.
    - Code:
        for(int i = 1; i < arr.size(); i++) {
            if(arr[i] < 0) {
                int temp = arr[i], j = i-1;
                while(j >= 0 && arr[j] >= 0) {
                    arr[j+1] = arr[j];
                    j--;
                }
                arr[j+1] = temp;
            }
        }
    - Time: O(n^2), Space: O(1), Stable.

3. std::stable_partition (C++ STL, Stable, O(n) expected):
    - Use built-in stable_partition from <algorithm>.
    - Code:
        #include <algorithm>
        stable_partition(arr.begin(), arr.end(), [](int x){ return x < 0; });
    - Time: O(n), Space: O(log n), Stable.

Dry Run:
--------
Input: [1,2,-4,-5,2,-7,3,2,-6,-8,-9,3,2,1]
Initial: i=0, j=13
Step 1: arr[0]=1 (not negative), arr[13]=1 (not negative) => j--
Step 2: arr[0]=1, arr[12]=2 (not negative) => j--
Step 3: arr[0]=1, arr[11]=3 (not negative) => j--
Step 4: arr[0]=1, arr[10]=-9 (negative) => swap arr[0] and arr[10]
        arr=[-9,2,-4,-5,2,-7,3,2,-6,-8,1,3,2,1], i++, j--
Step 5: arr[1]=2, arr[9]=-8 (negative) => swap arr[1] and arr[9]
        arr=[-9,-8,-4,-5,2,-7,3,2,-6,2,1,3,2,1], i++, j--
... and so on, until all negatives are on the left.

Code with detailed comments:
*/

void moveNegatives(vector<int>& arr) {
    int i = 0;                      // Pointer from left (start of array)
    int j = arr.size() - 1;         // Pointer from right (end of array)
    while(i <= j) {                 // Continue until pointers cross
        if(arr[i] < 0) {            // If current left element is negative
            // Already at correct side, move left pointer forward
            i++;
        }
        else if(arr[j] < 0) {       // If right element is negative and left is not
            // Swap negative from right to left
            swap(arr[i], arr[j]);
            i++;                    // Move left pointer forward
            j--;                    // Move right pointer backward
        }
        else {
            // arr[j] is non-negative, move right pointer backward
            j--;
        }
    }
}

int main() {
    vector<int> arr{1,2,-4,-5,2,-7,3,2,-6,-8,-9,3,2,1}; // Input array
    moveNegatives(arr);                                 // Move all negatives to left
    for(int i = 0; i < arr.size(); i++) {               // Print the result
        cout << arr[i] << " ";
    }
    return 0;
}

/*
Dry Run:
--------
Input: [1,2,-4,-5,2,-7,3,2,-6,-8,-9,3,2,1]
i=0, j=13
arr[0]=1 (not negative), arr[13]=1 (not negative) => j=12
arr[0]=1, arr[12]=2 (not negative) => j=11
arr[0]=1, arr[11]=3 (not negative) => j=10
arr[0]=1, arr[10]=-9 (negative) => swap arr[0] and arr[10], i=1, j=9
arr=[-9,2,-4,-5,2,-7,3,2,-6,-8,1,3,2,1]
arr[1]=2, arr[9]=-8 => swap arr[1] and arr[9], i=2, j=8
arr=[-9,-8,-4,-5,2,-7,3,2,-6,2,1,3,2,1]
arr[2]=-4 (negative) => i=3
arr[3]=-5 (negative) => i=4
arr[4]=2, arr[8]=-6 => swap arr[4] and arr[8], i=5, j=7
arr=[-9,-8,-4,-5,-6,-7,3,2,2,2,1,3,2,1]
arr[5]=-7 (negative) => i=6
arr[6]=3, arr[7]=2 (not negative) => j=6
Loop ends (i=6, j=6)
All negatives are now on the left side.
Output: -9 -8 -4 -5 -6 -7 3 2 2 2 1 3 2 1
*/