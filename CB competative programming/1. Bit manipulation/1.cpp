#include <iostream>
#include <vector>
using namespace std;

// Function to check if a number is odd using bit manipulation
bool isOdd(int x) {
    return (x & 1);
}
// Get ith bit (0-indexed, from right)
int getIthBit(int x, int i) {
    return (x >> i) & 1;
}

// Set ith bit: Use bitwise OR with mask (1<<i) to set i-th bit to 1
int setIthBit(int x, int i) {
    return x | (1 << i);
}

// Function to clear (set to 0) the i-th bit of integer x (0-indexed from right)
int clearIthBit(int x, int i) {
    int mask = ~(1 << i); // Mask with all 1's except 0 at position i
    return x & mask;
}

// Function to update the i-th bit of x to value v (v is 0 or 1)
int updateBit(int x, int i, int v) {
    x = (x & ~(1 << i)) | (v << i);
    return x;
}

// Function to clear all bits from 0 to i (inclusive) in x
int clearLastIBits(int x, int i) {
    int mask = (~0) << (i + 1);
    return x & mask;
}

// Function to clear bits from position i to j (inclusive) in x
int clearBitsInRange(int x, int i, int j) {
    int left = (~0) << (j + 1);       // 1s before position j+1
    int right = (1 << i) - 1;         // 1s after position i-1
    int mask = left | right;          // 1s outside [i, j], 0s in [i, j]
    return x & mask;
}

// Function to find the unique element in a vector of size 2n+1, where all others appear twice
int findUniqueElement(const vector<int>& nums) {
    int ans = 0;
    for(int num : nums) {
        ans ^= num;
    }
    return ans;
}

int main() {
    vector<int> nums = {2, 3, 4, 3, 2};
    cout << findUniqueElement(nums) << endl; // Outputs 4
    return 0;
}
