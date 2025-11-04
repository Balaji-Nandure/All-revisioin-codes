#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

// Helper function to find the maximum crossing sum across mid
int maxCrossingSum(const vector<int>& arr, int l, int mid, int r) {
    int sum = 0;
    int left_sum = INT_MIN;

    // Include elements on left of mid
    for (int i = mid; i >= l; --i) {
        sum += arr[i];
        left_sum = max(left_sum, sum);
    }

    sum = 0;
    int right_sum = INT_MIN;

    // Include elements on right of mid
    for (int i = mid + 1; i <= r; ++i) {
        sum += arr[i];
        right_sum = max(right_sum, sum);
    }

    return left_sum + right_sum;
}

// Divide and conquer function to find maximum subarray sum
int maxSubArraySum(const vector<int>& arr, int l, int r) {
    // Base case: only one element
    if (l == r)
        return arr[l];

    int mid = l + (r - l) / 2;

    // Return maximum of three possible cases
    // 1. Max subarray sum in left half
    // 2. Max subarray sum in right half
    // 3. Max subarray sum crossing the mid
    int left_max = maxSubArraySum(arr, l, mid);
    int right_max = maxSubArraySum(arr, mid + 1, r);
    int cross_max = maxCrossingSum(arr, l, mid, r);

    return max({left_max, right_max, cross_max});
}

int main() {
    // Sample array
    vector<int> arr = {2, -4, 3, -1, 2, -4, 3};

    int max_sum = maxSubArraySum(arr, 0, arr.size() - 1);

    cout << "Maximum subarray sum: " << max_sum << endl;

    return 0;
}
