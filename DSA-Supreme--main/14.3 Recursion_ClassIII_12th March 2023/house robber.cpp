/*
House Robber Problem (Recursive Approach)

Problem:
Given an array of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police (cannot rob two adjacent houses).

Recurrence:
For each house at index i, you have two choices:
  - Rob this house, and move to i+2 (since you cannot rob i+1)
  - Skip this house, move to i+1

Base case:
  - If idx >= nums.size(), return 0 (no more houses)

Recursive Formula:
  maxRob(idx) = max(nums[idx] + maxRob(idx+2), maxRob(idx+1))
*/

#include <iostream>
#include <vector>
using namespace std;

// Recursive function to solve House Robber problem
int houseRobberHelper(const vector<int>& nums, int idx) {
    // Base case: If we've gone past the last house
    if (idx >= nums.size()) return 0;

    // Choice 1: Rob this house, move to idx+2
    int rob = nums[idx] + houseRobberHelper(nums, idx + 2);

    // Choice 2: Skip this house, move to idx+1
    int skip = houseRobberHelper(nums, idx + 1);

    // Return the max of both choices
    return max(rob, skip);
}

int houseRobber(const vector<int>& nums) {
    return houseRobberHelper(nums, 0);
}

int main() {
    vector<int> nums = {2, 7, 9, 3, 1}; // Example input
    cout << "Max money that can be robbed: " << houseRobber(nums) << endl; // Output: 12
    return 0;
}
