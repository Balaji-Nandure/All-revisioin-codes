#include <iostream>
#include <vector>
using namespace std;

// Recursive function to print all subarrays of the given vector
void printSubarrays(const vector<int>& arr, int start, int end) {
    // Base case: If the starting index has reached the end of the array, terminate recursion
    if (start == arr.size())
        return;

    // Print the current subarray from index 'start' to index 'end'
    for (int i = start; i <= end; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    // If end index can be increased without exceeding array bounds, 
    // recursively expand the current subarray by moving 'end' forward
    if (end + 1 < arr.size()) {
        printSubarrays(arr, start, end + 1);
    } 
    // Otherwise, move the start index forward and reset end to start for the next subarray
    else {
        printSubarrays(arr, start + 1, start + 1);
    }
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    printSubarrays(arr, 0, 0);
    return 0;
}
