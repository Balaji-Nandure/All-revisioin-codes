#include <iostream>
#include <vector>
using namespace std;

// Function to merge two sorted parts of the array: arr[l..mid] and arr[mid+1..r]
void merge(vector<int>& arr, int l, int mid, int r) {
    // Sizes of the two subarrays
    int n1 = mid - l + 1;
    int n2 = r - mid;

    // Create temporary arrays to hold the values
    vector<int> left(n1), right(n2);

    // Copy values from arr to left[] and right[]
    for(int i = 0; i < n1; ++i)
        left[i] = arr[l + i];
    for(int j = 0; j < n2; ++j)
        right[j] = arr[mid + 1 + j];

    // Merge the temporary arrays back into arr[l..r]
    int i = 0;     // Initial index for left[]
    int j = 0;     // Initial index for right[]
    int k = l;     // Initial index for merged array

    // Compare elements from left[] and right[] and place the smaller in arr
    while(i < n1 && j < n2) {
        if(left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    // Copy any remaining elements of left[] (if any)
    while(i < n1) {
        arr[k] = left[i];
        i++;
        k++;
    }
    // Copy any remaining elements of right[] (if any)
    while(j < n2) {
        arr[k] = right[j];
        j++;
        k++;
    }
}

// Recursive function to perform merge sort on arr[l..r]
void mergeSort(vector<int>& arr, int l, int r) {
    // Base case: if the array has one or zero elements, it's already sorted
    if(l >= r)
        return;

    int mid = l + (r - l) / 2; // Find the middle point

    // Recursively sort the first and second halves
    mergeSort(arr, l, mid);
    mergeSort(arr, mid + 1, r);

    // Merge the sorted halves
    merge(arr, l, mid, r);
}

int main() {
    // Sample array to be sorted
    vector<int> arr = {5, 2, 9, 1, 5, 6};

    // Call mergeSort on the entire array
    mergeSort(arr, 0, arr.size() - 1);

    // Print the sorted array
    cout << "Sorted array: ";
    for(int n : arr)
        cout << n << " ";
    cout << endl;

    return 0;
}
