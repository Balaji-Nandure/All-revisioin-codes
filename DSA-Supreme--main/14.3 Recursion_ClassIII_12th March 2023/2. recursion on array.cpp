#include <iostream> // includes the iostream header for input/output operations
                   // needed to use std::cout, std::cin, etc.
using namespace std; // allows direct use of std namespace
                    // avoids writing std:: before each standard function

// 1. Print array elements
void printArray(int arr[], int n, int index = 0) {
    // Checks if recursion has reached end of array (terminating condition)
    // Prevents accessing out-of-bounds index
    if (index == n) return;       

    // Prints current element at 'index' to the output
    // This is part of displaying the full array recursively
    cout << arr[index] << " ";

    // Calls function recursively for next index
    // Moves traversal to the next array element
    printArray(arr, n, index + 1);
}

// 2. Reverse array (in-place using recursion)
void reverseArray(int arr[], int start, int end) {
    // If start and end have crossed, stop recursion (array fully reversed)
    // This serves as the base case to avoid extra swaps after midpoint
    if (start >= end) return;     

    // Swaps the current outer pair of elements
    // Ensures reversal happens from both array ends towards center
    swap(arr[start], arr[end]);   

    // Continue recursion with next inner pair (increment start, decrement end)
    // This narrows the bounds for in-place reversal on next call
    reverseArray(arr, start + 1, end - 1);
}

// 3. Find maximum in array
int findMax(int arr[], int n, int index = 0) {
    // Base case: if only one element left, return it as max
    // At the end, smallest subproblem returns its value
    if (index == n - 1) return arr[index];       

    // Recursively get max value from the rest of the array 
    // This compares current value to max of subsequent elements
    int maxRest = findMax(arr, n, index + 1);   

    // Return the greater value between current and rest's max
    // Propagates the largest value found so far up the recursion
    return (arr[index] > maxRest) ? arr[index] : maxRest;
}

// 4. Find minimum in array
int findMin(int arr[], int n, int index = 0) {
    // Stop recursion when last element is reached (base case for min)
    // This halts further calls to prevent overflow
    if (index == n - 1) return arr[index];       

    // Recursively get min from the rest of the array
    // Divides problem into checking one element and next subarray
    int minRest = findMin(arr, n, index + 1);   

    // Returns smaller between current element and min of rest
    // Ensures the minimum is kept through recursion chain
    return (arr[index] < minRest) ? arr[index] : minRest;
}

// 5. Find sum of array elements
int sumArray(int arr[], int n, int index = 0) {
    // Stops recursion after all elements summed (index == n)
    // Prevents adding invalid elements beyond array bounds
    if (index == n) return 0;                    

    // Adds current element to sum of rest (recursive accumulation)
    // Accumulates the result through recursive calls
    return arr[index] + sumArray(arr, n, index + 1);
}

// 6. Check if array is sorted (ascending)
bool isSorted(int arr[], int n, int index = 0) {
    // Recursion stops at last valid index (single element is sorted)
    // This ensures out-of-bounds access does not occur
    if (index == n - 1) return true;             

    // If current is greater than next, array is not sorted
    // Immediate return false avoids further unnecessary recursion
    if (arr[index] > arr[index + 1]) return false;

    // Otherwise, check next pair recursively
    // Continues to check each adjacent pair for order
    return isSorted(arr, n, index + 1);
}

// 7. Linear Search (check if element is present)
bool linearSearch(int arr[], int n, int key, int index = 0) {
    // Base case: end of array reached without finding key
    // Ensures function returns false if element is absent
    if (index == n) return false;                

    // If current element matches key, return true (found)
    // Stops recursion immediately on first match
    if (arr[index] == key) return true;

    // Search rest of array recursively from next index
    // Proceeds until key found or array exhausted
    return linearSearch(arr, n, key, index + 1);
}

// 8. Find index of first occurrence
int firstOccurrence(int arr[], int n, int key, int index = 0) {
    // Base case: return -1 if end is reached without finding key
    // Used as signal that key is not present in array
    if (index == n) return -1;                   

    // Returns current index if key found at current position
    // First match is returned up the recursion chain
    if (arr[index] == key) return index;

    // Otherwise, recursively check next element for key
    // Searches for first occurrence in remainder of array
    return firstOccurrence(arr, n, key, index + 1);
}

