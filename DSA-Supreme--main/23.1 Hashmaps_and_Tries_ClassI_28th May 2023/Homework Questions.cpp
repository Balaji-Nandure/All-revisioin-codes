
/*
Approach and Detailed Explanation:

1) Design a Data Structure with O(1) Insertion, Deletion, Search, and Get Random:

   - The best approach is to use a combination of a vector and an unordered_map.
   - The vector stores the elements for O(1) random access.
   - The unordered_map stores the element and its index in the vector for O(1) search, insertion, and deletion.
   - For deletion, swap the element to be deleted with the last element in the vector, pop_back, and update the map accordingly.

   // Implementation:
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstdlib>
using namespace std;

class RandomizedSet {
    vector<int> nums; // stores the elements for O(1) random access
    unordered_map<int, int> mp; // maps element to its index in nums
public:
    // Inserts a value to the set. Returns true if the set did not already contain the specified element.
    bool insert(int val) {
        if (mp.count(val)) return false; // element already present
        nums.push_back(val); // add to vector
        mp[val] = nums.size() - 1; // store index in map
        return true;
    }
    // Removes a value from the set. Returns true if the set contained the specified element.
    bool remove(int val) {
        if (!mp.count(val)) return false; // element not present
        int idx = mp[val]; // get index of element to remove
        int last = nums.back(); // get last element
        nums[idx] = last; // move last element to idx
        mp[last] = idx; // update index of last element in map
        nums.pop_back(); // remove last element
        mp.erase(val); // remove from map
        return true;
    }
    // Returns true if the set contains the specified element.
    bool search(int val) {
        return mp.count(val) > 0;
    }
    // Get a random element from the set.
    int getRandom() {
        int idx = rand() % nums.size(); // generate random index
        return nums[idx];
    }
};

/*
Alternative Approaches:
- Using only unordered_set: O(1) insert, delete, search, but getRandom is O(n).
- Using only vector: O(1) getRandom, O(1) insert at end, but O(n) delete/search.
- The above approach is optimal for all O(1) operations.

Dry Run:
Insert 5: nums = [5], mp = {5:0}
Insert 10: nums = [5,10], mp = {5:0, 10:1}
Remove 5: swap 5 and 10, nums = [10], mp = {10:0}
Insert 7: nums = [10,7], mp = {10:0, 7:1}
getRandom: returns either 10 or 7

------------------------------------------------------------

2) Read documentation of maps from cpp reference.
   // Visit: https://en.cppreference.com/w/cpp/container/map
   // Key points:
   // - map is an associative container that stores key-value pairs in sorted order.
   // - O(log n) insertion, deletion, and search.
   // - unordered_map provides O(1) average time for these operations but does not maintain order.

------------------------------------------------------------

3) Convert code of reorganize string using map instead of freq array.

   // Problem: Given a string, rearrange it so that no two adjacent characters are the same.
   // Approach:
   // - Use a map<char, int> to count frequencies.
   // - Use a max heap (priority_queue) to always pick the character with the highest remaining frequency.
   // - Place the most frequent character, then the next, and so on, ensuring no two same characters are adjacent.

#include <queue>
#include <string>
#include <map>
using namespace std;

string reorganizeString(string s) {
    map<char, int> freq; // count frequency of each character
    for (char c : s) freq[c]++; // build frequency map

    // max heap: pair of (frequency, character)
    priority_queue<pair<int, char>> pq;
    for (auto& p : freq) pq.push({p.second, p.first});

    string result = "";
    pair<int, char> prev = {0, '#'}; // previous character used

    while (!pq.empty()) {
        auto curr = pq.top(); pq.pop();
        result += curr.second; // add current character to result

        // If previous character still has remaining count, push it back
        if (prev.first > 0) pq.push(prev);

        // Decrease count and set as previous
        curr.first--;
        prev = curr;
    }

    // If result length is not equal to input, not possible to reorganize
    if (result.length() != s.length()) return "";

    return result;
}

/*
Alternative Approach:
- Use unordered_map instead of map for faster average performance.
- Use a custom comparator for priority_queue if using unordered_map.

Dry Run:
Input: "aab"
freq: {a:2, b:1}
pq: [(2,a), (1,b)]
result: ""
Step 1: pop (2,a), result="a", prev=(1,a)
Step 2: pop (1,b), result="ab", push prev (1,a), prev=(0,b)
Step 3: pop (1,a), result="aba", prev=(0,a)
Done. Output: "aba"
*/
