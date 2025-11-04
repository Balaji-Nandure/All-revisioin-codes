/*
    Approach Used:
    ----------------
    This code implements a Max-Heap using an array. The heap supports two main operations:
    1. Insertion: Insert a new value while maintaining the heap property (parent >= children).
    2. Deletion: Remove the root (maximum element) and re-heapify to maintain the heap property.

    - The heap is 1-indexed (arr[0] is unused or set to -1 for clarity).
    - For any node at index i:
        - Left child: 2*i
        - Right child: 2*i + 1
        - Parent: i/2

    Better Alternatives:
    --------------------
    1. Use std::priority_queue from STL for heap operations (recommended for production).
    2. Use dynamic array (vector) for flexible size.
    3. Implement both Min-Heap and Max-Heap with a flag or function pointer.
    4. Add error handling for overflow/underflow.
    5. Use heapify to build heap in O(n) time from an array.

    // Example: Using STL priority_queue (Max-Heap by default)
    /*
    #include <queue>
    priority_queue<int> pq;
    pq.push(10);
    pq.push(20);
    cout << pq.top(); // 20
    pq.pop();
    */

    // Example: Heapify an array (O(n) build)
    /*
    void heapify(int arr[], int n, int i) {
        int largest = i;
        int left = 2*i;
        int right = 2*i+1;
        if(left <= n && arr[left] > arr[largest]) largest = left;
        if(right <= n && arr[right] > arr[largest]) largest = right;
        if(largest != i) {
            swap(arr[i], arr[largest]);
            heapify(arr, n, largest);
        }
    }
    for(int i = n/2; i >= 1; i--) heapify(arr, n, i);
    */

    Dry Run:
    --------
    Initial heap: -1 100 50 60 40 45
    Insert 110:
        - Insert at end: -1 100 50 60 40 45 110
        - 110 > 60 (parent), swap: -1 100 50 110 40 45 60
        - 110 > 50 (parent), swap: -1 100 110 50 40 45 60
        - 110 > 100 (parent), swap: -1 110 100 50 40 45 60
    After insert: -1 110 100 50 40 45 60
    Delete root (110):
        - Replace root with last: -1 60 100 50 40 45
        - 60 < 100 (left child), swap: -1 100 60 50 40 45
        - 60 < 45 (right child of 60), no swap needed
    After delete: -1 100 60 50 40 45

*/

#include <iostream>
using namespace std;

// Max-Heap implementation using array
class Heap
{
public:
    int arr[101]; // Array to store heap elements (1-indexed)
    int size;     // Current size of heap

    // Constructor: Initialize heap size to 0
    Heap()
    {
        size = 0;
        arr[0] = -1; // arr[0] is unused, set to -1 for clarity
    }

    // Insert a value into the heap
    void insert(int value)
    {
        // Step 1: Place value at the end of the heap
        size = size + 1;
        int index = size;
        arr[index] = value;

        // Step 2: Bubble up to maintain heap property
        while (index > 1)
        {
            int parentIndex = index / 2; // Find parent index
            if (arr[parentIndex] < arr[index])
            {
                // If parent is less than child, swap them
                swap(arr[parentIndex], arr[index]);
                index = parentIndex; // Move up to parent
            }
            else
            {
                // Heap property satisfied
                break;
            }
        }
    }

    // Delete and return the root (maximum element) from the heap
    int deleteValue()
    {
        if (size == 0)
        {
            cout << "Heap is empty!" << endl;
            return -1; // Error value
        }

        int ans = arr[1]; // Store root value to return

        // Step 1: Replace root with last element
        arr[1] = arr[size];
        size--; // Remove last element

        // Step 2: Bubble down to maintain heap property
        int index = 1;
        while (index <= size)
        {
            int left = 2 * index;     // Left child index
            int right = 2 * index + 1;// Right child index
            int largest = index;      // Assume current index is largest

            // Check if left child exists and is greater than current
            if (left <= size && arr[largest] < arr[left])
            {
                largest = left;
            }
            // Check if right child exists and is greater than current largest
            if (right <= size && arr[largest] < arr[right])
            {
                largest = right;
            }

            if (largest == index)
            {
                // Current node is larger than both children, heap property satisfied
                break;
            }
            else
            {
                // Swap with the larger child and continue
                swap(arr[index], arr[largest]);
                index = largest;
            }
        }
        return ans; // Return deleted root value
    }

    // Utility function to print the heap
    void printHeap()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Heap h;

    // Manually building a heap for demonstration
    h.arr[1] = 100;
    h.arr[2] = 50;
    h.arr[3] = 60;
    h.arr[4] = 40;
    h.arr[5] = 45;
    h.size = 5;

    cout << "Printing the heap" << endl;
    h.printHeap();

    // Insert a new value
    h.insert(110);
    cout << "After inserting 110:" << endl;
    h.printHeap();

    // Delete the root value
    int deleted = h.deleteValue();
    cout << "After deleting root (" << deleted << "):" << endl;
    h.printHeap();

    return 0;
}

/*
Dry Run:
--------
Initial heap: 100 50 60 40 45
Insert 110:
    - Insert at end: 100 50 60 40 45 110
    - 110 > 60 (parent), swap: 100 50 110 40 45 60
    - 110 > 50 (parent), swap: 100 110 50 40 45 60
    - 110 > 100 (parent), swap: 110 100 50 40 45 60
After insert: 110 100 50 40 45 60
Delete root (110):
    - Replace root with last: 60 100 50 40 45
    - 60 < 100 (left child), swap: 100 60 50 40 45
    - 60 < 45 (right child of 60), no swap needed
After delete: 100 60 50 40 45

Better Alternative (STL):
-------------------------
#include <queue>
priority_queue<int> pq;
pq.push(100); pq.push(50); pq.push(60); pq.push(40); pq.push(45);
pq.push(110);
cout << pq.top(); // 110
pq.pop();
cout << pq.top(); // 100

*/