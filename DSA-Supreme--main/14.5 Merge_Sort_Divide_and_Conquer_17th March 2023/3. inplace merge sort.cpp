#include <iostream>
#include <vector>
using namespace std;

// In-place merge for arr[l..mid] (sorted), arr[mid+1..r] (sorted)
void inplaceMerge(vector<int>& arr, int l, int mid, int r) {
    int start1 = l;
    int start2 = mid + 1;

    // Traverse through both sorted subarrays
    while (start1 <= mid && start2 <= r) {
        // If element at start1 is already in right place, move ahead
        if (arr[start1] <= arr[start2]) {
            start1++;
        } else {
            // arr[start2] is lower and out of place, need to shift elements
            int value = arr[start2];
            int index = start2;

            // Shift all the elements between start1 and start2 one step to the right
            while (index > start1) {
                arr[index] = arr[index - 1];
                index--;
            }
            arr[start1] = value;

            // Update pointers
            start1++;
            mid++;    // Because all elements between start1 and start2 are now one step to right
            start2++;
        }
    }
}

// Recursive function to perform in-place merge sort on arr[l..r]
void inplaceMergeSort(vector<int>& arr, int l, int r) {
    if (l >= r) return;

    int mid = l + (r - l) / 2;
    inplaceMergeSort(arr, l, mid);
    inplaceMergeSort(arr, mid + 1, r);

    inplaceMerge(arr, l, mid, r);
}

int main() {
    vector<int> arr = {5, 2, 9, 1, 5, 6};

    inplaceMergeSort(arr, 0, arr.size() - 1);

    cout << "Sorted array: ";
    for (int n : arr)
        cout << n << " ";
    cout << endl;

    return 0;
}
