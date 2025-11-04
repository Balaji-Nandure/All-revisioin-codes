/*
Approach:
-----------
This code demonstrates the usage of C++ STL priority_queue to implement both Max Heap and Min Heap.
- Max Heap: By default, priority_queue in C++ is a max heap (largest element at the top).
- Min Heap: By using greater<int> as the comparator, we can make a min heap (smallest element at the top).

Key Operations:
- push(): Insert an element into the heap.
- top(): Access the top (max/min) element.
- pop(): Remove the top element.
- size(): Get the number of elements.
- empty(): Check if the heap is empty.

Alternatives:
-------------
1. Custom Comparator:
   You can use a custom comparator struct/class for more complex ordering.
   Example:
   ```
   struct CustomCompare {
       bool operator()(const int& a, const int& b) {
           // Custom logic, e.g., return a > b for min heap
           return a > b;
       }
   };
   priority_queue<int, vector<int>, CustomCompare> customPQ;
   ```

2. Using make_heap, push_heap, pop_heap (for heap algorithms on vector):
   ```
   vector<int> v = {23, 12, 67, 15};
   make_heap(v.begin(), v.end()); // Max heap by default
   // For min heap: use greater<int> as comparator
   make_heap(v.begin(), v.end(), greater<int>());
   ```

3. For custom objects, define operator< or provide a comparator.

Improvements:
-------------
- Use functions to avoid code repetition.
- Print the entire heap (by popping all elements) for better visualization.
- Add more comments for clarity.

*/

#include<iostream>
#include<queue>
#include<vector>
using namespace std;

// Function to print and empty the priority queue (for demonstration)
template<typename T>
void printAndEmptyPQ(priority_queue<T> pq) {
    // Print all elements in max heap order
    cout << "Heap elements (max to min): ";
    while(!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;
}

template<typename T>
void printAndEmptyPQ(priority_queue<T, vector<T>, greater<T>> pq) {
    // Print all elements in min heap order
    cout << "Heap elements (min to max): ";
    while(!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;
}

int main(){
    // Demonstrating Max Heap
    cout << "Max Heap" << endl;
    // Create a max heap (default behavior)
    priority_queue<int> pq;

    // Insert elements into the max heap
    pq.push(23); // Insert 23
    pq.push(12); // Insert 12
    pq.push(67); // Insert 67
    pq.push(15); // Insert 15

    // Print all elements (for demonstration)
    printAndEmptyPQ(pq);

    // Re-insert elements for further operations
    pq.push(23);
    pq.push(12);
    pq.push(67);
    pq.push(15);

    // Access the top element (should be the largest)
    cout << "Top element: " << pq.top() << endl;

    // Remove the top element (largest)
    pq.pop();

    // Size after pop
    cout << "Size after pop: " << pq.size() << endl;

    // Check if the heap is empty
    if(pq.empty()){
        cout << "Heap is empty" << endl;
    }
    else{
        cout << "Heap is not empty" << endl;
    }

    cout << "------------------------" << endl;

    // Demonstrating Min Heap
    cout << "Min Heap" << endl;
    // Create a min heap using greater<int> as comparator
    priority_queue<int, vector<int>, greater<int>> p;

    // Insert elements into the min heap
    p.push(23); // Insert 23
    p.push(12); // Insert 12
    p.push(67); // Insert 67
    p.push(15); // Insert 15

    // Print all elements (for demonstration)
    printAndEmptyPQ(p);

    // Re-insert elements for further operations
    p.push(23);
    p.push(12);
    p.push(67);
    p.push(15);

    // Access the top element (should be the smallest)
    cout << "Top element: " << p.top() << endl;

    // Remove the top element (smallest)
    p.pop();

    // Size after pop
    cout << "Size after pop: " << p.size() << endl;

    // Check if the heap is empty
    if(p.empty()){
        cout << "Heap is empty" << endl;
    }
    else{
        cout << "Heap is not empty" << endl;
    }

    return 0;
}

/*
Dry Run:
--------
Max Heap:
- Inserted: 23, 12, 67, 15
- Heap (max to min): 67 23 15 12
- Top element: 67
- After pop (removes 67), size: 3
- Heap is not empty

Min Heap:
- Inserted: 23, 12, 67, 15
- Heap (min to max): 12 15 23 67
- Top element: 12
- After pop (removes 12), size: 3
- Heap is not empty

Better Alternatives:
-------------------
- Use custom comparators for complex objects or custom ordering.
- Use heap algorithms (make_heap, push_heap, pop_heap) for more control or for non-priority_queue containers.
- For printing all elements, priority_queue does not provide iterators, so you must pop elements (as shown).
- For stable ordering or to keep all elements, use a copy of the heap for printing.
*/