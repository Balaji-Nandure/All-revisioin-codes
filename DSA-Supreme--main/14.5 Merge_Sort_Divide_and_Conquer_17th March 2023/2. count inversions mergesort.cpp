#include <iostream>
#include <vector>
using namespace std;

// Merge function that also counts and returns number of inversions found
long long mergeAndCount(vector<int>& arr, int l, int mid, int r) {
    int n1 = mid - l + 1;              // Size of left half
    int n2 = r - mid;                  // Size of right half
    vector<int> left(n1), right(n2);   // Temporary arrays

    // Copy values from arr into left[] and right[]
    for(int i = 0; i < n1; ++i)
        left[i] = arr[l + i];
    for(int j = 0; j < n2; ++j)
        right[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = l;           // i for left[], j for right[], k for arr[]
    long long invCount = 0;            // Inversion counter

    // Merge back while counting inversions
    while(i < n1 && j < n2) {
        if(left[i] <= right[j]) {
            arr[k++] = left[i++];
        } else {
            // All remaining elements in left[i..n1-1] are greater than right[j]
            arr[k++] = right[j++];
            invCount += (n1 - i);      // Count inversions
        }
    }
    // Copy remaining left[]
    while(i < n1) arr[k++] = left[i++];
    // Copy remaining right[]
    while(j < n2) arr[k++] = right[j++];
    return invCount;
}

// Recursive merge sort that also returns number of inversions in arr[l..r]
long long mergeSortAndCount(vector<int>& arr, int l, int r) {
    long long invCount = 0;
    if(l < r) {
        int mid = l + (r - l) / 2;
        // Count inversions in left part
        invCount += mergeSortAndCount(arr, l, mid);
        // Count inversions in right part
        invCount += mergeSortAndCount(arr, mid + 1, r);
        // Count inversions during merging
        invCount += mergeAndCount(arr, l, mid, r);
    }
    return invCount;
}

int main() {
    // Input array for which inversion count is to be found
    vector<int> arr = {5, 2, 9, 1, 5, 6};

    // Calculate inversion count
    long long invCount = mergeSortAndCount(arr, 0, arr.size() - 1);

    // Print the sorted array and number of inversions
    cout << "Sorted array: ";
    for(int n : arr)
        cout << n << " ";
    cout << endl;
    
    cout << "Number of inversions: " << invCount << endl;

    return 0;
}
