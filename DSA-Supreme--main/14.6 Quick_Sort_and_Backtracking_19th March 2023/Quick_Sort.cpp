#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];   // last element as pivot
    int i = low;             // i will track position to place smaller elements

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            swap(arr[i], arr[j]);
            i++; // move boundary forward
        }
    }

    // place pivot at its correct position
    swap(arr[i], arr[high]);

    return i; // pivot index
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);  // partition index
        quickSort(arr, low, pi - 1);         // sort left side
        quickSort(arr, pi + 1, high);        // sort right side
    }
}

int main() {
    vector<int> arr = {10, 7, 8, 9, 1, 5};

    cout << "Before sorting: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    quickSort(arr, 0, arr.size() - 1);

    cout << "After sorting:  ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    return 0;
}
