/*
    Approach Used: Insertion Sort

    - Insertion Sort is a simple sorting algorithm that builds the final sorted array one item at a time.
    - It is much less efficient on large lists than more advanced algorithms such as quicksort, heapsort, or merge sort.
    - The algorithm iterates through the array and at each iteration, it removes one element from the input data, finds the location it belongs within the sorted list, and inserts it there.
    - It repeats until no input elements remain.

    Time Complexity:
        - Best Case: O(n) [when array is already sorted]
        - Average and Worst Case: O(n^2)
    Space Complexity: O(1) [in-place]

    Better Alternatives (for large datasets):
        - Merge Sort: O(n log n), stable, not in-place (uses extra space)
        - Quick Sort: O(n log n) average, O(n^2) worst, in-place, not stable
        - Heap Sort: O(n log n), in-place, not stable
        - TimSort (used in Python): Hybrid of merge and insertion sort, O(n log n)
        - For nearly sorted arrays, Insertion Sort is very efficient.

    Dry Run Example at the end of code.
*/

#include<iostream>
#include<vector>
using namespace std;

// Function to print the elements of the array
void printArr(const vector<int>& arr){
    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] << " "; // Print each element followed by a space
    }
    cout << endl; // Print newline for better formatting
}

// Function to perform insertion sort on the array
void insertionSort(vector<int>& arr){
    int n = arr.size(); // Get the size of the array

    // Traverse from the second element to the last element
    for(int i = 1; i < n; i++){
        int val = arr[i]; // Store the current element to be positioned
        int j = i - 1;    // Start comparing with the previous elements

        // Shift elements of arr[0..i-1], that are greater than val, to one position ahead
        while(j >= 0 && arr[j] > val){
            arr[j + 1] = arr[j]; // Shift element to the right
            j--;                 // Move to the previous element
        }

        // Place the stored value at its correct position in the sorted part
        arr[j + 1] = val;
    }
}

int main(){
    // Initialize the array with unsorted values
    vector<int> arr{10, 1, 4, 8, 5, 7};

    cout << "Printing array before sorting:" << endl;
    printArr(arr); // Print the unsorted array

    cout << "Printing array after sorting:" << endl;
    insertionSort(arr); // Sort the array using insertion sort
    printArr(arr);      // Print the sorted array

    return 0;
}

/*
    Dry Run Example:
    Input: [10, 1, 4, 8, 5, 7]

    i=1, val=1
        Compare 10 > 1, shift 10 to right
        Insert 1 at position 0
        [1, 10, 4, 8, 5, 7]

    i=2, val=4
        Compare 10 > 4, shift 10 to right
        Compare 1 < 4, stop
        Insert 4 at position 1
        [1, 4, 10, 8, 5, 7]

    i=3, val=8
        Compare 10 > 8, shift 10 to right
        Compare 4 < 8, stop
        Insert 8 at position 2
        [1, 4, 8, 10, 5, 7]

    i=4, val=5
        Compare 10 > 5, shift 10 to right
        Compare 8 > 5, shift 8 to right
        Compare 4 < 5, stop
        Insert 5 at position 2
        [1, 4, 5, 8, 10, 7]

    i=5, val=7
        Compare 10 > 7, shift 10 to right
        Compare 8 > 7, shift 8 to right
        Compare 5 < 7, stop
        Insert 7 at position 3
        [1, 4, 5, 7, 8, 10]

    Output: [1, 4, 5, 7, 8, 10]
*/