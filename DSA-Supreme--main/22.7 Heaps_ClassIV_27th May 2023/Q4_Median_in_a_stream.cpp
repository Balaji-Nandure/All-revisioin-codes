/*
Approach Used:
---------------
We are finding the median in a stream of integers efficiently using two heaps:
    - maxHeap: stores the smaller half of the numbers (max at top)
    - minHeap: stores the larger half of the numbers (min at top)
The idea is to keep the heaps balanced in size (difference at most 1), and maintain the property that all elements in maxHeap are <= all elements in minHeap.
The median is either the top of one heap (if odd number of elements) or the average of the tops (if even).

Time Complexity: O(log n) per insertion (due to heap operations)
Space Complexity: O(n) for storing all elements in heaps

Alternative (but less efficient) approaches:
--------------------------------------------
1. Sort the array after every insertion and pick the median. This is O(n log n) per insertion.
2. Use a balanced BST (like multiset in C++), but insertion and median finding is O(log n).

Better/Alternative Approach (with code) in comments at the end.

*/

// Include necessary headers
#include <iostream>
#include <queue>
using namespace std;

// Helper function to compare sizes of two heaps
int signum(int a, int b)
{
    // Returns 0 if sizes are equal, 1 if a > b, -1 if a < b
    if (a == b)
        return 0;
    if (a > b)
        return 1;
    return -1;
}

// Function to insert element and update median
void callMedian(double &median, priority_queue<int> &maxHeap, priority_queue<int, vector<int>, greater<int>> &minHeap, int element)
{
    // Decide action based on relative sizes of heaps
    switch (signum(minHeap.size(), maxHeap.size()))
    {
    case 0: // Both heaps have equal size
        if (element > median)
        {
            // If new element is greater than current median, push to minHeap (right half)
            minHeap.push(element);
            median = minHeap.top(); // Median is top of minHeap
        }
        else
        {
            // Else, push to maxHeap (left half)
            maxHeap.push(element);
            median = maxHeap.top(); // Median is top of maxHeap
        }
        break;
    case 1: // minHeap has more elements than maxHeap
        if (element > median)
        {
            // If new element is greater than median, move minHeap's top to maxHeap to balance
            int minTop = minHeap.top();
            minHeap.pop();
            maxHeap.push(minTop);
            // Insert new element to minHeap
            minHeap.push(element);
            // Now both heaps are equal, median is average of tops
            median = ((maxHeap.top()) + (minHeap.top())) / 2.0;
        }
        else
        {
            // Else, just push to maxHeap to balance sizes
            maxHeap.push(element);
            median = ((maxHeap.top()) + (minHeap.top())) / 2.0;
        }
        break;
    case -1: // maxHeap has more elements than minHeap
        if (element > median)
        {
            // If new element is greater than median, push to minHeap to balance
            minHeap.push(element);
            median = ((maxHeap.top()) + (minHeap.top())) / 2.0;
        }
        else
        {
            // Else, move maxHeap's top to minHeap to balance, then push new element to maxHeap
            int maxTop = maxHeap.top();
            maxHeap.pop();
            minHeap.push(maxTop);
            maxHeap.push(element);
            median = ((maxHeap.top()) + (minHeap.top())) / 2.0;
        }
        break;
    }
}

int main()
{
    // Input stream of numbers
    int arr[6] = {5, 7, 2, 9, 3, 8};
    int n = 6;

    // Max-heap for left half (smaller numbers)
    priority_queue<int> maxHeap;
    // Min-heap for right half (larger numbers)
    priority_queue<int, vector<int>, greater<int>> minHeap;

    // Initially, median is 0
    double median = 0;

    // Process each element in the stream
    for (int i = 0; i < n; i++)
    {
        int element = arr[i];
        callMedian(median, maxHeap, minHeap, element); // Insert and update median
        cout << median << " "; // Output current median
    }
    cout << endl;
    return 0;
}

/*
-------------------------------
Alternative (Better) Approach:
-------------------------------
Instead of using a custom signum and switch, you can always:
1. Insert into maxHeap first.
2. Move the largest from maxHeap to minHeap.
3. If minHeap has more elements, move its smallest back to maxHeap.
4. Median is either maxHeap.top() (if odd), or average of tops (if even).

Code:
------
void addNum(int num, priority_queue<int>& maxHeap, priority_queue<int, vector<int>, greater<int>>& minHeap) {
    maxHeap.push(num);
    minHeap.push(maxHeap.top());
    maxHeap.pop();
    if (minHeap.size() > maxHeap.size()) {
        maxHeap.push(minHeap.top());
        minHeap.pop();
    }
}
double findMedian(priority_queue<int> maxHeap, priority_queue<int, vector<int>, greater<int>> minHeap) {
    if (maxHeap.size() > minHeap.size())
        return maxHeap.top();
    else
        return (maxHeap.top() + minHeap.top()) / 2.0;
}

-------------------------------
Dry Run (for arr = {5, 7, 2, 9, 3, 8}):
-------------------------------
Step 1: Insert 5
    maxHeap: [5], minHeap: []
    median = 5

Step 2: Insert 7
    7 > 5, so minHeap: [7], maxHeap: [5]
    median = (5+7)/2 = 6

Step 3: Insert 2
    2 < 6, so maxHeap: [5,2], minHeap: [7]
    median = 5

Step 4: Insert 9
    9 > 5, so minHeap: [7,9], maxHeap: [5,2]
    median = (5+7)/2 = 6

Step 5: Insert 3
    3 < 6, so maxHeap: [5,2,3], minHeap: [7,9]
    median = 5

Step 6: Insert 8
    8 > 5, so minHeap: [7,9,8], maxHeap: [5,2,3]
    median = (5+7)/2 = 6

Output: 5 6 5 6 5 6

*/