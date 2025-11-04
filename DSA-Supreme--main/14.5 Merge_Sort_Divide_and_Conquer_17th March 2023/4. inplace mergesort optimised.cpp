#include <iostream> // For input and output operations
#include <vector>   // For using the vector container
#include <cmath>    // For mathematical operations, though not used here
using namespace std; // Use the standard namespace

// Function to compute the next gap value
int nextGap(int gap) {
    if (gap <= 1) // If gap is 1 or less, end the loop
        return 0; // No more passes needed when gap reaches 0
    return (gap / 2) + (gap % 2);  // Ceiling of gap/2
}

// Function to merge two sorted subarrays in place using the Gap method
void inplaceMerge(vector<int>& arr, int l, int mid, int r) {
    int total_len = r - l + 1;       // Total length of the subarray to be merged
    int gap = nextGap(total_len);    // Initial gap for the gap method

    while (gap > 0) {                // Continue until gap becomes 0
        int i = l;                   // Start pointer at the beginning of the left subarray
        int j = l + gap;             // Second pointer at 'gap' distance from i

        while (j <= r) {             // Traverse until j reaches end of subarray
            if (arr[i] > arr[j])     // If element at i is greater than element at j
                swap(arr[i], arr[j]); // Swap them to correct order
            i++;                     // Move the first pointer forward
            j++;                     // Move the second pointer forward to maintain the gap
        }

        gap = nextGap(gap);          // Reduce the gap for the next pass
    }
}

// Recursive merge sort that sorts input array in-place using the gap method
void inplaceMergeSort(vector<int>& arr, int l, int r) {
    if (l >= r) return;                        // Base case: single element or invalid

    int mid = l + (r - l) / 2;                 // Find the mid-point

    inplaceMergeSort(arr, l, mid);             // Recursively sort left half
    inplaceMergeSort(arr, mid + 1, r);         // Recursively sort right half
    inplaceMerge(arr, l, mid, r);              // In-place merge the sorted halves
}

int main() {
    vector<int> arr = {5, 2, 9, 1, 5, 6};      // Declare and initialize sample array

    inplaceMergeSort(arr, 0, arr.size() - 1);  // Call in-place merge sort on the array

    cout << "Sorted array: ";                  // Output sorted array label
    for (int n : arr)                          // Iterate through sorted array
        cout << n << " ";                      // Print each element followed by space
    cout << endl;                              // New line after printing the array

    return 0;                                  // Indicate successful execution
}
