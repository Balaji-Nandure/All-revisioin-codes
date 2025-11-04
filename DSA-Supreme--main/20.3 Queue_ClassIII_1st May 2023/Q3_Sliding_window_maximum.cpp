/*
    Approach Used: Monotonic Deque (Optimal O(N) Solution)
    ------------------------------------------------------
    - We use a deque to keep track of indices of useful elements for each window.
    - The deque is maintained in decreasing order of values in nums.
    - For each window, the front of the deque always contains the index of the maximum element.
    - We remove indices from the back if the current element is greater than or equal to the element at those indices (since they can't be maximum for any future window).
    - We also remove indices from the front if they are out of the current window.
    - This approach ensures each element is pushed and popped at most once, giving O(N) time complexity.

    Better Alternatives:
    -------------------
    1. Brute Force: For each window, scan all k elements to find the maximum. O(N*k) time.
    2. Multiset/Heap: Use a multiset or max-heap to keep track of window elements. O(N*logk) time.
    3. Monotonic Deque (used here): O(N) time, O(k) space.

    // Brute Force Approach (for reference)
    /*
    vector<int> slidingWindowMaxBruteForce(vector<int>& nums, int k) {
        vector<int> ans;
        for(int i=0; i<=nums.size()-k; i++) {
            int mx = nums[i];
            for(int j=i; j<i+k; j++) {
                mx = max(mx, nums[j]);
            }
            ans.push_back(mx);
        }
        return ans;
    }
    */

    // Heap Approach (for reference)
    /*
    vector<int> slidingWindowMaxHeap(vector<int>& nums, int k) {
        vector<int> ans;
        priority_queue<pair<int,int>> pq; // {value, index}
        for(int i=0; i<nums.size(); i++) {
            pq.push({nums[i], i});
            if(i >= k-1) {
                while(pq.top().second <= i-k) pq.pop(); // Remove out of window
                ans.push_back(pq.top().first);
            }
        }
        return ans;
    }
    */
*/

#include<iostream>
#include<deque>
#include<vector>
using namespace std;

// Function to print the maximum of each sliding window of size k
void solve(vector<int>& nums, int k) {
    deque<int> dq; // Stores indices of potential max elements for current window
    vector<int> ans; // Stores the result

    // Process the first window of size k
    for(int i = 0; i < k; i++) {
        // Remove indices whose corresponding values are less than current element
        // as they can't be the maximum for this or any future window
        while(!dq.empty() && nums[i] >= nums[dq.back()]) {
            dq.pop_back();
        }
        dq.push_back(i); // Insert current index
    }
    // The element at the front of the deque is the largest for the first window
    ans.push_back(nums[dq.front()]);

    // Process the rest of the windows
    for(int i = k; i < nums.size(); i++) {
        // Remove indices from the front if they are out of the current window
        if(!dq.empty() && dq.front() <= i - k) {
            dq.pop_front();
        }
        // Remove indices whose corresponding values are less than current element
        while(!dq.empty() && nums[i] >= nums[dq.back()]) {
            dq.pop_back();
        }
        dq.push_back(i); // Insert current index

        // The element at the front of the deque is the largest for the current window
        ans.push_back(nums[dq.front()]);
    }

    // Print the result
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}

/*
    Dry Run:
    --------
    Input: nums = [1,3,-1,-3,5,3,6,7], k = 3

    Step-by-step:
    Window 0-2: [1,3,-1]
        - Insert 1 (dq: [0])
        - 3 >= 1, pop 0, insert 1 (dq: [1])
        - -1 < 3, insert 2 (dq: [1,2])
        - Max: nums[1] = 3

    Window 1-3: [3,-1,-3]
        - 1 is out of window, dq: [1,2]
        - -3 < -1, insert 3 (dq: [1,2,3])
        - Max: nums[1] = 3

    Window 2-4: [-1,-3,5]
        - 1 is out of window, pop 1 (dq: [2,3])
        - 5 >= -3, pop 3; 5 >= -1, pop 2; insert 4 (dq: [4])
        - Max: nums[4] = 5

    Window 3-5: [-3,5,3]
        - 4 in window, dq: [4]
        - 3 < 5, insert 5 (dq: [4,5])
        - Max: nums[4] = 5

    Window 4-6: [5,3,6]
        - 4 in window, dq: [4,5]
        - 6 >= 3, pop 5; 6 >= 5, pop 4; insert 6 (dq: [6])
        - Max: nums[6] = 6

    Window 5-7: [3,6,7]
        - 6 in window, dq: [6]
        - 7 >= 6, pop 6; insert 7 (dq: [7])
        - Max: nums[7] = 7

    Output: 3 3 5 5 6 7

*/

int main() {
    vector<int> nums{1,3,-1,-3,5,3,6,7};
    int k = 3;
    solve(nums, k);
    return 0;
}