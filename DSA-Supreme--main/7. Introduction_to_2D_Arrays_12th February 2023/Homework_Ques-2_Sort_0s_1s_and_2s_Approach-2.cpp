#include<iostream>
#include<vector>
using namespace std;

/*
Approach Used: Dutch National Flag Algorithm (Three Pointer Approach)
---------------------------------------------------------------
- The problem is to sort an array containing only 0s, 1s, and 2s in a single pass and without using extra space.
- We use three pointers:
    l (low):   marks the boundary for 0s (all elements before l are 0)
    m (mid):   current element under consideration
    h (high):  marks the boundary for 2s (all elements after h are 2)
- The idea is to partition the array into three sections:
    [0, l-1]      -> 0s
    [l, m-1]      -> 1s
    [m, h]        -> unknown
    [h+1, end]    -> 2s
- We iterate with m from 0 to h, and swap elements to their correct section based on their value.
*/

void sort0s1sand2s(vector<int>& nums) {
    int l = 0;                  // low pointer for 0s
    int m = 0;                  // mid pointer for current element
    int h = nums.size() - 1;    // high pointer for 2s

    // Traverse the array until mid pointer crosses high pointer
    while (m <= h) {
        if (nums[m] == 0) {
            // If current element is 0, swap it to the front (l-th position)
            swap(nums[m], nums[l]);
            m++;    // move to next element
            l++;    // expand 0s boundary
        }
        else if (nums[m] == 1) {
            // If current element is 1, it's already in correct place
            m++;    // just move to next element
        }
        else {
            // If current element is 2, swap it to the end (h-th position)
            swap(nums[m], nums[h]);
            h--;    // shrink 2s boundary
            // Do not increment m here, as swapped element needs to be checked
        }
    }
}

/*
Alternative Approaches:
-----------------------
1. Counting Sort (Two Passes, O(n) time, O(1) space):
    - Count number of 0s, 1s, and 2s in the array.
    - Overwrite the array with counted number of 0s, then 1s, then 2s.
    - Code:
        void sort0s1s2s_counting(vector<int>& nums) {
            int count0 = 0, count1 = 0, count2 = 0;
            for (int num : nums) {
                if (num == 0) count0++;
                else if (num == 1) count1++;
                else count2++;
            }
            int i = 0;
            while (count0--) nums[i++] = 0;
            while (count1--) nums[i++] = 1;
            while (count2--) nums[i++] = 2;
        }
    - Pros: Simple, easy to implement.
    - Cons: Requires two passes, not in-place if you want to preserve original array.

2. STL sort (Not optimal for this problem):
    - Use std::sort(nums.begin(), nums.end());
    - Time complexity O(n log n), not optimal as we can do O(n).

Dutch National Flag is optimal for this problem: O(n) time, O(1) space, single pass.
*/

/*
Dry Run Example:
----------------
Input: [2, 0, 2, 1, 1, 0]
Initial: l=0, m=0, h=5

Step 1: m=0, nums[m]=2 -> swap(nums[0], nums[5]) => [0, 0, 2, 1, 1, 2], h=4
Step 2: m=0, nums[m]=0 -> swap(nums[0], nums[0]) => [0, 0, 2, 1, 1, 2], l=1, m=1
Step 3: m=1, nums[m]=0 -> swap(nums[1], nums[1]) => [0, 0, 2, 1, 1, 2], l=2, m=2
Step 4: m=2, nums[m]=2 -> swap(nums[2], nums[4]) => [0, 0, 1, 1, 2, 2], h=3
Step 5: m=2, nums[m]=1 -> m=3
Step 6: m=3, nums[m]=1 -> m=4

Final: [0, 0, 1, 1, 2, 2]
*/

int main() {
    vector<int> arr{2, 0, 2, 1, 1, 0}; // Input array containing 0s, 1s, and 2s
    sort0s1sand2s(arr);                 // Sort the array using Dutch National Flag algorithm

    // Output the sorted array
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    return 0;
}