// https://leetcode.com/problems/sort-colors/description/

/*
Approach Used: Dutch National Flag Algorithm (Three Pointer Approach)
---------------------------------------------------------------
This problem is a classic example of the Dutch National Flag problem. 
We need to sort an array containing only 0s, 1s, and 2s in-place and in a single pass.

Key Idea:
- Use three pointers:
    - s (start): boundary for 0s (left side)
    - m (mid): current element under consideration
    - e (end): boundary for 2s (right side)
- Traverse the array with 'm' and swap elements to their correct region:
    - If nums[m] == 0: swap with s, increment both s and m
    - If nums[m] == 1: just move m forward
    - If nums[m] == 2: swap with e, decrement e (do not increment m, as swapped value needs to be checked)

Time Complexity: O(n)
Space Complexity: O(1) (in-place)

Other Approaches (with code in comments):
-----------------------------------------
1. Counting Sort (Two Passes):
   - Count number of 0s, 1s, and 2s, then overwrite the array.
   - Code:
        // int zeroCount = 0, oneCount = 0, twoCount = 0;
        // for(int num : nums) {
        //     if(num == 0) zeroCount++;
        //     else if(num == 1) oneCount++;
        //     else twoCount++;
        // }
        // int i = 0;
        // while(zeroCount--) nums[i++] = 0;
        // while(oneCount--) nums[i++] = 1;
        // while(twoCount--) nums[i++] = 2;

2. Using STL sort (Not optimal for this problem, O(n log n)):
   - Code:
        // sort(nums.begin(), nums.end());

Dutch National Flag Algorithm (Optimal, One Pass, In-place):
------------------------------------------------------------
*/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int s = 0;                  // 's' marks the next position for 0
        int m = 0;                  // 'm' is the current index being checked
        int e = nums.size() - 1;    // 'e' marks the next position for 2

        // Traverse the array until m crosses e
        while(m <= e){
            if(nums[m] == 0){
                // If current element is 0, swap it to the front (s-th position)
                swap(nums[s], nums[m]);
                s++;    // Move s to next position for 0
                m++;    // Move m to next element
            }
            else if(nums[m] == 1){
                // If current element is 1, it's already in correct region
                m++;    // Just move to next element
            }
            else if(nums[m] == 2){
                // If current element is 2, swap it to the end (e-th position)
                swap(nums[m], nums[e]);
                e--;    // Move e to previous position for 2
                // Do not increment m here, as the swapped element at m needs to be checked
            }
        }
    }
};

/*
Dry Run Example:
----------------
Input: nums = [2,0,2,1,1,0]

Initial: s=0, m=0, e=5

Step 1: m=0, nums[m]=2 -> swap(nums[0], nums[5]) => [0,0,2,1,1,2], e=4
Step 2: m=0, nums[m]=0 -> swap(nums[0], nums[0]) => [0,0,2,1,1,2], s=1, m=1
Step 3: m=1, nums[m]=0 -> swap(nums[1], nums[1]) => [0,0,2,1,1,2], s=2, m=2
Step 4: m=2, nums[m]=2 -> swap(nums[2], nums[4]) => [0,0,1,1,2,2], e=3
Step 5: m=2, nums[m]=1 -> m=3
Step 6: m=3, nums[m]=1 -> m=4

Loop ends (m > e). Final array: [0,0,1,1,2,2]
*/