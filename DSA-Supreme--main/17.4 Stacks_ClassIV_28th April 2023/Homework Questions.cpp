/*
Approach Used: Monotonic Stack (Optimal O(n) Solution)
------------------------------------------------------
This code demonstrates the "Next Greater Element" (NGE) problem using a monotonic decreasing stack.
For each element in the array, we want to find the next element to its right which is greater than itself.

Key Logic:
----------
- We use a stack to keep track of indices of elements for which we haven't found the NGE yet.
- As we iterate through the array, if the current element is greater than the element at the index on top of the stack,
  then the current element is the NGE for that index. We update the result and pop the index.
- We repeat this until the stack is empty or the current element is not greater.
- Finally, we push the current index onto the stack.

This approach ensures each element is pushed and popped at most once, giving O(n) time complexity.

*/

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// Function to find Next Greater Element for each element in the array
vector<int> nextGreaterElement(vector<int>& nums) {
    stack<int> st; // Stack to store indices of elements whose NGE is not found yet
    vector<int> res(nums.size(), -1); // Initialize result with -1 (if no NGE exists)

    for(int i = 0; i < nums.size(); i++) {
        // While stack is not empty and current element is greater than element at index on top of stack
        while(!st.empty() && nums[i] > nums[st.top()]) {
            res[st.top()] = nums[i]; // Current element is the NGE for index at top of stack
            st.pop(); // Remove index as its NGE is found
        }
        st.push(i); // Push current index to stack for future NGE checks
    }
    // Remaining indices in stack have no NGE, so res[] remains -1 for them
    return res;
}

/*
-------------------------------
Better Alternatives & Variations
-------------------------------

1. Brute Force Approach (O(n^2)):
---------------------------------
For each element, scan all elements to its right to find the next greater.
Not efficient for large inputs.

Code:
------
vector<int> bruteForceNGE(vector<int>& nums) {
    vector<int> res(nums.size(), -1);
    for(int i = 0; i < nums.size(); i++) {
        for(int j = i+1; j < nums.size(); j++) {
            if(nums[j] > nums[i]) {
                res[i] = nums[j];
                break;
            }
        }
    }
    return res;
}

2. Circular Array NGE (for problems like Leetcode 503):
-------------------------------------------------------
If the array is circular, we can simulate two passes.

Code:
------
vector<int> circularNGE(vector<int>& nums) {
    int n = nums.size();
    vector<int> res(n, -1);
    stack<int> st;
    for(int i = 0; i < 2*n; i++) {
        int idx = i % n;
        while(!st.empty() && nums[idx] > nums[st.top()]) {
            res[st.top()] = nums[idx];
            st.pop();
        }
        if(i < n) st.push(idx);
    }
    return res;
}

3. Next Smaller Element (NSE) / Previous Greater/Smaller Element:
-----------------------------------------------------------------
- Use similar logic but change the comparison operator.
- For NSE, use nums[i] < nums[st.top()].
- For Previous Greater/Smaller, traverse from left to right.

4. Min Stack Design (O(1) getMin):
----------------------------------
Use two stacks: one for all values, one for current minimums.

Code:
------
stack<int> s, minS;
void push(int val) {
    s.push(val);
    if(minS.empty() || val <= minS.top()) minS.push(val);
}
void pop() {
    if(s.top() == minS.top()) minS.pop();
    s.pop();
}
int getMin() { return minS.top(); }

5. Sorting a Stack using Recursion:
-----------------------------------
See Q4_Sort_a_stack.cpp for details. The idea is to pop all elements recursively and insert them in sorted order.

-------------------------------
Dry Run Example (Next Greater Element)
-------------------------------

Input: nums = [4, 5, 2, 25]
Stack: stores indices

Step 1: i=0, nums[0]=4, stack=[], push 0
    st = [0]
Step 2: i=1, nums[1]=5 > nums[0]=4
    res[0]=5, pop 0, push 1
    st = [1]
Step 3: i=2, nums[2]=2 < nums[1]=5
    push 2
    st = [1,2]
Step 4: i=3, nums[3]=25 > nums[2]=2
    res[2]=25, pop 2
    nums[3]=25 > nums[1]=5
    res[1]=25, pop 1, push 3
    st = [3]
End: res = [5, 25, 25, -1]

-------------------------------
Summary:
-------------------------------
- Monotonic stack is optimal for NGE/NSE problems (O(n)).
- Brute force is simple but slow (O(n^2)).
- For circular arrays, simulate two passes.
- For Min Stack, use two stacks or encode min in a single stack.
- Practice all stack applications: expression evaluation, parentheses matching, stock span, sorting stack, etc.
*/
