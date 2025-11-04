/*
Approach:
----------
- Traverse array from left to right.
- Maintain a monotonic increasing stack.
- While stack.top() >= current, pop.
- If stack not empty → top = previous smaller.
- Push current element.
- Time: O(n), Space: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> prevSmaller(const vector<int>& a) {
    int n = a.size();
    vector<int> res(n, -1);
    stack<int> st;
    for (int i = 0; i < n; ++i) {
        while (!st.empty() && st.top() >= a[i]) st.pop();
        if (!st.empty()) res[i] = st.top();
        // if if stack is empty then it res[i]=-1. as initialisation.
        st.push(a[i]);
    }
    return res;
}

int main() {
    vector<int> v = {2, 1, 4, 3};
    for (int x : prevSmaller(v)) cout << x << " ";
    cout << "\n";
}
