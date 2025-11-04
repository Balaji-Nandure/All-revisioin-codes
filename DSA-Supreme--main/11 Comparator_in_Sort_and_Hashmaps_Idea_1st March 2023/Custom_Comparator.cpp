/*
Approach:
-----------
- This code demonstrates how to use custom comparators with the STL sort function to sort strings and vectors in descending order.
- Custom comparator functions are passed as the third argument to std::sort to define the sorting logic.
- The code sorts a string in reverse lexicographical order and a vector of integers in decreasing order.

Alternative Approaches (without code):
--------------------------------------
1. Instead of custom comparators, you can use std::greater<>() for built-in types to sort in descending order.
2. For strings, you can use std::reverse after default sort to reverse the order.
3. Lambda functions can be used for inline comparators, making code more concise.
4. For more complex data types (like pairs or structs), custom comparators can be extended to sort based on multiple fields.
5. For stable sorting, use std::stable_sort instead of std::sort if order preservation is needed for equal elements.

Code with detailed comments and improvements:
---------------------------------------------
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <functional> // For std::greater
using namespace std;

// Custom comparator for sorting characters in descending order
bool cmp(char first, char second) {
    // If first character is greater than second, return true to place first before second
    return first > second;
}

// Custom comparator for sorting integers in descending order
bool cmp1(int a, int b) {
    // If a is greater than b, return true to place a before b
    return a > b;
}

int main() {
    // Input string to be sorted
    string s = "bhavya"; 

    // Sort the string in descending (reverse lexicographical) order using custom comparator
    sort(s.begin(), s.end(), cmp); // cmp defines the sorting logic

    // Output the sorted string
    cout << s << endl; // Expected output: 'yvhbba'

    // Create a vector of integers
    vector<int> v{3, 1, 4, 5, 2}; 

    // Sort the vector in decreasing order using custom comparator
    sort(v.begin(), v.end(), cmp1); // cmp1 defines the sorting logic

    // Output the sorted vector
    for (auto i : v) {
        cout << i << " "; // Expected output: 5 4 3 2 1
    }
    cout << endl;

    /*
    // Alternative: Using std::greater for built-in types (no need for custom comparator)
    sort(v.begin(), v.end(), greater<int>());

    // Alternative: Using lambda function for inline comparator
    sort(v.begin(), v.end(), [](int a, int b) { return a > b; });

    // For stable sorting (preserving order of equal elements)
    stable_sort(v.begin(), v.end(), cmp1);
    */

    return 0;
}

/*
Dry Run:
--------
1. String s = "bhavya"
   - After sort with cmp: 'yvhbba'
   - Output: yvhbba

2. Vector v = {3, 1, 4, 5, 2}
   - After sort with cmp1: {5, 4, 3, 2, 1}
   - Output: 5 4 3 2 1

Key Points:
-----------
- Custom comparators allow flexible sorting logic.
- For simple types, STL provides ready-made comparators like std::greater.
- Lambda functions can make code concise.
- Use stable_sort if order of equal elements matters.
*/