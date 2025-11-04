/*
    Approach:
    -----------
    - This code implements the Bubble Sort algorithm to sort an array of integers in ascending order.
    - Bubble Sort works by repeatedly swapping adjacent elements if they are in the wrong order.
    - After each pass, the largest unsorted element "bubbles up" to its correct position at the end of the array.
    - The process is repeated for n-1 passes or until no swaps are needed (array is sorted early).

    Better Alternatives (without code):
    -----------------------------------
    1. Selection Sort:
        - Finds the minimum element from the unsorted part and puts it at the beginning.
        - Fewer swaps than Bubble Sort, but still O(n^2) time complexity.
    2. Insertion Sort:
        - Builds the sorted array one element at a time by inserting elements into their correct position.
        - Efficient for small or nearly sorted arrays (O(n) best case).
    3. Merge Sort / Quick Sort / Heap Sort:
        - All have better average and worst-case time complexity (O(n log n)).
        - Merge Sort is stable and good for linked lists.
        - Quick Sort is fast in practice but not stable.
        - Heap Sort is in-place but not stable.
    4. Built-in sort (std::sort in C++):
        - Highly optimized, uses IntroSort (hybrid of Quick, Heap, and Insertion Sort).

    Improvements made:
    ------------------
    - Added comments for all important lines.
    - Improved printArr to print a newline at the end for better output formatting.
    - Used const reference in printArr to avoid unnecessary copying.
    - Added more descriptive output in main.
    - Provided a dry run at the end of the code.
*/

#include<iostream>
#include<vector>
using namespace std;

// Function to print the elements of the array
void printArr(const vector<int>& arr){
    for(int i = 0; i < arr.size(); i++){ // Loop through all elements
        cout << arr[i] << " ";           // Print each element
    }
    cout << endl;                        // Print newline for better formatting
}

// Function to perform Bubble Sort on the array
void bubbleSort(vector<int>& arr){
    int n = arr.size(); // Get the size of the array
    // Outer loop for n-1 passes
    for(int i = 0; i < n - 1; i++){
        bool swapped = false; // Track if any swap happened in this pass
        // Inner loop for comparing adjacent elements
        for(int j = 1; j < n - i; j++){ // Last i elements are already sorted
            if(arr[j - 1] > arr[j]){    // If previous element is greater than current
                swap(arr[j - 1], arr[j]); // Swap them
                swapped = true;           // Mark that a swap occurred
            }
        }
        // If no swaps occurred in this pass, array is already sorted
        if(!swapped){
            break; // Exit early for optimization
        }
    }
}

int main(){
    // Initialize the array with unsorted elements
    vector<int> arr{10, 1, 4, 8, 5, 7};

    cout << "Array before sorting: " << endl;
    printArr(arr); // Print the unsorted array

    bubbleSort(arr); // Sort the array using Bubble Sort

    cout << "Array after Bubble Sort: " << endl;
    printArr(arr); // Print the sorted array

    return 0;
}

/*
Dry Run:
--------
Initial array: [10, 1, 4, 8, 5, 7]

Pass 1:
    Compare 10 and 1 -> swap -> [1, 10, 4, 8, 5, 7]
    Compare 10 and 4 -> swap -> [1, 4, 10, 8, 5, 7]
    Compare 10 and 8 -> swap -> [1, 4, 8, 10, 5, 7]
    Compare 10 and 5 -> swap -> [1, 4, 8, 5, 10, 7]
    Compare 10 and 7 -> swap -> [1, 4, 8, 5, 7, 10]
    (10 is now at correct position)

Pass 2:
    Compare 1 and 4 -> no swap
    Compare 4 and 8 -> no swap
    Compare 8 and 5 -> swap -> [1, 4, 5, 8, 7, 10]
    Compare 8 and 7 -> swap -> [1, 4, 5, 7, 8, 10]
    (8 is now at correct position)

Pass 3:
    Compare 1 and 4 -> no swap
    Compare 4 and 5 -> no swap
    Compare 5 and 7 -> no swap
    (No swaps in this pass, so array is sorted early and loop breaks)

Final sorted array: [1, 4, 5, 7, 8, 10]
*/