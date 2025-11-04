// https://leetcode.com/problems/longest-common-prefix/

/*
Approach 1: Brute Force (Horizontal Scanning)
---------------------------------------------
- We take the first string as a reference and compare each character with the corresponding character in all other strings.
- If all strings have the same character at the current position, we add it to the answer.
- If any string differs or is shorter, we stop and return the answer so far.

Time Complexity: O(N*M) where N = number of strings, M = length of the shortest string.
Space Complexity: O(1) (ignoring output string)

Alternative Approaches (detailed code in comments below):
---------------------------------------------------------
1. Vertical Scanning: Compare characters column-wise.
2. Divide and Conquer: Recursively find LCP for subarrays and merge.
3. Binary Search: Binary search on prefix length.
4. Trie-based: Build a Trie and walk down as long as only one child exists and not terminal.

See below for code and dry run.
*/

// Brute force approach with detailed comments
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return ""; // Edge case: empty input

        string ans = ""; // To store the result

        // Loop through each character of the first string
        for(int i = 0; i < strs[0].length(); i++) {
            char ch = strs[0][i]; // Current character to compare
            bool match = true;    // Flag to check if all strings match at this position

            // Compare this character with the same position in all other strings
            for(int j = 1; j < strs.size(); j++) {
                // If current string is shorter than i+1 or character doesn't match
                if(i >= strs[j].size() || ch != strs[j][i]) {
                    match = false; // Mismatch found
                    break;         // No need to check further
                }
            }

            if(!match) {
                break; // Stop at first mismatch
            } else {
                ans.push_back(ch); // All strings matched at this position, add to answer
            }
        }
        return ans; // Return the longest common prefix found
    }
};

/*
Approach 2: Trie-based Solution
-------------------------------
- Insert all strings into a Trie.
- Walk down the Trie from the root as long as there is only one child and the node is not terminal.
- The path traversed is the longest common prefix.

Time Complexity: O(N*M) for insertion and O(M) for LCP extraction.
Space Complexity: O(N*M) for Trie storage.

This approach is efficient when there are many strings with long common prefixes.
*/

// Trie Node definition
class TrieNode {
public:
    char data;                  // Character stored at this node
    TrieNode* children[26];     // Pointers to child nodes (for lowercase a-z)
    bool isTerminal;            // True if this node marks the end of a word
    int childCount;             // Number of non-null children

    TrieNode(char d) {
        this->data = d;
        for(int i = 0; i < 26; i++) {
            children[i] = NULL; // Initialize all children to NULL
        }
        this->isTerminal = false;
        childCount = 0;
    }
};

// Insert a word into the Trie
void insertWord(TrieNode* root, const string& word) {
    TrieNode* curr = root;
    for(char ch : word) {
        int index = ch - 'a';
        if(curr->children[index] == NULL) {
            curr->children[index] = new TrieNode(ch); // Create new node if not present
            curr->childCount++;                       // Increment child count
        }
        curr = curr->children[index]; // Move to the child node
    }
    curr->isTerminal = true; // Mark end of word
}

// Find the longest common prefix by traversing the Trie
void findLCP(const string& first, string &ans, TrieNode* root) {
    TrieNode* curr = root;
    for(char ch : first) {
        int index = ch - 'a';
        // Continue if only one child and not terminal
        if(curr->childCount == 1 && !curr->isTerminal) {
            ans.push_back(ch);           // Add character to answer
            curr = curr->children[index];// Move to next node
        } else {
            break; // Stop if more than one child or terminal node
        }
    }
}

// Trie-based solution class
class Solution_Trie {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return ""; // Edge case

        TrieNode* root = new TrieNode('-'); // Root node with dummy character

        // Insert all strings into the Trie
        for(const string& word : strs) {
            insertWord(root, word);
        }

        string ans = "";
        // Use the first string to guide the LCP search
        findLCP(strs[0], ans, root);

        // Clean up Trie memory (not shown here for brevity)
        return ans;
    }
};

/*
Alternative Approach: Binary Search on Prefix Length
---------------------------------------------------
- Find the minimum string length (minLen).
- Binary search for the maximum prefix length L such that all strings share the same prefix of length L.

Code:
---------------------------------
string commonPrefix(const vector<string>& strs, int len) {
    string prefix = strs[0].substr(0, len);
    for(const string& s : strs) {
        if(s.substr(0, len) != prefix)
            return "";
    }
    return prefix;
}
string longestCommonPrefix(vector<string>& strs) {
    if(strs.empty()) return "";
    int minLen = INT_MAX;
    for(const string& s : strs) minLen = min(minLen, (int)s.size());
    int low = 0, high = minLen;
    string ans = "";
    while(low <= high) {
        int mid = low + (high - low) / 2;
        string pref = commonPrefix(strs, mid);
        if(!pref.empty()) {
            ans = pref;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return ans;
}
---------------------------------
Time Complexity: O(N*logM), where N = number of strings, M = min string length.

*/

/*
Dry Run Example:
----------------
Input: ["flower","flow","flight"]

Brute Force:
- i=0: ch='f', all strings have 'f' at 0 -> ans="f"
- i=1: ch='l', all strings have 'l' at 1 -> ans="fl"
- i=2: ch='o', "flight"[2]='i' != 'o' -> break
Output: "fl"

Trie:
- Insert "flower", "flow", "flight" into Trie.
- Traverse: 'f' (1 child), 'l' (1 child), next node has >1 child (branch: 'o' and 'i'), stop.
Output: "fl"
*/
