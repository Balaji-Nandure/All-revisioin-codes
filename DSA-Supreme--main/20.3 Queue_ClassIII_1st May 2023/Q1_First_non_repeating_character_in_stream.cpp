/*
Problem:
---------
Given a stream of lowercase characters (string s),
for each character in the stream, find the first non-repeating character so far.
If none exists, output '#' for that position.

Example:
---------
Input:  "aabc"
Output: "a#bb"

Approach:
----------
1. Maintain:
   - a frequency array (count of each character)
   - a queue to store potential non-repeating characters.
2. For each character:
   - Increment its frequency.
   - Push it into the queue.
   - While the front of the queue has freq > 1 → pop it.
   - If queue is empty → append '#', else append queue.front().

Time: O(n)
Space: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

string firstNonRepeating(string s) {
    vector<int> freq(26, 0); // Initialize frequency array // For 'a' to 'z' tracking
    queue<char> q;            // Create character queue    // Stores potential candidates
    string ans = "";          // Initialize result string // Will store output sequence

    for (char ch : s) {       // Process each character   // Iterate through input stream
        freq[ch - 'a']++;     // Increment frequency      // Update count for current char
        q.push(ch);           // Add to candidate queue   // Always push new character

        // Remove repeating chars from front // Clean up invalid candidates
        while (!q.empty() && freq[q.front() - 'a'] > 1) // Check front validity // If repeating, remove
            q.pop();          // Remove invalid front     // Pop until valid found

        // Check for non-repeating char // Determine output character
        if (q.empty())        // If queue is empty        // No valid candidates left
            ans.push_back('#'); // Add '#' marker         // Indicates no non-repeating
        else                  // If valid candidate exists // Queue has non-repeating
            ans.push_back(q.front()); // Add front char   // First non-repeating found
    }

    return ans;               // Return final result      // Complete output sequence
}

int main() {
    string s = "aabc";
    cout << "Stream: " << s << "\n";
    cout << "First non-repeating sequence: " << firstNonRepeating(s) << "\n";

    /*
    Dry Run:
    s = "aabc"

    Step 1: 'a' → freq[a]=1 → queue=[a] → ans='a'
    Step 2: 'a' → freq[a]=2 → pop 'a' → queue=[] → ans='a#'
    Step 3: 'b' → freq[b]=1 → queue=[b] → ans='a#b'
    Step 4: 'c' → freq[c]=1 → queue=[b,c] → ans='a#bb'
    Output: "a#bb"
    */
}
