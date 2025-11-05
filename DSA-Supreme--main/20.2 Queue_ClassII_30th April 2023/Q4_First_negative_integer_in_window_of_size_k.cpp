/*
Approach (Using Only Queue):
----------------------------
1. Maintain a queue of negative numbers currently in the window.
2. Traverse the array:
   - Add arr[i] to queue if it’s negative.
   - Once the window size reaches k:
        - The front of the queue gives the first negative number.
        - Remove arr[i - k + 1] (the element going out) from queue if it matches the front.
3. Print 0 if the queue is empty.

Time Complexity: O(n)
Space Complexity: O(k)
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> firstNegativeInWindow(vector<int>& arr, int k) {
    queue<int> q; // stores negative numbers
    vector<int> ans;
    int n = arr.size();

    for (int i = 0; i < n; i++) {
        // Step 1: push negative element to queue
        if (arr[i] < 0)
            q.push(arr[i]);

        // Step 2: start recording answers once we reach window size k
        if (i >= k - 1) {
            // If queue is not empty → front is first negative
            if (!q.empty())
                ans.push_back(q.front());
            else
                ans.push_back(0);

            // Step 3: remove outgoing element from window
            if (!q.empty() && arr[i - k + 1] == q.front())
                q.pop();
        }
    }
    return ans;
}

int main() {
    vector<int> arr = {12, -1, -7, 8, -15, 30, 16, 28};
    int k = 3;

    vector<int> result = firstNegativeInWindow(arr, k);

    cout << "First negative in every window of size " << k << ":\n";
    for (int x : result)
        cout << x << " ";
    cout << "\n";

    /*
    Dry Run:
    -------------------
    arr = [12, -1, -7, 8, -15, 30, 16, 28], k = 3
    Windows:
    [12, -1, -7]  → -1
    [-1, -7, 8]   → -1
    [-7, 8, -15]  → -7
    [8, -15, 30]  → -15
    [-15, 30, 16] → -15
    [30, 16, 28]  → 0
    Output: -1 -1 -7 -15 -15 0
    */
}