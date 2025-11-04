
/*
Approach and Explanation for Each Problem:

1) make_heap and heapify methods in C++ STL:
------------------------------------------------
- make_heap: Converts a range into a heap in-place. By default, it creates a max-heap.
- heapify: Not directly available in STL, but the process is similar to adjusting a subtree to maintain the heap property.

Example:
*/

#include <iostream>
#include <vector>
#include <algorithm> // for make_heap, push_heap, pop_heap

// Function to print a vector
void printVector(const std::vector<int>& v) {
    for (int n : v) std::cout << n << " ";
    std::cout << std::endl;
}

void demo_make_heap() {
    std::vector<int> v = {3, 1, 4, 1, 5, 9, 2};
    // make_heap rearranges the elements into a max-heap
    std::make_heap(v.begin(), v.end());
    std::cout << "Heap created using make_heap: ";
    printVector(v);

    // To insert a new element and maintain heap property:
    v.push_back(6);
    std::push_heap(v.begin(), v.end()); // Restores heap property after insertion
    std::cout << "After push_heap (insert 6): ";
    printVector(v);

    // To remove the largest element:
    std::pop_heap(v.begin(), v.end()); // Moves largest to end
    v.pop_back(); // Actually removes it
    std::cout << "After pop_heap (remove max): ";
    printVector(v);
}

/*
Alternative: Priority Queue (simpler interface for heaps)
#include <queue>
std::priority_queue<int> pq;
pq.push(3); pq.push(1); pq.push(4);
pq.top(); // returns largest element
pq.pop(); // removes largest element
*/

/*
2) Minimum cost of cutting ropes (Same pattern as reorganize string)
--------------------------------------------------------------------
Approach:
- Always combine the two smallest ropes first (greedy approach).
- Use a min-heap (priority_queue with greater<int>) to efficiently get the smallest ropes.
- At each step, add the cost of combining ropes to total cost, and push the combined rope back to heap.

Code:
*/

#include <queue>

int minCostToCutRopes(std::vector<int>& ropes) {
    // Min-heap to always get the two smallest ropes
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap(ropes.begin(), ropes.end());
    int totalCost = 0;

    // Continue until only one rope remains
    while (minHeap.size() > 1) {
        int first = minHeap.top(); minHeap.pop(); // Smallest rope
        int second = minHeap.top(); minHeap.pop(); // Second smallest
        int cost = first + second; // Cost to combine
        totalCost += cost; // Add to total cost
        minHeap.push(cost); // Push combined rope back
    }
    return totalCost;
}

/*
Alternative:
- This is the optimal approach (greedy + min-heap).
- Any other approach (e.g., combining random ropes) will not guarantee minimum cost.

Dry Run Example:
Ropes: [4, 3, 2, 6]
Step 1: Combine 2+3=5 (cost=5), heap=[4,5,6], total=5
Step 2: Combine 4+5=9 (cost=9), heap=[6,9], total=14
Step 3: Combine 6+9=15 (cost=15), heap=[15], total=29
Final answer: 29
*/

/*
3) Time complexity of median in a stream
-----------------------------------------
Approach:
- Use two heaps:
    - Max-heap for lower half
    - Min-heap for upper half
- For each new number:
    - Insert into appropriate heap
    - Balance the heaps (size difference at most 1)
    - Median is either the top of one heap or average of tops

Time Complexity:
- Insertion: O(log n) (heap insertion)
- Median retrieval: O(1) (peek top(s) of heap)

Code:
*/

class MedianFinder {
    std::priority_queue<int> maxHeap; // lower half (max-heap)
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap; // upper half (min-heap)
public:
    void addNum(int num) {
        // Add to maxHeap first
        if (maxHeap.empty() || num <= maxHeap.top())
            maxHeap.push(num);
        else
            minHeap.push(num);

        // Balance the heaps
        if (maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        } else if (minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }

    double findMedian() {
        if (maxHeap.size() == minHeap.size())
            return (maxHeap.top() + minHeap.top()) / 2.0;
        else
            return maxHeap.top();
    }
};

/*
Alternative:
- Brute force: Store all numbers, sort on each query (O(n log n) per query) -- not efficient.
- The two-heap approach is optimal for online median.

Dry Run Example:
Stream: 5, 15, 1, 3
Insert 5: maxHeap=[5], minHeap=[]
Median: 5
Insert 15: maxHeap=[5], minHeap=[15]
Median: (5+15)/2=10
Insert 1: maxHeap=[5,1], minHeap=[15]
Median: 5
Insert 3: maxHeap=[3,1], minHeap=[5,15]
Median: (3+5)/2=4
*/
