/*
Approach Used:
---------------
- This code uses C++ STL's inbuilt sort function (std::sort) to sort an array of integers in ascending order.
- std::sort uses IntroSort (a hybrid of QuickSort, HeapSort, and InsertionSort) for optimal performance.
- The sorted array is then printed.

Better Alternatives / Detailed Approaches (without code):
---------------------------------------------------------
1. **Bubble Sort**: Simple, but inefficient (O(n^2)). Repeatedly swaps adjacent elements if they are in the wrong order.
2. **Selection Sort**: Selects the minimum element from the unsorted part and swaps it with the first unsorted element. Also O(n^2).
3. **Insertion Sort**: Builds the sorted array one element at a time. Efficient for small or nearly sorted arrays (O(n) best case, O(n^2) worst).
4. **Merge Sort**: Divide and conquer, stable, O(n log n) time, but uses extra space.
5. **Quick Sort**: Fast in practice, O(n log n) average, O(n^2) worst, in-place, not stable.
6. **Heap Sort**: O(n log n), in-place, not stable.
7. **std::stable_sort**: Like std::sort but stable (preserves order of equal elements).
8. **Custom Comparator**: std::sort can take a comparator for custom sorting (e.g., descending order).

Improvements Made:
------------------
- Added detailed comments explaining logic behind each important line.
- Improved printArr to print a newline at the end for better formatting.
- Used const reference in printArr for better practice (if using vector).
- Added output formatting for clarity.
- Added a dry run at the end as a comment.

*/

#include<iostream>      // For input/output stream
#include<algorithm>     // For using sort function
using namespace std;

// Function to print the elements of the array
void printArr(const int arr[], int n) {
    for(int i = 0; i < n; i++) { // Loop through all elements
        cout << arr[i] << " ";   // Print each element followed by a space
    }
    cout << endl;                // Print newline for better formatting
}

int main() {
    // Initialize the array with unsorted elements
    int arr[] = {5, 4, 3, 2, 1}; // arr = [5, 4, 3, 2, 1]
    int n = sizeof(arr) / sizeof(arr[0]); // Calculate the number of elements in the array

    cout << "Array before sorting: " << endl;
    printArr(arr, n); // Print the unsorted array

    // Sort the array in ascending order using STL sort
    // sort() sorts elements in the range [arr, arr + n)
    // Time Complexity: O(n log n)
    sort(arr, arr + n);

    cout << "Array after sorting: " << endl;
    printArr(arr, n); // Print the sorted array

    return 0; // Indicate successful program termination
}

/*
Dry Run:
--------
Initial arr: [5, 4, 3, 2, 1]
After sort:  [1, 2, 3, 4, 5]
Output:
Array before sorting: 
5 4 3 2 1 
Array after sorting: 
1 2 3 4 5 
*/