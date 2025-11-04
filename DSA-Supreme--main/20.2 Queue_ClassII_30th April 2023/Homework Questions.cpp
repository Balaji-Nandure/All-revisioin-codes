/*
1) Problem: Solve first negative integer in every window of size = k with the help of queue.

Approach Used:
----------------
- We use a queue to keep track of the indices of negative numbers in the current window.
- As we slide the window, we enqueue the index if the current element is negative.
- For each window, the front of the queue gives the index of the first negative integer in that window.
- If the queue is empty for a window, it means there is no negative integer in that window.

Better Alternatives:
---------------------
- Instead of storing indices, we can store the actual negative values, but indices help in efficiently removing elements that are out of the current window.
- A brute force approach would be to check every window and scan for the first negative integer, which is O(n*k) time complexity.
- The queue-based approach is O(n) time complexity.

Code Implementation:
---------------------
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Function to print first negative integer in every window of size k
vector<int> firstNegativeInWindow(vector<int>& arr, int k) {
    vector<int> result; // To store the answer for each window
    queue<int> q; // To store indices of negative numbers

    int n = arr.size();

    // Process first window of size k
    for(int i = 0; i < k; ++i) {
        if(arr[i] < 0) {
            q.push(i); // Store index of negative number
        }
    }

    // For the first window
    if(!q.empty()) {
        result.push_back(arr[q.front()]); // First negative integer in the window
    } else {
        result.push_back(0); // No negative integer in the window
    }

    // Process rest of the windows
    for(int i = k; i < n; ++i) {
        // Remove indices which are out of this window
        while(!q.empty() && q.front() <= i - k) {
            q.pop();
        }

        // Add current element if it is negative
        if(arr[i] < 0) {
            q.push(i);
        }

        // Append the answer for current window
        if(!q.empty()) {
            result.push_back(arr[q.front()]);
        } else {
            result.push_back(0);
        }
    }

    return result;
}

/*
Alternative Approach (Brute Force, Not Recommended):
----------------------------------------------------
for(int i = 0; i <= n-k; ++i) {
    bool found = false;
    for(int j = i; j < i+k; ++j) {
        if(arr[j] < 0) {
            result.push_back(arr[j]);
            found = true;
            break;
        }
    }
    if(!found) result.push_back(0);
}
Time Complexity: O(n*k)
*/

// Dry Run Example:
// arr = {12, -1, -7, 8, 15, 30, 16, 28}, k = 3
// Window 1: [12, -1, -7] -> First negative: -1
// Window 2: [-1, -7, 8] -> First negative: -1
// Window 3: [-7, 8, 15] -> First negative: -7
// Window 4: [8, 15, 30] -> No negative: 0
// Window 5: [15, 30, 16] -> No negative: 0
// Window 6: [30, 16, 28] -> No negative: 0
// Output: -1 -1 -7 0 0 0
2) Solve non-repeated character in a stream.
