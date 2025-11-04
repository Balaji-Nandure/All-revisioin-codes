/*
Approach Used:
---------------
- We are using C++ STL's inbuilt sort function to sort a vector of integers in ascending order.
- The sort function uses IntroSort (a hybrid sorting algorithm: QuickSort + HeapSort + InsertionSort) for best performance.
- The sorted array is then printed.

Better Alternatives / Detailed Approaches:
------------------------------------------
1. For small arrays, algorithms like Insertion Sort or Bubble Sort can be used, but they are less efficient (O(n^2)).
2. For large datasets, Merge Sort or QuickSort can be implemented manually for educational purposes.
3. For custom sorting (descending or by custom criteria), a comparator can be passed to std::sort.
4. For stable sorting (preserving order of equal elements), use std::stable_sort.
5. For partial sorting (e.g., only k smallest elements), use std::partial_sort or std::nth_element.

Code with detailed comments:
---------------------------
*/

#include<iostream>      // For input/output stream
#include<vector>        // For using vector container
#include<algorithm>     // For using sort function
using namespace std;

int main(){
    // Initialize a vector with unsorted elements
    vector<int> arr{5, 4, 3, 2, 1}; // arr = [5, 4, 3, 2, 1]

    // Sort the vector in ascending order using STL sort
    // sort() sorts elements in the range [arr.begin(), arr.end())
    // Time Complexity: O(n log n)
    sort(arr.begin(), arr.end());

    // Print the sorted array
    // Loop through each element and print
    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl; // For better output formatting

    return 0; // Indicate successful program termination
}

/*
Dry Run:
--------
Initial arr: [5, 4, 3, 2, 1]
After sort:  [1, 2, 3, 4, 5]
Output:      1 2 3 4 5

Step-by-step:
1. arr = [5, 4, 3, 2, 1]
2. sort(arr.begin(), arr.end()) sorts arr to [1, 2, 3, 4, 5]
3. for loop prints each element: 1 2 3 4 5
*/