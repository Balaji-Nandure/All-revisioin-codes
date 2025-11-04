// https://leetcode.com/problems/word-ladder/description/

/*
Approach Used:
---------------
- This is a classic BFS (Breadth First Search) approach to find the shortest transformation sequence from beginWord to endWord.
- Each word is treated as a node, and an edge exists between two nodes if they differ by exactly one character.
- We use a queue to perform BFS, and an unordered_set for O(1) lookup and to avoid revisiting words.
- For each word, we try changing every character to every possible lowercase letter and check if the new word exists in the wordList (set).
- If we reach the endWord, we return the number of steps taken.

Better Alternatives:
--------------------
1. **Bidirectional BFS**: Instead of searching from only the beginWord, we can search from both beginWord and endWord simultaneously. This can reduce the search space and improve performance.
2. **Preprocessing with Intermediate Words**: Preprocess the word list to create a mapping of all possible intermediate words (with one letter replaced by '*') to all words matching that pattern. This allows O(1) access to all neighbors.

Bidirectional BFS Example (in comments):
----------------------------------------
/*
int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    unordered_set<string> wordSet(wordList.begin(), wordList.end());
    if(wordSet.find(endWord) == wordSet.end()) return 0;
    unordered_set<string> beginSet{beginWord}, endSet{endWord}, visited;
    int len = 1;
    while(!beginSet.empty() && !endSet.empty()) {
        if(beginSet.size() > endSet.size()) swap(beginSet, endSet);
        unordered_set<string> temp;
        for(string word : beginSet) {
            for(int i = 0; i < word.size(); ++i) {
                char old = word[i];
                for(char c = 'a'; c <= 'z'; ++c) {
                    word[i] = c;
                    if(endSet.count(word)) return len + 1;
                    if(wordSet.count(word) && !visited.count(word)) {
                        temp.insert(word);
                        visited.insert(word);
                    }
                }
                word[i] = old;
            }
        }
        beginSet = temp;
        ++len;
    }
    return 0;
}
*/

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // Queue for BFS: stores pairs of (current word, current transformation count)
        queue<pair<string,int>> q;
        q.push({beginWord, 1}); // Start BFS from beginWord with count 1

        // Unordered set for fast lookup and to avoid revisiting words
        unordered_set<string> st(wordList.begin(), wordList.end());

        // If endWord is not in the wordList, no transformation is possible
        if(st.find(endWord) == st.end()) return 0;

        // Remove the beginWord from the set to prevent revisiting
        st.erase(beginWord);

        while(!q.empty()){
            // Get the front node from the queue
            pair<string,int> fNode = q.front();
            q.pop();

            string currString = fNode.first; // Current word
            int currCount = fNode.second;    // Number of transformations so far

            // If we have reached the endWord, return the transformation count
            if(currString == endWord){
                return currCount;
            }

            // Try changing every character of the current word
            for(int index = 0; index < currString.length(); index++){
                char originalChar = currString[index]; // Store original character

                // Replace character from 'a' to 'z'
                for(char ch = 'a'; ch <= 'z'; ch++){
                    if(ch == originalChar) continue; // Skip if the character is the same

                    currString[index] = ch; // Change the character

                    // If the new word exists in the set, it's a valid transformation
                    if(st.find(currString) != st.end()){
                        q.push({currString, currCount + 1}); // Add new word to queue with incremented count
                        st.erase(currString); // Remove from set to prevent revisiting
                    }
                }
                // Restore the original character for the next iteration
                currString[index] = originalChar;
            }
        }
        // If endWord is not reachable, return 0
        return 0;
    }
};

/*
Dry Run Example:
----------------
Input:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log","cog"]

Step-by-step:
1. Start with "hit", count = 1. Queue: [("hit",1)]
2. Change 'h' to 'a'..'z', only "hot" is in wordList. Queue: [("hot",2)]
3. "hot": change each letter, find "dot" and "lot". Queue: [("dot",3), ("lot",3)]
4. "dot": find "dog". Queue: [("lot",3), ("dog",4)]
5. "lot": find "log". Queue: [("dog",4), ("log",4)]
6. "dog": find "cog". Queue: [("log",4), ("cog",5)]
7. "cog" == endWord, return 5.

Output: 5

Time Complexity: O(N * L^2), where N = number of words, L = length of each word.
Space Complexity: O(N * L)
*/