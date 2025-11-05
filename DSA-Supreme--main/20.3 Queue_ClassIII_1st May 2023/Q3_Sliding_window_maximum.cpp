/*
Approach:
----------
We want the maximum of each window of size k.

1️⃣ Use a deque (double-ended queue) to store indices of useful elements.
    - The deque will always store indices in **decreasing order of values**.
2️⃣ For each index i:
    - Remove elements from the **front** if they are outside the window (i - k).
    - Remove elements from the **back** while arr[i] >= arr[dq.back()].
      (since they will never be the max again)
    - Push current index into deque.
    - Once i >= k - 1, record arr[dq.front()] as the window maximum.
3️⃣ Return the collected results.

⏱ Time: O(n) → each element is pushed & popped at most once  
💾 Space: O(k)
*/

#include <bits/stdc++.h>  // Include standard libraries  // For deque and vector support
using namespace std;      // Use standard namespace      // Avoid std:: prefix

vector<int> slidingWindowMax(vector<int>& arr, int k) {  // Function declaration  // Takes array and window size
    deque<int> dq;        // Create deque for indices    // Stores useful element positions
    vector<int> ans;      // Create result vector        // Will store window maximums

    for (int i = 0; i < arr.size(); i++) {  // Iterate through array  // Process each element once

        // Remove out-of-window elements
        if (!dq.empty() && dq.front() <= i - k)  // Check if front is outdated  // Element outside current window
            dq.pop_front();                      // Remove outdated index        // Clean up old elements

        // Remove smaller elements from back (maintain decreasing order)
        while (!dq.empty() && arr[i] >= arr[dq.back()])  // Check if current is larger  // Maintain decreasing order
            dq.pop_back();                               // Remove smaller elements     // They won't be max anymore

        dq.push_back(i);     // Add current index        // Always add new element

        // Record max once window has size k
        if (i >= k - 1)      // Check if window is full  // Need k elements for valid window
            ans.push_back(arr[dq.front()]);  // Add maximum to result  // Front has largest element
    }
    return ans;              // Return result vector     // Contains all window maximums
}

int main() {
    vector<int> arr = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;

    vector<int> res = slidingWindowMax(arr, k);

    cout << "Sliding Window Maximums: ";
    for (int x : res)
        cout << x << " ";
    cout << "\n";

    /*
    Dry Run:
    ----------------
    arr = [1,3,-1,-3,5,3,6,7], k=3
    Windows:         Max:
    [1,3,-1]         → 3
    [3,-1,-3]        → 3
    [-1,-3,5]        → 5
    [-3,5,3]         → 5
    [5,3,6]          → 6
    [3,6,7]          → 7
    Output: 3 3 5 5 6 7
    */
}
