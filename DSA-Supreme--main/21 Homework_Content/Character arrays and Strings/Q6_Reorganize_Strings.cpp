// https://leetcode.com/problems/reorganize-string/description/

/*
<h3>Approach (Greedy):</h3>
- Count the frequency of each character in the string.
- Find the character with the maximum frequency.
- If the max frequency is more than (n+1)/2, return "" (impossible).
- Place the most frequent character at even indices (0, 2, 4, ...).
- Place the remaining characters in the remaining positions, filling even indices first, then odd indices.

<h3>Dry Run:</h3>
Input: "aab"
- freq: [2,1,0,...] ('a':2, 'b':1)
- maxCount = 2, maxChar = 'a'
- maxCount <= (3+1)/2 = 2, so possible
- Place 'a' at even indices: result[0]='a', result[2]='a'
- Place 'b' at next available (odd) index: result[1]='b'
- Output: "aba"
*/

class Solution {
public:
    string reorganizeString(string s) {
        int n = s.size(); // Get length of input string // Used for result size and checks
        vector<int> freq(26, 0); // Frequency array for 26 lowercase letters // Initialized to 0

        for(char c: s){ // Loop through each character in s // For counting frequency
            freq[c - 'a']++; // Increment count for this character // Maps 'a'-'z' to 0-25
        }

        int maxCount = 0; // To store highest frequency found // Used for feasibility check
        int maxChar = 0; // To store index of most frequent char // Will be used for placement
        for(int i=0; i<26; i++){ // Loop through all possible characters // Check each letter
            if(freq[i] > maxCount){ // If current char freq is higher // Update maxCount and maxChar
                maxCount = freq[i]; // Store new max frequency // Used for placement and check
                maxChar = i; // Store index of most frequent char // Needed for placement
            }
        }

        if(maxCount > (n+1)/2) return ""; // If impossible to reorganize // More than half chars same

        string result(n, ' '); // Initialize result string with spaces // Will fill in characters

        int idx = 0; // Start placing at index 0 (even) // Used to alternate positions
        while(freq[maxChar] > 0){ // While there are most frequent chars left // Place them first
            result[idx] = (char) (maxChar + 'a'); // Place most frequent char at idx // Convert index to char
            idx += 2; // Move to next even index // Ensures no adjacent same chars
            freq[maxChar]--; // Decrement count for this char // Track how many left to place
        }

        for(int i=0; i<26; i++){ // Loop through all characters // Place remaining chars
        int idx = 0;
        // Place most frequent char at even indices
        while(freq[maxChar] > 0){
            result[idx] = (char) (maxChar + 'a');
            idx += 2;
            freq[maxChar]--;
        }

        // Place remaining characters
        for(int i=0; i<26; i++){
            while(freq[i] > 0){
                if(idx >= n) idx = 1;
                result[idx] = (char) (i + 'a');
                idx += 2;
                freq[i]--;
            }
        }

        return result;
    }
};