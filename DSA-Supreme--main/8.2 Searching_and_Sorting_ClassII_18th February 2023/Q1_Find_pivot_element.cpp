/*
    Approach Used:
    ----------------
    - The array is a rotated sorted array (increasing order, rotated at some pivot).
    - The pivot element is the largest element, i.e., the point where the order breaks.
    - We use a modified binary search to find the pivot efficiently in O(log n) time.

    Better Alternatives (in comments):
    -----------------------------------
    1. Linear Search: Traverse the array and find the point where arr[i] > arr[i+1]. Time: O(n). Not efficient.
    2. Use built-in functions (like std::max_element) but that is O(n).
    3. If duplicates are present, binary search needs extra handling.
    4. If you want the index of the minimum (smallest) element (rotation count), you can adapt the binary search accordingly.

    This code finds the index of the largest element (pivot) in a rotated sorted array with unique elements.
*/

#include<iostream>
#include<vector>
using namespace std;

// Function to find the index of the pivot (largest) element in a rotated sorted array
int pivotElement(const vector<int>& arr) {
    int n = arr.size();
    int left = 0, right = n - 1;

    // Edge case: If array is not rotated at all
    // This edge case is not strictly required for correctness.
    // The main binary search loop will also handle the non-rotated case correctly,
    // returning n-1 as the pivot (largest element) when the array is fully sorted.
    // You can safely remove this block for unique elements.
    // if (arr[left] < arr[right]) {
    //     // The last element is the largest (pivot)
    //     return right;
    // }

    // Simple binary search for pivot
    while (left < right) {
        int mid = left + (right - left) / 2;

        // If mid element is greater than right, pivot is in right half
        if (arr[mid] > arr[right]) {
            left = mid + 1;
        } else {
            // Pivot is in left half (including mid)
            right = mid;
        }
    }
    // After loop, left points to the smallest element (rotation point)
    // Pivot (largest) is just before it, handle wrap-around
    return (left - 1 + n) % n;
}

int main() {
    // Example rotated sorted array
    vector<int> arr{3, 4, 5, 6, 7, 1, 2};

    int pivot = pivotElement(arr); // Find pivot index

    cout << "Pivot = " << arr[pivot] << endl; // Output the pivot element

    return 0;
}

/*
    Dry Run:
    ---------
    Input: arr = {3,4,5,6,7,1,2}
    Indices:   0 1 2 3 4 5 6

    1st Iteration:
        s = 0, e = 6
        mid = 3
        arr[mid]=6, arr[mid+1]=7 -> 6 < 7, not pivot
        arr[mid-1]=5 < 6, not pivot
        arr[s]=3 < arr[mid]=6, so move s = mid+1 = 4

    2nd Iteration:
        s = 4, e = 6
        mid = 5
        arr[mid]=1, arr[mid+1]=2 -> 1 < 2, not pivot
        arr[mid-1]=7 > 1, so arr[mid-1]=7 is pivot, return 4

    Output: Pivot = 7

    (If array is not rotated, e.g. {1,2,3,4,5}, pivot is last element.)
*/