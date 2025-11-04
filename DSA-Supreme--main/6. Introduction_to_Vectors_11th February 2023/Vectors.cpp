/*
Approach Used:
--------------
- This code demonstrates the basic usage of the C++ STL vector, including:
    - Declaration and initialization of vectors.
    - Checking the size and capacity of a vector.
    - Inserting and removing elements.
    - Printing vector elements.
    - Using the empty() function to check if a vector is empty.

Logic/Comments for Important Lines:
-----------------------------------
- vector<int> arr;                // Declare an empty vector of integers.
- int ans = (sizeof(arr)/sizeof(int)); // Attempts to get size in terms of int, but this is not meaningful for vectors (compiler dependent).
- cout << arr.size();             // Prints the number of elements currently stored in the vector (should be 0 initially).
- cout << arr.capacity();         // Prints the current capacity (how many elements can be stored before reallocation).
- arr.push_back(5);               // Inserts 5 at the end of the vector.
- arr.push_back(6);               // Inserts 6 at the end of the vector.
- for(...) cout << arr[i];        // Prints all elements of the vector.
- arr.pop_back();                 // Removes the last element (6) from the vector.
- vector<int> crr(10, 1);         // Initializes a vector of size 10, all elements set to 1.
- for(...) cout << crr[i];        // Prints all elements of crr.
- crr.empty();                    // Returns false (0) if crr is not empty, true (1) if it is.
- vector<int> drr;                // Declares an empty vector.
- drr.empty();                    // Returns true (1) since drr is empty.

Alternative Detailed Approach:
-----------------------------
- Instead of using push_back for each element, you can initialize a vector with a list of values:
    vector<int> arr = {5, 6};
- To print all elements, you can use a range-based for loop:
    for(int val : arr) cout << val << " ";
- To clear a vector (remove all elements):
    arr.clear();
- To check if a vector is empty after clearing:
    cout << arr.empty() << endl;
- To get the maximum possible size of a vector:
    cout << arr.max_size() << endl;

Dry Run:
--------
Step 1: vector<int> arr; // arr is empty
Step 2: int ans = (sizeof(arr)/sizeof(int)); // Not meaningful, prints 1 (size of vector object / size of int)
Step 3: cout << arr.size(); // 0 (no elements)
Step 4: cout << arr.capacity(); // 0 (no allocated storage yet)
Step 5: arr.push_back(5); // arr = [5]
Step 6: arr.push_back(6); // arr = [5, 6]
Step 7: print arr: 5 6
Step 8: arr.pop_back(); // arr = [5]
Step 9: vector<int> crr(10, 1); // crr = [1,1,1,1,1,1,1,1,1,1]
Step 10: print crr: 1 1 1 1 1 1 1 1 1 1
Step 11: cout << crr.empty(); // 0 (not empty)
Step 12: vector<int> drr; // drr is empty
Step 13: cout << drr.empty(); // 1 (empty)

*/

#include<iostream>
#include<vector> // vector header file to use vector in our program
using namespace std;

int main(){
    vector<int> arr; // Declare an empty vector of integers

    int ans = (sizeof(arr)/sizeof(int)); // Not meaningful for vectors, just for demonstration
    cout << ans << endl; // Prints 1 (size of vector object / size of int), not the number of elements

    // Checking default array size and capacity
    cout << arr.size() << endl;     // Prints 0, as no elements are stored yet
    cout << arr.capacity() << endl; // Prints 0, as no memory is allocated yet

    // Insertion of elements
    arr.push_back(5); // Insert 5 at the end of the vector
    arr.push_back(6); // Insert 6 at the end of the vector

    // Printing vector elements
    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] << " "; // Print each element
    }
    cout << endl;

    // Removes last element inserted
    arr.pop_back(); // Removes 6 from the vector

    // Initialization of vector with fixed size and value
    vector<int> crr(10, 1); // Create vector of size 10, all elements initialized to 1

    // Printing crr vector elements
    for(int i = 0; i < crr.size(); i++){
        cout << crr[i] << " "; // Print each element of crr
    }
    cout << endl;

    // empty() function usage
    cout << crr.empty() << endl; // Prints 0 (false), as crr is not empty

    vector<int> drr; // Declare an empty vector
    cout << drr.empty() << endl; // Prints 1 (true), as drr is empty

    return 0;
}