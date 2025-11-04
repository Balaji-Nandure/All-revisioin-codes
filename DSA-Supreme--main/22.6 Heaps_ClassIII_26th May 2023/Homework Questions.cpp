/*
1) Median in a Data Stream

Approach Used:
----------------
We use two heaps to efficiently find the median in a stream of numbers:
    - A max-heap (to store the smaller half of the numbers)
    - A min-heap (to store the larger half of the numbers)
This allows us to always access the middle elements in O(1) time and insert in O(log n) time.

Logic:
------
- The max-heap (let's call it 'left') contains the smaller half of the numbers (max at top).
- The min-heap (let's call it 'right') contains the larger half of the numbers (min at top).
- For every new number:
    - If the number is less than or equal to the max of 'left', push to 'left'.
    - Else, push to 'right'.
    - Balance the heaps so that their sizes differ by at most 1.
- The median is:
    - If both heaps are of equal size, the average of the tops of both heaps.
    - If not, the top of the heap with more elements.

Implementation:
---------------
*/

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class MedianFinder {
    // Max-heap for the lower half
    priority_queue<int> left;
    // Min-heap for the upper half
    priority_queue<int, vector<int>, greater<int>> right;

public:
    // Adds a number into the data structure.
    void addNum(int num) {
        // If left is empty or num is less than or equal to max of left, push to left
        if(left.empty() || num <= left.top()) {
            left.push(num);
        } else {
            // Else, push to right
            right.push(num);
        }

        // Balance the heaps so that their sizes differ by at most 1
        if(left.size() > right.size() + 1) {
            right.push(left.top());
            left.pop();
        } else if(right.size() > left.size()) {
            left.push(right.top());
            right.pop();
        }
    }

    // Returns the median of current data stream
    double findMedian() {
        if(left.size() == right.size()) {
            // If even number of elements, median is average of two middle elements
            return (left.top() + right.top()) / 2.0;
        } else {
            // If odd, median is the top of the heap with more elements
            return left.top();
        }
    }
};

/*
Alternative Approaches:
-----------------------
1. Brute Force:
    - Store all numbers in a vector, sort after every insertion, and pick the middle element(s).
    - Time Complexity: O(n log n) per insertion (inefficient for large streams).

2. Multiset Approach:
    - Use a multiset and maintain an iterator to the median.
    - Insertion: O(log n), Median: O(1).
    - More code complexity, but similar performance to the heap approach.

Sample Code for Multiset Approach:
----------------------------------
#include <set>
class MedianFinder {
    multiset<int> data;
    multiset<int>::iterator mid;
public:
    MedianFinder() : mid(data.end()) {}
    void addNum(int num) {
        int n = data.size();
        data.insert(num);
        if(n == 0) {
            mid = data.begin();
        } else if(num < *mid) {
            if(n % 2 == 0) --mid;
        } else {
            if(n % 2 == 1) ++mid;
        }
    }
    double findMedian() {
        int n = data.size();
        if(n % 2 == 1) return *mid;
        else return (*mid + *next(mid)) / 2.0;
    }
};

Dry Run Example:
----------------
Input: [5, 15, 1, 3]
Step 1: addNum(5)
    left: [5], right: []
    Median: 5
Step 2: addNum(15)
    left: [5], right: [15]
    Median: (5+15)/2 = 10
Step 3: addNum(1)
    left: [5,1], right: [15]
    Median: 5
Step 4: addNum(3)
    left: [3,1], right: [5,15]
    Median: (3+5)/2 = 4

This approach ensures O(log n) insertion and O(1) median retrieval.
*/
