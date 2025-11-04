// https://learn.thecodehelp.in/s/courses/63ac9183e4b0f1067f1b7b32/take

/*
Approach Used (Updated):
------------------------
- We use the "Horizontal Scanning" approach.
- Start by assuming the first string is the common prefix.
- For each subsequent string, check if it starts with the current prefix.
- If not, repeatedly remove the last character from the prefix until it matches the start of the current string.
- If at any point the prefix becomes empty, return "" (no common prefix).
- This continues until all strings have been checked.

Time Complexity: O(N * M), where N = number of strings, M = length of the shortest string.
Space Complexity: O(1) extra (excluding output string).

Better Alternatives:
--------------------
1. **Sorting Approach**:
   - Sort the array of strings.
   - The common prefix of the first and last string will be the answer.
   - Time: O(NlogN + M), Space: O(1)
   - Code:
     ```
     string longestCommonPrefix(vector<string>& strs) {
         if(strs.empty()) return "";
         sort(strs.begin(), strs.end());
         string first = strs[0], last = strs.back();
         int i = 0;
         while(i < first.size() && i < last.size() && first[i] == last[i]) i++;
         return first.substr(0, i);
     }
     ```

2. **Trie-based Approach**:
   - Build a Trie of all strings, then traverse until a node has more than one child or is end of word.
   - Good for large datasets, but more complex.

Below is the updated code with detailed comments and a dry run at the end.
*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // Start with first string as prefix.
        // Iteratively shorten prefix using find() until all strings start with it.

        if(strs.empty()) return "";
        string prefix = strs[0];
        for(int i=1; i<strs.size(); i++){
            while(strs[i].find(prefix) != 0){ // means until prefix is not found at 0th index
                prefix = prefix.substr(0, prefix.size() - 1); 
                if(prefix.empty()) return "";
            }
        }

        return prefix;
    }
};

/*
Dry Run Example (Updated):
--------------------------
Input: strs = ["flower", "flow", "flight"]

Initial prefix = "flower"

Check with "flow":
    - "flow" does not start with "flower" -> shorten prefix to "flowe"
    - "flow" does not start with "flowe" -> shorten prefix to "flow"
    - "flow" starts with "flow" -> prefix remains "flow"

Check with "flight":
    - "flight" does not start with "flow" -> shorten prefix to "flo"
    - "flight" does not start with "flo" -> shorten prefix to "fl"
    - "flight" starts with "fl" -> prefix remains "fl"

All strings checked. Final prefix = "fl"

Output: "fl"
*/