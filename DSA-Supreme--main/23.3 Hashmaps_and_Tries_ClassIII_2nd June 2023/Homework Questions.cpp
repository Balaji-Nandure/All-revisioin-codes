/*
Approach:
-----------
The instruction is to dry run the class codes on at least 5-6 examples. 
Dry running means manually simulating the code's execution step by step with sample inputs to understand how the logic flows and to verify correctness.

Below is a template for how to dry run any code, with comments explaining each step.
Additionally, a better approach is to write automated test cases to validate the code, which is more efficient and less error-prone than manual dry runs.

Manual Dry Run Example (for a sample function, e.g., finding frequency of elements using hashmap):

Suppose we have the following code:
-------------------------------------------------
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// Function to count frequency of elements in an array
void printFrequencies(const vector<int>& arr) {
    unordered_map<int, int> freq; // hashmap to store frequency

    // Count frequency of each element
    for(int num : arr) {
        freq[num]++; // increment count for num
    }

    // Print frequencies
    for(auto& pair : freq) {
        cout << "Element: " << pair.first << ", Frequency: " << pair.second << endl;
    }
}

int main() {
    vector<int> arr = {1, 2, 2, 3, 1, 4, 2};
    printFrequencies(arr);
    return 0;
}
-------------------------------------------------

// Dry Run for arr = {1, 2, 2, 3, 1, 4, 2}:
// Step 1: freq = {}
// Step 2: num = 1 -> freq = {1:1}
// Step 3: num = 2 -> freq = {1:1, 2:1}
// Step 4: num = 2 -> freq = {1:1, 2:2}
// Step 5: num = 3 -> freq = {1:1, 2:2, 3:1}
// Step 6: num = 1 -> freq = {1:2, 2:2, 3:1}
// Step 7: num = 4 -> freq = {1:2, 2:2, 3:1, 4:1}
// Step 8: num = 2 -> freq = {1:2, 2:3, 3:1, 4:1}
// Output: 
// Element: 1, Frequency: 2
// Element: 2, Frequency: 3
// Element: 3, Frequency: 1
// Element: 4, Frequency: 1

// Repeat similar dry runs for 5-6 different input arrays to ensure correctness.

// Better Alternative Approach:
// Instead of manual dry runs, write automated test cases as follows:

/*
void testPrintFrequencies() {
    vector<vector<int>> testCases = {
        {1,2,2,3,1,4,2},
        {5,5,5,5},
        {1,2,3,4,5},
        {},
        {0,0,0,1,1,2}
    };
    for(const auto& arr : testCases) {
        printFrequencies(arr);
        cout << "----" << endl;
    }
}
*/

// This approach is more scalable and less error-prone.

// Summary of Approach:
// 1. Understand the logic of the code.
// 2. Choose 5-6 diverse test cases (including edge cases).
// 3. For each test case, simulate the code step by step (manual dry run).
// 4. Alternatively, write automated tests to validate the code.

// Dry Run Example (for above code):
// Input: {1,2,2,3,1,4,2}
// freq: {}
// After 1: {1:1}
// After 2: {1:1,2:1}
// After 2: {1:1,2:2}
// After 3: {1:1,2:2,3:1}
// After 1: {1:2,2:2,3:1}
// After 4: {1:2,2:2,3:1,4:1}
// After 2: {1:2,2:3,3:1,4:1}
// Output: 1->2, 2->3, 3->1, 4->1
