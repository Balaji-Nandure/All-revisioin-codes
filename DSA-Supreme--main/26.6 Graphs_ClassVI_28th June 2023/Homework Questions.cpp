
/*
Approach and Explanation for Each Problem:

1) Word Ladder Problem (with visited data structure):

   - Problem: Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord, such that:
        - Only one letter can be changed at a time.
        - Each transformed word must exist in the word list.
   - Approach:
        - Use BFS (Breadth First Search) to find the shortest path.
        - Use a visited set to avoid revisiting words.
        - At each step, for the current word, try changing every character to every possible lowercase letter and check if the new word is in the word list and not visited.
        - If we reach endWord, return the number of steps.
   - Code:
*/

#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>
using namespace std;

// Function to return length of shortest transformation sequence
int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    unordered_set<string> wordSet(wordList.begin(), wordList.end()); // Store all words for O(1) lookup
    if(wordSet.find(endWord) == wordSet.end()) return 0; // If endWord not in wordList, return 0

    queue<pair<string, int>> q; // Queue for BFS, stores (currentWord, currentLevel)
    q.push({beginWord, 1});
    unordered_set<string> visited; // To keep track of visited words
    visited.insert(beginWord);

    while(!q.empty()) {
        auto [word, level] = q.front();
        q.pop();

        if(word == endWord) return level; // Found the endWord

        for(int i = 0; i < word.size(); ++i) {
            string temp = word;
            for(char c = 'a'; c <= 'z'; ++c) {
                temp[i] = c;
                // If the new word is in wordSet and not visited
                if(wordSet.find(temp) != wordSet.end() && visited.find(temp) == visited.end()) {
                    q.push({temp, level + 1});
                    visited.insert(temp); // Mark as visited
                }
            }
        }
    }
    return 0; // No transformation found
}

/*
Better Alternative Approach:
- Bidirectional BFS can be used to optimize the search, starting from both beginWord and endWord and meeting in the middle.
- This reduces the search space and improves performance.

Code for Bidirectional BFS (in comments):

int ladderLengthBiBFS(string beginWord, string endWord, vector<string>& wordList) {
    unordered_set<string> wordSet(wordList.begin(), wordList.end());
    if(wordSet.find(endWord) == wordSet.end()) return 0;

    unordered_set<string> beginSet{beginWord}, endSet{endWord}, visited;
    int len = 1;

    while(!beginSet.empty() && !endSet.empty()) {
        if(beginSet.size() > endSet.size()) swap(beginSet, endSet);
        unordered_set<string> tempSet;
        for(auto word : beginSet) {
            for(int i = 0; i < word.size(); ++i) {
                string temp = word;
                for(char c = 'a'; c <= 'z'; ++c) {
                    temp[i] = c;
                    if(endSet.find(temp) != endSet.end()) return len + 1;
                    if(wordSet.find(temp) != wordSet.end() && visited.find(temp) == visited.end()) {
                        tempSet.insert(temp);
                        visited.insert(temp);
                    }
                }
            }
        }
        beginSet = tempSet;
        ++len;
    }
    return 0;
}

*/

/*
Dry Run Example:
beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]

Step 1: Start with "hit", level = 1
Step 2: Change 'h' to 'h'...'z', find "hot" in wordList, push ("hot", 2)
Step 3: From "hot", change one letter at a time, find "dot" and "lot", push ("dot", 3), ("lot", 3)
Step 4: From "dot", find "dog", push ("dog", 4)
Step 5: From "dog", find "cog", push ("cog", 5)
Step 6: "cog" == endWord, return 5

*/

/*
2) Path with Minimum Effort - Test Case Discovery:

   - Problem: Given a grid of heights, find a path from top-left to bottom-right such that the maximum absolute difference in heights between two consecutive cells is minimized.
   - Approach: Use Dijkstra's algorithm (min-heap) to always expand the path with the minimum effort so far.
   - Task: Try to find a test case which fails the current code (if any).
   - Comment: If your code does not handle edge cases like multiple paths with the same effort, or does not properly update the effort for already visited cells, it may fail.
   - Example of a tricky test case:

Grid:
[
 [1,2,2],
 [3,8,2],
 [5,3,5]
]

Expected Output: 2

If your code does not update the effort for a cell when a better path is found, it may fail.

*/

/*
3) Word Ladder II (All Shortest Transformation Sequences):

   - Problem: Find all shortest transformation sequences from beginWord to endWord.
   - Approach:
        - Use BFS to build the graph of shortest paths.
        - Use DFS or backtracking to reconstruct all paths from beginWord to endWord.
   - Code (in comments):

vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
    unordered_set<string> wordSet(wordList.begin(), wordList.end());
    vector<vector<string>> res;
    unordered_map<string, vector<string>> parents;
    unordered_set<string> levelVisited;
    queue<string> q;
    q.push(beginWord);
    bool found = false;

    while(!q.empty() && !found) {
        int size = q.size();
        levelVisited.clear();
        for(int i = 0; i < size; ++i) {
            string word = q.front(); q.pop();
            string orig = word;
            for(int j = 0; j < word.size(); ++j) {
                char old = word[j];
                for(char c = 'a'; c <= 'z'; ++c) {
                    word[j] = c;
                    if(wordSet.find(word) != wordSet.end()) {
                        if(word == endWord) found = true;
                        if(!parents.count(word)) q.push(word);
                        parents[word].push_back(orig);
                        levelVisited.insert(word);
                    }
                }
                word[j] = old;
            }
        }
        for(auto& w : levelVisited) wordSet.erase(w);
    }

    vector<string> path{endWord};
    function<void(string)> dfs = [&](string word) {
        if(word == beginWord) {
            vector<string> temp = path;
            reverse(temp.begin(), temp.end());
            res.push_back(temp);
            return;
        }
        for(auto& p : parents[word]) {
            path.push_back(p);
            dfs(p);
            path.pop_back();
        }
    };
    if(found) dfs(endWord);
    return res;
}

/*
Dry Run for Word Ladder II:
beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]

Possible shortest sequences:
["hit","hot","dot","dog","cog"]
["hit","hot","lot","log","cog"]
*/



