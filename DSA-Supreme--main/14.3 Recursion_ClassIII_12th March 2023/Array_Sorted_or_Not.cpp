#include <iostream>
using namespace std;

// Recursive function to check if array is sorted in non-decreasing order
bool isSorted(int arr[], int n) {
    // Base case: If array has 0 or 1 element, it is sorted
    if (n == 0 || n == 1) return true;

    // Check if first element is greater than second element
    if (arr[0] > arr[1]) return false; // If so, array is not sorted

    // Recursive call: check if the rest of the array is sorted
    return isSorted(arr + 1, n - 1); // Move to next element
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n; // Read the array size from user

    int arr[n];
    cout << "Enter elements of array: ";
    // Input array elements from user
    for (int i = 0; i < n; i++) cin >> arr[i];

    // Use isSorted function to check if array is sorted and print result
    if (isSorted(arr, n))
        cout << "Array is sorted" << endl;
    else
        cout << "Array is NOT sorted" << endl;

    return 0;
}
