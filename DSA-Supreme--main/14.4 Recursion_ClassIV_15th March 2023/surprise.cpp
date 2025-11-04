#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

/* 
1️⃣ Problem: Maximum Sum of Non-Adjacent Elements
   - Given an array, return the maximum sum where no two elements are adjacent.
   - Example: [3,2,5,10,7] → 15 (3 + 5 + 7 OR 3 + 10).
*/
int maxNonAdjacentSum(vector<int>& arr, int i = 0) {
    if (i >= arr.size()) return 0;
    int include = arr[i] + maxNonAdjacentSum(arr, i + 2);
    int exclude = maxNonAdjacentSum(arr, i + 1);
    return max(include, exclude);
}

/* 
2️⃣ Problem: Subset Sum (Yes/No)
   - Check if a subset of array elements sums to target.
   - Example: arr = [3, 34, 4, 12, 5, 2], sum = 9 → true ([4,5]).
*/
bool subsetSum(vector<int>& arr, int n, int sum) {
    if (sum == 0) return true;
    if (n == 0) return false;
    if (arr[n-1] > sum) return subsetSum(arr, n-1, sum);
    return subsetSum(arr, n-1, sum) || subsetSum(arr, n-1, sum - arr[n-1]);
}

/* 
3️⃣ Problem: Count Subsets with Given Sum
   - Count how many subsets sum to a given value.
   - Example: arr = [1,2,3], sum = 3 → subsets = { [1,2], [3] } → 2 ways.
*/
int countSubsets(vector<int>& arr, int n, int sum) {
    if (sum == 0) return 1;
    if (n == 0) return 0;
    if (arr[n-1] > sum) return countSubsets(arr, n-1, sum);
    return countSubsets(arr, n-1, sum) + countSubsets(arr, n-1, sum - arr[n-1]);
}

/* 
4️⃣ Problem: Generate All Subsets of an Array
   - Print all possible subsets.
   - Example: arr = [1,2] → {}, {1}, {2}, {1,2}.
*/
void generateSubsets(vector<int>& arr, int index, vector<int>& current) {
    if (index == arr.size()) {
        cout << "{ ";
        for (int x : current) cout << x << " ";
        cout << "}\n";
        return;
    }
    // Include current element
    current.push_back(arr[index]);
    generateSubsets(arr, index + 1, current);
    current.pop_back();
    // Exclude current element
    generateSubsets(arr, index + 1, current);
}

/* 
5️⃣ Problem: Partition Equal Subset Sum
   - Can we partition array into two subsets with equal sum?
   - Example: [1,5,11,5] → true ([1,5,5] and [11]).
*/
bool canPartition(vector<int>& arr, int n, int sum) {
    if (sum == 0) return true;
    if (n == 0 || sum < 0) return false;
    return canPartition(arr, n-1, sum - arr[n-1]) || canPartition(arr, n-1, sum);
}

/* 
6️⃣ Problem: Longest Common Subsequence (LCS)
   - Find length of longest subsequence common in both strings.
   - Example: "abcde", "ace" → "ace" → length = 3.
*/
int LCS(string s1, string s2, int i, int j) {
    if (i == 0 || j == 0) return 0;
    if (s1[i-1] == s2[j-1]) 
        return 1 + LCS(s1, s2, i-1, j-1);
    else 
        return max(LCS(s1, s2, i-1, j), LCS(s1, s2, i, j-1));
}

int main() {
    // 1️⃣ Max non-adjacent sum
    vector<int> arr1 = {3, 2, 5, 10, 7};
    cout << "Max Non-Adjacent Sum = " << maxNonAdjacentSum(arr1) << "\n";

    // 2️⃣ Subset Sum (Yes/No)
    vector<int> arr2 = {3, 34, 4, 12, 5, 2};
    int sum = 9;
    cout << "Subset with sum " << sum << " exists? " 
         << (subsetSum(arr2, arr2.size(), sum) ? "Yes" : "No") << "\n";

    // 3️⃣ Count Subsets with Given Sum
    vector<int> arr3 = {1, 2, 3};
    int target = 3;
    cout << "Number of subsets with sum " << target << " = " 
         << countSubsets(arr3, arr3.size(), target) << "\n";

    // 4️⃣ Generate All Subsets
    vector<int> arr4 = {1, 2};
    vector<int> current;
    cout << "All subsets of [1,2]:\n";
    generateSubsets(arr4, 0, current);

    // 5️⃣ Partition Equal Subset Sum
    vector<int> arr5 = {1, 5, 11, 5};
    int total = 0;
    for (int x : arr5) total += x;
    cout << "Can partition equally? " 
         << ((total % 2 == 0 && canPartition(arr5, arr5.size(), total/2)) ? "Yes" : "No") << "\n";

    // 6️⃣ LCS
    string s1 = "abcde", s2 = "ace";
    cout << "Length of LCS(\"abcde\",\"ace\") = " << LCS(s1, s2, s1.size(), s2.size()) << "\n";

    return 0;
}