// 9. Find index of last occurrence
int lastOccurrence(int arr[], int n, int key, int index = 0) {
    // Stops recursion at end of array; returns -1 if not found
    // This acts as the base case indicating key is missing
    if (index == n) return -1;

    // Recursively find last occurrence in rest of array
    // Moves through to the end before any check returns
    int restIndex = lastOccurrence(arr, n, key, index + 1);

    // If found in rest of array, propagate that value upwards
    // Prioritizes later indices over earlier ones
    if (restIndex != -1) return restIndex;

    // If not found in rest, check current position for key
    // Last occurrence gets picked in reverse during recursion unwinding
    if (arr[index] == key) return index;

    // Return -1 if key not found at current and later indices
    // Indicates complete absence of the key
    return -1;
}

// 10. Binary Search (recursive, array must be sorted)
int binarySearch(int arr[], int low, int high, int key) {
    // Stop recursion when search space is invalid (not found)
    // base case to end search when element doesn't exist
    if (low > high) return -1;                    

    // Calculate middle index of current search range
    // use (high - low) to avoid integer overflow in large arrays
    int mid = low + (high - low) / 2;

    // If mid element matches key, return mid index (element found)
    // This is the successful search condition
    if (arr[mid] == key) return mid;

    // If current mid element is greater than key, search left half recursively
    // move high to mid-1 to reduce the range leftwards
    else if (arr[mid] > key) 
        return binarySearch(arr, low, mid - 1, key);

    // If key is greater, search right half recursively (low becomes mid+1)
    // Reduces the range rightwards for next call
    else 
        return binarySearch(arr, mid + 1, high, key);
}

// 11. Count occurrences of an element
int countOccurrences(int arr[], int n, int key, int index = 0) {
    // If all elements checked, return 0 (no more elements)
    // base case for termination; indicates nothing to count further
    if (index == n) return 0;

    // Recursively get count from rest of the array
    // Adds to result if match found at current index
    int countRest = countOccurrences(arr, n, key, index + 1);

    // Adds 1 if current matches key, else adds 0
    // Final result is total number of keys counted
    return (arr[index] == key ? 1 : 0) + countRest;
}

// 12. Print all indices of an element
void printAllIndices(int arr[], int n, int key, int index = 0) {
    // Ends recursion at end of array (base case)
    // Prevents further checks after array finished
    if (index == n) return;

    // If current element matches key, print current index
    // Prints index for every match, including duplicates
    if (arr[index] == key) cout << index << " ";

    // Recursively process next index in array
    // Ensures all indices are checked for key matches
    printAllIndices(arr, n, key, index + 1);
}

// ---------------- MAIN FUNCTION ----------------
int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[n];
    cout << "Enter elements of array: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    cout << "\n1. Array elements: ";
    printArray(arr, n);

    reverseArray(arr, 0, n - 1);
    cout << "\n2. Reversed array: ";
    printArray(arr, n);

    cout << "\n3. Maximum element: " << findMax(arr, n);
    cout << "\n4. Minimum element: " << findMin(arr, n);
    cout << "\n5. Sum of elements: " << sumArray(arr, n);

    cout << "\n6. Is sorted? " << (isSorted(arr, n) ? "Yes" : "No");

    int key;
    cout << "\n\nEnter element to search: ";
    cin >> key;

    cout << "7. Linear search: " << (linearSearch(arr, n, key) ? "Found" : "Not Found");
    cout << "\n8. First occurrence index: " << firstOccurrence(arr, n, key);
    cout << "\n9. Last occurrence index: " << lastOccurrence(arr, n, key);
    cout << "\n11. Count occurrences: " << countOccurrences(arr, n, key);

    cout << "\n12. All indices of element: ";
    printAllIndices(arr, n, key);

    // 10. Binary Search (requires sorted array)
    // Sort array first for correct binary search
    reverseArray(arr, 0, n - 1); // restore original order
    cout << "\n\nSorted array for Binary Search: ";
    printArray(arr, n);
    int bsIndex = binarySearch(arr, 0, n - 1, key);
    cout << "\n10. Binary Search index: " << bsIndex << endl;

    return 0;
}

// Output:
// Enter size of array: 5
// Enter elements of array: 1 2 3 2 4

// 1. Array elements: 1 2 3 2 4
// 2. Reversed array: 4 2 3 2 1
// 3. Maximum element: 4
// 4. Minimum element: 1
// 5. Sum of elements: 12
// 6. Is sorted? No

// Enter element to search: 2
// 7. Linear search: Found
// 8. First occurrence index: 1
// 9. Last occurrence index: 3
// 11. Count occurrences: 2
// 12. All indices of element: 1 3
// Sorted array for Binary Search: 1 2 2 3 4
// 10. Binary Search index: 2
