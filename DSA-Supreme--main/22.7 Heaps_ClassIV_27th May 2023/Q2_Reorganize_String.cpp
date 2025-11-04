// https://leetcode.com/problems/reorganize-string/submissions/959596416/

/*
Approach Used:
---------------
1. Count the frequency of each character in the string.
2. Use a max heap (priority queue) to always pick the two most frequent characters.
3. Place them alternately in the result string, reducing their count.
4. If at the end, a character is left with more than one count, it's impossible to reorganize.
5. This ensures no two adjacent characters are the same.

Why this works:
---------------
- By always picking the two most frequent remaining characters, we avoid placing the same character adjacently.
- If any character's frequency is more than (n+1)/2, it's impossible to rearrange.

Better Alternative Approach (with code in comments):
----------------------------------------------------
- Instead of custom node class, use std::pair<int, char> for heap.
- Use a queue to store the previous character that needs to wait before being used again.
- This can make the code cleaner and more efficient.

Example of alternative approach:
--------------------------------
/*
string reorganizeString(string s) {
    vector<int> freq(26, 0);
    for(char c : s) freq[c-'a']++;
    priority_queue<pair<int, char>> pq;
    for(int i=0; i<26; ++i) if(freq[i]) pq.push({freq[i], 'a'+i});
    string res = "";
    pair<int, char> prev = {0, '#'};
    while(!pq.empty()) {
        auto [cnt, ch] = pq.top(); pq.pop();
        res += ch;
        if(prev.first > 0) pq.push(prev);
        cnt--;
        prev = {cnt, ch};
    }
    // Check for adjacent duplicates
    for(int i=1; i<res.size(); ++i) if(res[i]==res[i-1]) return "";
    return res;
}
*/

class node{
    public:
        char data;   // character
        int count;   // frequency of character
        node(char d,int c){
            data = d;
            count = c;
        }
};

// Comparator for max heap: higher count comes first
class compare{
    public:
        bool operator()(node a,node b){
            return a.count < b.count;
        }
};

class Solution {
public:
    string reorganizeString(string s) {
        // Step 1: Count frequency of each character
        int freq[26] = {0};
        for(int i = 0; i < s.length(); i++){
            char ch = s[i];
            freq[ch-'a']++;
        }

        // Step 2: Build max heap of characters by frequency
        priority_queue<node, vector<node>, compare> maxHeap;
        for(int i = 0; i < 26; i++){
            if(freq[i] != 0){
                // Push character and its frequency into heap
                node temp(i+'a', freq[i]);
                maxHeap.push(temp);
            }
        }

        string ans = "";

        // Step 3: Greedily pick two most frequent characters and append to result
        while(maxHeap.size() > 1){
            // Fetch top 2 elements (most frequent)
            node first = maxHeap.top();
            maxHeap.pop();
            node second = maxHeap.top();
            maxHeap.pop();

            // Append both to result string
            ans += first.data;
            ans += second.data;

            // Decrement their counts
            first.count--;
            second.count--;

            // If still have remaining, push back to heap
            if(first.count != 0){
                maxHeap.push(first);
            }
            if(second.count != 0){
                maxHeap.push(second);
            }
        }

        // Step 4: If one character left, check if it can be placed
        if(maxHeap.size() == 1){
            node temp = maxHeap.top();
            maxHeap.pop();
            if(temp.count == 1){
                // Only one occurrence left, safe to append
                ans += temp.data;
            }
            else{
                // More than one left, cannot avoid adjacent duplicates
                ans = "";
            }
        }

        // Step 5: Return result (empty string if not possible)
        return ans;
    }
};

/*
Dry Run Example:
----------------
Input: s = "aab"

1. freq = [2,1,0,...]
2. maxHeap: [('a',2), ('b',1)]
3. Pop 'a'(2), 'b'(1): ans = "ab"
   - 'a' count becomes 1, push back to heap
4. maxHeap: [('a',1)]
5. Pop 'a'(1): ans = "aba"
6. Heap empty, done. Return "aba"

Input: s = "aaab"
1. freq = [3,1,0,...]
2. maxHeap: [('a',3), ('b',1)]
3. Pop 'a'(3), 'b'(1): ans = "ab"
   - 'a' count becomes 2, push back to heap
4. maxHeap: [('a',2)]
5. Pop 'a'(2): only one left, but count > 1, so impossible. Return ""

Time Complexity: O(N log K), where N = length of s, K = number of unique characters.
Space Complexity: O(K)
*/
