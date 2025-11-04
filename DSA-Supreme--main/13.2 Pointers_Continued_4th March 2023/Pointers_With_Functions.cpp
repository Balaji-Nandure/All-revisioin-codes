/*
Approach:
-----------
- Demonstrate how arrays are passed to functions in C++ and how their size information is lost.
- Show the difference between sizeof operator on array in main (actual array) vs in function (pointer).
- Discuss better alternatives for passing arrays to functions when size information is needed.

Better Alternatives (in comments):
-----------------------------------
1. Pass the size of the array as an additional parameter to the function.
2. Use std::array (for fixed size arrays) or std::vector (for dynamic arrays) which retain size information.
3. Use templates to deduce array size at compile time.

*/

// Include input/output stream library
#include<iostream>
using namespace std;

// Function to demonstrate array decay to pointer when passed to function
void solve(int arr[]) { 
    // arr is actually a pointer here, not an array
    cout << "Size in solve function is - " << sizeof(arr) << " bytes" << endl; // Will print size of pointer (typically 8 bytes on 64-bit systems)
    // Note: Cannot determine actual array size here
}

int main() {
    // Declare and initialize an integer array of size 10, first 4 elements initialized
    int arr[10] = {1,2,3,4};
    
    // sizeof(arr) gives total size in bytes of the array (10 * 4 = 40 bytes for int[10])
    cout << "Size of array in main function is - " << sizeof(arr) << " bytes" << endl; // Will print 40 bytes
    
    // Pass array to function; decays to pointer, size information lost
    solve(arr);

    return 0;
}

/*
Better Alternatives (Detailed):
-------------------------------
1. Pass array size as an argument:
    void solve(int arr[], int n) { ... }
    // Call: solve(arr, 10);

2. Use std::array (C++11 and above):
    #include<array>
    void solve(std::array<int, 10>& arr) { ... }
    // arr.size() gives size

3. Use std::vector for dynamic arrays:
    #include<vector>
    void solve(const std::vector<int>& arr) { ... }
    // arr.size() gives size

4. Use templates to deduce size:
    template<size_t N>
    void solve(int (&arr)[N]) { cout << N; }

Dry Run:
---------
main():
    arr[10] = {1,2,3,4};
    sizeof(arr) = 40 bytes (10 ints * 4 bytes each)
    Output: "Size of array in main function is - 40 bytes"
    solve(arr):
        arr decays to int*
        sizeof(arr) = 8 bytes (size of pointer on 64-bit)
        Output: "Size in solve function is - 8 bytes"

Key Takeaway:
--------------
- When passing arrays to functions, only the pointer is passed, not the actual array, so size information is lost.
- Always pass array size or use STL containers/templates to retain size information.
*/