/*
Approach Used:
---------------
Selection Sort is an in-place, comparison-based sorting algorithm. The main idea is to divide the array into two parts: the sorted part at the left end and the unsorted part at the right end. In every iteration, the minimum element from the unsorted part is picked and swapped with the leftmost unsorted element, moving the boundary of the sorted part one step to the right.

Time Complexity: O(n^2) in all cases (best, average, worst)
Space Complexity: O(1) (in-place)
Stable: No (can be made stable with extra effort)
Use-case: Good for small arrays or when memory write is costly (as it does minimum number of swaps)

Better Alternatives (without code):
-----------------------------------
1. **Bubble Sort**: Also O(n^2), but generally slower than selection sort due to more swaps.
2. **Insertion Sort**: O(n^2) but faster than selection sort for nearly sorted or small arrays. It is stable and adaptive.
3. **Merge Sort**: O(n log n), stable, but requires O(n) extra space.
4. **Quick Sort**: O(n log n) average, O(n^2) worst, in-place, not stable, but very fast in practice.
5. **Heap Sort**: O(n log n), in-place, not stable.

Improvements Made:
------------------
- Added detailed comments for logic and reasoning.
- Used range-based for loop in printArr for better readability.
- Added input prompt and output formatting for clarity.
- Added a dry run at the end as a comment.

*/

#include<iostream>
#include<vector>
using namespace std;

// Function to print the elements of the array
void printArr(const vector<int>& arr) {
    for (const int& num : arr) { // Range-based loop for better readability
        cout << num << " ";
    }
    cout << endl;
}

// Function to perform Selection Sort on the array
void selectionSort(vector<int>& arr) {
    int n = arr.size();
    // Traverse through all array elements except the last one
    for (int i = 0; i < n - 1; i++) { // n-1 passes required
        int minIndex = i; // Assume the current position holds the minimum
        // Find the minimum element in the unsorted part
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) { // If a smaller element is found
                minIndex = j; // Update minIndex
            }
        }
        // Swap the found minimum element with the first element of the unsorted part
        if (minIndex != i) { // Only swap if needed to reduce unnecessary swaps
            swap(arr[i], arr[minIndex]);
        }
        // Uncomment below to see the array after each pass
        // printArr(arr);
    }
}

int main() {
    // Initialize the array to be sorted
    vector<int> arr{10, 1, 4, 8, 5, 7};

    cout << "Array before sorting: " << endl;
    printArr(arr);

    // Sort the array using Selection Sort
    selectionSort(arr);

    cout << "Array after Selection Sort: " << endl;
    printArr(arr);

    return 0;
}

/*
Dry Run:
--------
Initial array: [10, 1, 4, 8, 5, 7]

Pass 1 (i=0): Find min from index 0 to 5
    minIndex = 1 (value 1)
    Swap arr[0] and arr[1] => [1, 10, 4, 8, 5, 7]

Pass 2 (i=1): Find min from index 1 to 5
    minIndex = 2 (value 4)
    Swap arr[1] and arr[2] => [1, 4, 10, 8, 5, 7]

Pass 3 (i=2): Find min from index 2 to 5
    minIndex = 4 (value 5)
    Swap arr[2] and arr[4] => [1, 4, 5, 8, 10, 7]

Pass 4 (i=3): Find min from index 3 to 5
    minIndex = 5 (value 7)
    Swap arr[3] and arr[5] => [1, 4, 5, 7, 10, 8]

Pass 5 (i=4): Find min from index 4 to 5
    minIndex = 5 (value 8)
    Swap arr[4] and arr[5] => [1, 4, 5, 7, 8, 10]

Sorted array: [1, 4, 5, 7, 8, 10]
*/