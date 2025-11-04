#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Recursive function to find maximum sum of non-adjacent elements
int maxNonAdjacentSum(vector<int>& arr, int i) {
    if (i >= arr.size()) return 0; // base case: beyond array
    
    // Option 1: include arr[i] → skip next element
    int include = arr[i] + maxNonAdjacentSum(arr, i + 2);
    
    // Option 2: exclude arr[i]
    int exclude = maxNonAdjacentSum(arr, i + 1);
    
    // Return max of both choices
    return max(include, exclude);
}

int main() {
    vector<int> arr = {3, 2, 5, 10, 7};
    
    int result = maxNonAdjacentSum(arr, 0);
    cout << "Maximum sum of non-adjacent elements = " << result << endl;
    
    return 0;
}
