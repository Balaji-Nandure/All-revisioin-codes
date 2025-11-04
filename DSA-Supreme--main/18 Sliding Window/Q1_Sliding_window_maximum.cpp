/*
Approach Used: Monotonic Deque (Optimal O(n) Solution)
------------------------------------------------------
We solve the "Sliding Window Maximum" problem using a monotonic deque (double-ended queue).
The deque stores indices of elements in the current window, always in decreasing order of their values.
- The front of the deque always contains the index of the maximum element for the current window.
- For each new element, we remove indices from the back whose corresponding values are less than the current value (since they can never be the maximum for any future window).
- We also remove indices from the front if they are out of the current window's range.

Why this works:
---------------
- Each element is pushed and popped at most once, so the time complexity is O(n).
- The deque always contains indices of elements that are potential maximums for the current or future windows.

Better Alternatives & Detailed Approaches:
------------------------------------------
1. **Brute Force (O(n*k)):**
   For each window, scan all k elements to find the maximum.
   ```
   vector<int> maxSlidingWindow(vector<int>& nums, int k) {
       vector<int> ans;
       for(int i = 0; i <= nums.size() - k; i++) {
           int mx = nums[i];
           for(int j = i; j < i + k; j++) {
               mx = max(mx, nums[j]);
           }
           ans.push_back(mx);
       }
       return ans;
   }
   ```
   - Not efficient for large inputs.

2. **Multiset/Heap (O(n*logk)):**
   Use a multiset or max-heap to keep track of the k elements in the window.
   ```
   vector<int> maxSlidingWindow(vector<int>& nums, int k) {
       multiset<int> window;
       vector<int> ans;
       for(int i = 0; i < nums.size(); i++) {
           window.insert(nums[i]);
           if(i >= k-1) {
               ans.push_back(*window.rbegin());
               window.erase(window.find(nums[i-k+1]));
           }
       }
       return ans;
   }
   ```
   - Slightly better, but still not optimal.

3. **Block Preprocessing (O(n)):**
   Precompute max from left and right for each block of size k, then answer each window in O(1).
   - More complex to implement, but also O(n).

-------------------
Code with Comments:
-------------------
*/

#include <vector>
#include <deque>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq; // Stores indices of useful elements for current window, in decreasing order of value
        vector<int> ans; // Stores the maximum for each window

        // Process the first k elements (first window)
        for(int i = 0; i < k; i++) {
            // Remove indices from back whose corresponding values are less than current value
            while(!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }
            // Add current index to the deque
            dq.push_back(i);
        }
        // The element at the front of the deque is the maximum for the first window
        ans.push_back(nums[dq.front()]);

        // Process the rest of the elements (remaining windows)
        for(int i = k; i < nums.size(); i++) {
            // Remove indices from front if they are out of the current window
            if(!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }
            // Remove indices from back whose corresponding values are less than current value
            while(!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }
            // Add current index to the deque
            dq.push_back(i);
            // The element at the front of the deque is the maximum for the current window
            ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};

/*
-------------------
Dry Run Example:
-------------------
Input: nums = [1,3,-1,-3,5,3,6,7], k = 3

Step-by-step:
i=0: dq=[0] (nums[0]=1)
i=1: nums[1]=3 > nums[0]=1, pop 0, dq=[], push 1 => dq=[1]
i=2: nums[2]=-1 < nums[1]=3, push 2 => dq=[1,2]
First window: ans=[nums[1]]=3

i=3: window is [3,-1,-3], dq.front()=1, but 1 <= 3-3=0 is false, so keep. nums[3]=-3 < nums[2]=-1, push 3 => dq=[1,2,3]
      Now, dq.front()=1, which is in window, ans.push_back(nums[1])=3

i=4: window is [-1,-3,5], dq.front()=1, 1 <= 4-3=1, so pop 1. Now, nums[4]=5 > nums[3]=-3, pop 3; nums[4]=5 > nums[2]=-1, pop 2; dq=[], push 4 => dq=[4]
      ans.push_back(nums[4])=5

i=5: window is [-3,5,3], dq.front()=4, 4 <= 5-3=2 is false, nums[5]=3 < nums[4]=5, push 5 => dq=[4,5]
      ans.push_back(nums[4])=5

i=6: window is [5,3,6], dq.front()=4, 4 <= 6-3=3 is false, nums[6]=6 > nums[5]=3, pop 5; nums[6]=6 > nums[4]=5, pop 4; dq=[], push 6 => dq=[6]
      ans.push_back(nums[6])=6

i=7: window is [3,6,7], dq.front()=6, 6 <= 7-3=4 is false, nums[7]=7 > nums[6]=6, pop 6; dq=[], push 7 => dq=[7]
      ans.push_back(nums[7])=7

Output: [3,3,5,5,6,7]
*/