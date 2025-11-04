// Problem: Find Peak Element in a Mountain Array using Binary Search

// Steps:
// 1. Mountain array: arr[0..peak..n-1], strictly increasing then decreasing.
// 2. A peak element satisfies: arr[i] > arr[i-1] and arr[i] > arr[i+1].
// 3. Use binary search:
//    - mid = (left + right)/2
//    - If arr[mid] < arr[mid+1] → peak is on the right
//    - Else → peak is on the left (or mid is peak)
// 4. Continue until left == right → peak found at index 'left'

// Complexity:
// Time = O(log n), Space = O(1)


#include <iostream>
#include <vector>
using namespace std;

// Function to find peak element index in mountain array
int findPeak(vector<int>& arr) {
    int left = 0, right = arr.size() - 1;

    while (left < right) {
        int mid = left + (right - left) / 2;

        // If middle element is less than next element, peak is on the right
        if (arr[mid] < arr[mid + 1])
            left = mid + 1;
        else
            // Else peak is at mid or on the left
            right = mid;
    }

    // left == right → peak index
    return left;
}

int main() {
    vector<int> arr = {1, 3, 5, 7, 6, 4, 2};
    int peakIndex = findPeak(arr);
    cout << "Peak element is at index: " << peakIndex << endl;
    cout << "Peak element value: " << arr[peakIndex] << endl;
    return 0;
}
