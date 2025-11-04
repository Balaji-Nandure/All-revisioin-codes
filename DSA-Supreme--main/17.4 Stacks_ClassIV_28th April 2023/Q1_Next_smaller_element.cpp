// ----------- we need the *next* smaller element (first smaller to the right).----------



// Input:  [2, 1, 4, 3]
// Output: [1, -1, 3, -1]

// Approach:
// ----------
// - Traverse array from right to left.
// - Use a stack to maintain elements in increasing order.
// - For each element:
//     - Pop elements >= current (they can’t be next smaller).
//     - If stack not empty → top is next smaller.
//     - Push current element.
// - O(n) time, O(n) space.


#include <bits/stdc++.h>
using namespace std;

// Function to find next smaller element for each element in vector
vector<int> nextSmallerElements(const vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n, -1);  // Default -1 for no smaller element
    stack<int> st;              // Monotonic stack to track next smaller

    for (int i = n - 1; i >= 0; --i) {
        // Pop until we find a smaller element
        while (!st.empty() && st.top() >= nums[i]) {
            st.pop();
        }

        // If stack is not empty, top is next smaller
        if (!st.empty()) result[i] = st.top();

        // Push current element for future iterations
        st.push(nums[i]);
    }
    return result;
}

int main() {
    vector<int> v = {2, 1, 4, 3};
    auto ans = nextSmallerElements(v);

    cout << "Next smaller elements: ";
    for (int x : ans) cout << x << " ";
    cout << "\n";

    return 0;
}
