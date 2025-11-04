/*
Approach:
----------
- For each bar, we need to find:
    1. Previous Smaller *Element index* (to the left)
    2. Next Smaller *Element index* (to the right)
- Width of rectangle = nextSmaller[i] - prevSmaller[i] - 1
- Area for bar i = height[i] * width
- Take max over all bars.
- Time: O(n), Space: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

// Function to find Previous Smaller Element indices
vector<int> prevSmallerIndex(const vector<int>& a) {
    int n = a.size();
    vector<int> res(n, -1);
    stack<int> st;
    for (int i = 0; i < n; ++i) {
        while (!st.empty() && a[st.top()] >= a[i]) st.pop();
        if (!st.empty()) res[i] = st.top();
        st.push(i);
    }
    return res;
}

// Function to find Next Smaller Element indices
vector<int> nextSmallerIndex(const vector<int>& a) {
    int n = a.size();
    vector<int> res(n, n);
    stack<int> st;
    for (int i = n - 1; i >= 0; --i) {
        while (!st.empty() && a[st.top()] >= a[i]) st.pop();
        if (!st.empty()) res[i] = st.top();
        st.push(i);
    }
    return res;
}

int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    vector<int> pre = prevSmallerIndex(heights);
    vector<int> nxt = nextSmallerIndex(heights);

    int maxArea = 0;
    for (int i = 0; i < n; ++i) {
        int width = nxt[i] - pre[i] - 1;
        int area = heights[i] * width;
        maxArea = max(maxArea, area);
    }
    return maxArea;
}

int main() {
    vector<int> heights = {2, 1, 5, 6, 2, 3};
    cout << "Largest Rectangle Area: " << largestRectangleArea(heights) << "\n";
}
