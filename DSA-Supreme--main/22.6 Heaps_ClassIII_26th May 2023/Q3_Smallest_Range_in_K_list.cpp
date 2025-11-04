/*
================================================================================
Approach Used: Smallest Range Covering Elements from K Lists using Min Heap
================================================================================
- We are given k sorted lists (arrays).
- The goal is to find the smallest range [start, end] such that at least one number from each of the k lists is included in this range.

Logic:
------
- Use a min heap (priority_queue with custom comparator) to always extract the minimum element among the current heads of all lists.
- Track the current maximum element among the heads of all lists.
- At each step, the range is [min, max]. If this range is smaller than the previously found range, update the answer.
- Move forward in the list from which the minimum element was extracted, and insert the next element from that list into the heap.
- Stop when any list is exhausted (since we can't cover all lists anymore).

Time Complexity: O(N * log K), where N = total number of elements, K = number of lists.
Space Complexity: O(K) for the heap.

================================================================================
Better Alternatives:
================================================================================
1. **Brute Force (Not recommended):**
   - Generate all possible ranges by picking one element from each list and find the minimum range.
   - Time: O(n^k), not feasible for large k.

2. **Using Pointers and Sorting:**
   - Flatten all elements with their list index, sort them, and use a sliding window to find the smallest range covering all lists.
   - Time: O(N log N), but more complex to implement and higher space.

   // Example code for alternative approach:
   /*
   vector<int> smallestRange(vector<vector<int>>& nums) {
       vector<pair<int, int>> all;
       for (int i = 0; i < nums.size(); ++i)
           for (int x : nums[i])
               all.push_back({x, i});
       sort(all.begin(), all.end());
       vector<int> count(nums.size(), 0);
       int total = 0, left = 0, minRange = INT_MAX, start = -1, end = -1;
       for (int right = 0; right < all.size(); ++right) {
           if (++count[all[right].second] == 1) ++total;
           while (total == nums.size()) {
               if (all[right].first - all[left].first < minRange) {
                   minRange = all[right].first - all[left].first;
                   start = all[left].first;
                   end = all[right].first;
               }
               if (--count[all[left++].second] == 0) --total;
           }
       }
       return {start, end};
   }
   */

================================================================================
Dry Run Example:
================================================================================
Input: nums = [[4,10,15,24,26],[0,9,12,20],[5,18,22,30]]
Step 1: Insert first elements: 4(from 0), 0(from 1), 5(from 2). min=0, max=5, range=[0,5]
Step 2: Pop 0, insert 9 (from list 1). Heap: 4,5,9. max=9, min=4, range=[4,9]
Step 3: Pop 4, insert 10 (from list 0). Heap: 5,9,10. max=10, min=5, range=[5,10]
Step 4: Pop 5, insert 18 (from list 2). Heap: 9,10,18. max=18, min=9, range=[9,18]
...
Continue until one list is exhausted. The smallest range found is [20,24].

================================================================================
Code with Detailed Comments:
================================================================================
*/

#include <vector>
#include <queue>
#include <climits>
using namespace std;

// Node class to store value, row (list index), and col (element index in list)
class node {
public:
    int data; // Value of the element
    int row;  // Index of the list
    int col;  // Index within the list
    node(int d, int r, int c) : data(d), row(r), col(c) {}
};

// Comparator for min heap (priority_queue)
class compare {
public:
    bool operator()(node* a, node* b) {
        return a->data > b->data; // Min heap based on data value
    }
};

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int mini = INT_MAX; // To track current minimum in heap
        int maxi = INT_MIN; // To track current maximum among heap elements

        // Min heap to store the current element from each list
        priority_queue<node*, vector<node*>, compare> minHeap;

        int k = nums.size(); // Number of lists

        // Insert the first element of each list into the min heap
        for (int i = 0; i < k; i++) {
            int element = nums[i][0];
            maxi = max(maxi, element); // Update current maximum
            mini = min(mini, element); // Update current minimum
            minHeap.push(new node(element, i, 0)); // Push node with value, list index, and element index
        }

        // Initialize answer range with the initial min and max
        int ansStart = mini;
        int ansEnd = maxi;

        // Main loop: Continue until any list is exhausted
        while (!minHeap.empty()) {
            // Get the node with the minimum value
            node* top = minHeap.top();
            minHeap.pop();

            mini = top->data; // The popped element is the new minimum

            // If the current range [mini, maxi] is smaller than the previous answer, update answer
            if (maxi - mini < ansEnd - ansStart) {
                ansStart = mini;
                ansEnd = maxi;
            }

            // Move to the next element in the same list (if exists)
            if (top->col + 1 < nums[top->row].size()) {
                int nextVal = nums[top->row][top->col + 1]; // Next element in the same list
                maxi = max(maxi, nextVal); // Update current maximum if needed
                minHeap.push(new node(nextVal, top->row, top->col + 1)); // Push new node into heap
            } else {
                // If any list is exhausted, we cannot include all lists in the range anymore
                break;
            }
        }

        // Prepare the answer as a vector
        vector<int> ans;
        ans.push_back(ansStart);
        ans.push_back(ansEnd);
        return ans;
    }
}

/*
================================================================================
Dry Run Example:
================================================================================
Input: nums = [[4,10,15,24,26],[0,9,12,20],[5,18,22,30]]

Initial heap: [0 (list1), 4 (list0), 5 (list2)], mini=0, maxi=5, ans=[0,5]
Pop 0, push 9 (list1): heap=[4,5,9], mini=4, maxi=9, ans=[4,9]
Pop 4, push 10 (list0): heap=[5,9,10], mini=5, maxi=10, ans=[5,10]
Pop 5, push 18 (list2): heap=[9,10,18], mini=9, maxi=18, ans=[9,18]
Pop 9, push 12 (list1): heap=[10,12,18], mini=10, maxi=18, ans=[10,18]
Pop 10, push 15 (list0): heap=[12,15,18], mini=12, maxi=18, ans=[12,18]
Pop 12, push 20 (list1): heap=[15,18,20], mini=15, maxi=20, ans=[15,20]
Pop 15, push 24 (list0): heap=[18,20,24], mini=18, maxi=24, ans=[18,24]
Pop 18, push 22 (list2): heap=[20,22,24], mini=20, maxi=24, ans=[20,24] (smallest range)
Pop 20, push 26 (list1): heap=[22,24,26], mini=22, maxi=26, ans=[20,24]
Pop 22, push 30 (list2): heap=[24,26,30], mini=24, maxi=30, ans=[20,24]
Pop 24, push 15 (list0): list0 exhausted, break.

Final answer: [20,24]
================================================================================
*/