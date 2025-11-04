#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> arr = {1, 3, 5, 7, 9, 11, 13};
    int key = 7;

    // Using STL binary_search to check if key exists
    bool found = binary_search(arr.begin(), arr.end(), key);

    if (found) {
        // To get the index, use lower_bound
        auto it = lower_bound(arr.begin(), arr.end(), key);
        int index = it - arr.begin();
        cout << "Element " << key << " found at index: " << index << endl;
    } else {
        cout << "Element " << key << " not found in the array." << endl;
    }

    return 0;
}
