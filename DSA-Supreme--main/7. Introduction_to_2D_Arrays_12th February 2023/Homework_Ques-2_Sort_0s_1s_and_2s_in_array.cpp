#include<iostream>
#include<vector>
using namespace std;

/*
Approach Used: Counting Sort (Two Passes, O(n) time, O(1) space)
-----------------------------------------------------------------
- The problem is to sort an array containing only 0s, 1s, and 2s.
- We count the number of 0s, 1s, and 2s in the array in the first pass.
- In the second pass, we overwrite the array with the counted number of 0s, then 1s, then 2s.
- This approach is simple, easy to implement, and works in linear time with constant space.

Better/Alternative Approaches:
-----------------------------
1. Dutch National Flag Algorithm (Single Pass, O(n) time, O(1) space):
   - Uses three pointers (low, mid, high) to partition the array into three sections.
   - Swaps elements in-place to their correct section in a single traversal.
   - More efficient as it sorts in a single pass and is in-place.

   // Dutch National Flag Algorithm Implementation:
   void sort0s1sand2s_DNF(vector<int>& nums) {
       int low = 0, mid = 0, high = nums.size() - 1;
       while (mid <= high) {
           if (nums[mid] == 0) {
               swap(nums[low++], nums[mid++]);
           } else if (nums[mid] == 1) {
               mid++;
           } else {
               swap(nums[mid], nums[high--]);
           }
       }
   }

2. STL sort (Not recommended for this problem, but possible):
   - Use std::sort(nums.begin(), nums.end());
   - Time complexity O(n log n), not optimal for this problem.

Dry Run:
--------
Input: [2, 0, 2, 1, 1, 0]
Step 1: Count 0s, 1s, 2s
    zeroCount = 2 (positions 1, 5)
    oneCount  = 2 (positions 3, 4)
    twoCount  = 2 (positions 0, 2)
Step 2: Overwrite array
    Fill 2 zeros: arr[0]=0, arr[1]=0
    Fill 2 ones:  arr[2]=1, arr[3]=1
    Fill 2 twos:  arr[4]=2, arr[5]=2
Output: [0, 0, 1, 1, 2, 2]
*/

void sort0s1sand2s(vector<int>& nums) {
    int zeroCount = 0; // To store count of 0s
    int oneCount = 0;  // To store count of 1s
    int twoCount = 0;  // To store count of 2s

    // First pass: Count the number of 0s, 1s, and 2s
    for(int i = 0; i < nums.size(); i++) {
        if(nums[i] == 0)
            zeroCount++; // Increment count for 0
        else if(nums[i] == 1)
            oneCount++;  // Increment count for 1
        else if(nums[i] == 2)
            twoCount++;  // Increment count for 2
        // No else needed, as only 0,1,2 are present
    }

    // Second pass: Overwrite the array with 0s, then 1s, then 2s
    int i = 0;
    while(zeroCount--) {
        nums[i++] = 0; // Place all 0s at the beginning
    }
    while(oneCount--) {
        nums[i++] = 1; // Place all 1s after 0s
    }
    while(twoCount--) {
        nums[i++] = 2; // Place all 2s at the end
    }
}

int main() {
    vector<int> arr{2, 0, 2, 1, 1, 0}; // Input array containing 0s, 1s, and 2s

    sort0s1sand2s(arr); // Sort the array using counting sort approach

    // Print the sorted array
    for(int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " "; // Output each element
    }
    cout << endl;

    /*
    Dry Run:
    --------
    Input: [2, 0, 2, 1, 1, 0]
    zeroCount = 2, oneCount = 2, twoCount = 2
    After filling:
    arr[0] = 0
    arr[1] = 0
    arr[2] = 1
    arr[3] = 1
    arr[4] = 2
    arr[5] = 2
    Output: 0 0 1 1 2 2
    */

    return 0; // Indicate successful program termination
}