/*
Approach:
- This code demonstrates the usage of the STL deque (double-ended queue) in C++.
- It shows how to create a deque, insert elements at both ends, remove elements, check size, access front and rear, and check if the deque is empty.
- Deque allows fast insertion and deletion at both front and back (O(1) time).
- The code can be improved by using functions for modularity, iterating and printing the deque, and handling edge cases (like accessing front/back of empty deque).

Better Alternatives:
1. Use functions to modularize code for insertion, deletion, and display.
2. Use iterators to print the entire deque for better visualization.
3. Handle exceptions or check for empty deque before accessing front/back.
4. Use range-based for loop for printing.
5. For more complex operations, consider using std::list if only front/back operations are needed, as it may have less memory overhead.

Below is the improved code with detailed comments and a dry run at the end.
*/

#include<iostream>
#include<deque>
using namespace std;

// Function to print all elements of the deque
void printDeque(const deque<int>& d) {
    cout << "Deque: ";
    for(const int& elem : d) {
        cout << elem << " ";
    }
    cout << endl;
}

int main(){
    // Create an empty deque of integers
    deque<int> d;

    // Insert 5 at the front: d = [5]
    d.push_front(5); // push_front inserts element at the beginning

    // Insert 10 at the front: d = [10, 5]
    d.push_front(10);

    // Insert 20 at the back: d = [10, 5, 20]
    d.push_back(20); // push_back inserts element at the end

    // Insert 30 at the back: d = [10, 5, 20, 30]
    d.push_back(30);

    // Print current deque
    printDeque(d);

    // Print current size of deque
    cout << "Size = " << d.size() << endl;

    // Remove element from front: d = [5, 20, 30]
    d.pop_front(); // pop_front removes element from the beginning

    printDeque(d);
    cout << "Size = " << d.size() << endl;

    // Remove element from front: d = [20, 30]
    d.pop_front();

    printDeque(d);
    cout << "Size = " << d.size() << endl;

    // Check and print front and rear elements
    if(!d.empty()) { // Always check if deque is not empty before accessing front/back
        cout << "Front = " << d.front() << endl; // front() returns first element
        cout << "Rear = " << d.back() << endl;   // back() returns last element
    } else {
        cout << "Deque is empty, cannot access front/rear." << endl;
    }

    // Check if deque is empty
    if(d.empty()){
        cout << "Empty" << endl;
    }
    else{
        cout << "Not empty" << endl;
    }

    return 0;
}

/*
Alternative Approach (using std::list for only front/back operations):
#include<list>
list<int> l;
l.push_front(1);
l.push_back(2);
l.pop_front();
l.pop_back();
cout << l.front() << " " << l.back() << endl;

Dry Run:
Step 1: d = []
Step 2: d.push_front(5)   => d = [5]
Step 3: d.push_front(10)  => d = [10, 5]
Step 4: d.push_back(20)   => d = [10, 5, 20]
Step 5: d.push_back(30)   => d = [10, 5, 20, 30]
Print: Deque: 10 5 20 30
Size = 4

Step 6: d.pop_front()     => d = [5, 20, 30]
Print: Deque: 5 20 30
Size = 3

Step 7: d.pop_front()     => d = [20, 30]
Print: Deque: 20 30
Size = 2

Step 8: d.front() = 20, d.back() = 30
Print: Front = 20
Print: Rear = 30

Step 9: d.empty() = false
Print: Not empty
*/