#include <iostream>
using namespace std;

// Recursive binary search function
int binarySearch(int arr[], int low, int high, int key) {
    // Base case: element not found
    if (low > high) return -1;

    int mid = low + (high - low) / 2;

    if (arr[mid] == key) return mid;              // key found
    else if (arr[mid] > key)                     // search in left half
        return binarySearch(arr, low, mid - 1, key);
    else                                         // search in right half
        return binarySearch(arr, mid + 1, high, key);
}

int main() {
    int n, key;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[n];
    cout << "Enter elements of array (sorted): ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    cout << "Enter element to search: ";
    cin >> key;

    int index = binarySearch(arr, 0, n - 1, key);

    if (index != -1)
        cout << "Element found at index: " << index << endl;
    else
        cout << "Element not found" << endl;

    return 0;
}
