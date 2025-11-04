// https://www.spoj.com/problems/EKO/

/*
    Problem Approach:
    -----------------
    - We are given N trees with different heights and need to collect at least M units of wood by cutting the trees at a certain height H.
    - If a tree's height is greater than H, we collect (tree_height - H) wood from that tree.
    - The goal is to find the maximum possible value of H such that at least M units of wood are collected.

    - This is a classic "search the answer" problem, where the answer (H) lies in a range [0, max_height].
    - We use Binary Search to efficiently find the maximum H.

    - For each mid (candidate H), we check if it's possible to collect at least M wood by cutting at height mid.
    - If possible, we try a higher H (to maximize), else we try a lower H.

    - Time Complexity: O(N * log(max_height)), where N is the number of trees.

    Alternative Approaches:
    ----------------------
    1. Brute Force: Try every possible H from 0 to max_height, for each H, sum the wood collected. (O(N * max_height)) - TLE for large inputs.
    2. Prefix Sum Optimization: Not directly applicable here since each query depends on H, not a fixed prefix.
    3. Segment Tree: For multiple queries, segment tree can be used, but for a single query, binary search is optimal.

    Dry Run Example at the end.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to check if it is possible to collect at least 'm' units of wood
// by cutting all trees at height 'cutHeight'
bool isPossible(const vector<long long int>& trees, long long int m, long long int cutHeight) {
    long long int woodCollected = 0; // Total wood collected at this cut height
    for (int i = 0; i < trees.size(); i++) {
        // If tree is taller than cutHeight, collect the excess wood
        if (trees[i] > cutHeight) {
            woodCollected += trees[i] - cutHeight;
        }
        // Early exit: If already collected enough wood, no need to continue
        if (woodCollected >= m) return true;
    }
    // Return true if collected wood is at least m
    return woodCollected >= m;
}

// Function to find the maximum saw blade height to collect at least 'm' wood
long long int maxSawBladeHeight(const vector<long long int>& trees, long long int m) {
    long long int start = 0; // Minimum possible height
    long long int end = *max_element(trees.begin(), trees.end()); // Maximum tree height
    long long int ans = -1; // Store the best (maximum) height found

    // Binary search for the answer
    while (start <= end) {
        long long int mid = start + (end - start) / 2; // Candidate cut height
        if (isPossible(trees, m, mid)) {
            // If possible to collect enough wood at this height,
            // store this as a potential answer and try for a higher height
            ans = mid;
            start = mid + 1;
        } else {
            // If not enough wood, try a lower height
            end = mid - 1;
        }
    }
    return ans; // Return the maximum possible height
}

int main() {
    long long int n, m;
    cin >> n >> m; // Input: number of trees and required wood
    vector<long long int> trees(n);
    for (long long int i = 0; i < n; ++i) {
        cin >> trees[i]; // Input: heights of trees
    }
    cout << maxSawBladeHeight(trees, m) << endl; // Output the answer
    return 0;
}

/*
Alternative Approach (Brute Force, for understanding only):

// O(N * max_height) - Not efficient for large inputs
long long int bruteForceMaxSawBladeHeight(const vector<long long int>& trees, long long int m) {
    long long int maxH = *max_element(trees.begin(), trees.end());
    for (long long int h = maxH; h >= 0; --h) {
        long long int wood = 0;
        for (auto t : trees) {
            if (t > h) wood += t - h;
        }
        if (wood >= m) return h;
    }
    return -1;
}

*/

/*
Dry Run Example:
----------------
Input:
4 7
20 15 10 17

Step-by-step:
- max_height = 20
- Binary search range: [0, 20]

1st Iteration: mid = 10
    Wood collected: (20-10)+(15-10)+(10-10)+(17-10) = 10+5+0+7 = 22 >= 7 (possible)
    -> Try higher: start = 11, ans = 10

2nd Iteration: mid = 15
    Wood collected: (20-15)+(15-15)+(10-15)+(17-15) = 5+0+0+2 = 7 >= 7 (possible)
    -> Try higher: start = 16, ans = 15

3rd Iteration: mid = 18
    Wood collected: (20-18)+(15-18)+(10-18)+(17-18) = 2+0+0+0 = 2 < 7 (not possible)
    -> Try lower: end = 17

4th Iteration: mid = 16
    Wood collected: (20-16)+(15-16)+(10-16)+(17-16) = 4+0+0+1 = 5 < 7 (not possible)
    -> Try lower: end = 15

Binary search ends. Maximum height = 15

Output: 15
*/