/*
Approach Used:
---------------
We use a Trie (Prefix Tree) data structure to efficiently store and retrieve words for prefix-based search suggestions.
- Each node in the Trie represents a character and has up to 26 children (for each lowercase English letter).
- We insert all words into the Trie.
- For each prefix of the input string, we traverse the Trie and collect all words that start with that prefix.
- This is useful for implementing features like search bar suggestions.

Better Alternatives:
--------------------
1. **Limiting Suggestions**: In real-world applications, we often limit the number of suggestions (e.g., top 3) for performance.
2. **Storing Full Words at Terminal Nodes**: Instead of reconstructing words during traversal, store the full word at terminal nodes for faster retrieval.
3. **Using HashMaps Instead of Arrays**: For non-lowercase or Unicode support, use unordered_map instead of fixed-size arrays.
4. **Iterative Traversal**: Use iterative DFS/BFS for large Tries to avoid stack overflow.
5. **Sorting Suggestions**: Store suggestions in sorted order or use a min-heap for top-k suggestions.

Below is the improved code with detailed comments and a dry run at the end.
*/

#include<iostream>
#include<vector>
#include<algorithm> // For sorting suggestions if needed
using namespace std;

// Trie Node definition
class TrieNode{
    public:
        char data; // Character stored at this node
        TrieNode* children[26]; // Pointers to child nodes for each letter
        bool isTerminal; // True if this node marks the end of a word

        TrieNode(char d){
            this->data = d;
            for(int i = 0; i < 26; i++){
                children[i] = NULL; // Initialize all children as NULL
            }
            this->isTerminal = false; // Not terminal by default
        }
};

// Insert a word into the Trie
void insertWord(TrieNode* root, const string& word, int idx = 0) {
    // Base case: If all characters are inserted, mark node as terminal
    if(idx == word.length()) {
        root->isTerminal = true;
        return;
    }
    char ch = word[idx];
    int index = ch - 'a'; // Map character to index (0-25)
    TrieNode* child;

    // If child node for current character exists, use it
    if(root->children[index] != NULL) {
        child = root->children[index];
    }
    else {
        // Otherwise, create a new node
        child = new TrieNode(ch);
        root->children[index] = child;
    }
    // Recurse for the next character
    insertWord(child, word, idx + 1);
}

// Search for a word in the Trie
bool searchWord(TrieNode* root, const string& word, int idx = 0){
    // Base case: If all characters are checked, return isTerminal
    if(idx == word.length())
        return root->isTerminal;
    char ch = word[idx];
    int index = ch - 'a'; // Fixed bug: was 'A' in original, should be 'a'
    TrieNode* child = root->children[index];
    // If child does not exist, word is not present
    if(child == NULL)
        return false;
    // Recurse for the next character
    return searchWord(child, word, idx + 1);
}

// Helper function to collect all words starting from current Trie node
void storeSuggestion(TrieNode* curr, vector<string>& temp, string& prefix, int suggestionLimit = -1){
    // If current node is terminal, add the prefix as a suggestion
    if(curr->isTerminal){
        temp.push_back(prefix);
        // If limiting suggestions, return if limit reached
        if(suggestionLimit != -1 && temp.size() >= suggestionLimit)
            return;
    }
    // Try all possible children (a-z)
    for(char ch = 'a'; ch <= 'z'; ch++){
        int index = ch - 'a';
        TrieNode* next = curr->children[index];
        if(next != NULL){
            // Add character to prefix and recurse
            prefix.push_back(ch);
            storeSuggestion(next, temp, prefix, suggestionLimit);
            // Backtrack: remove last character
            prefix.pop_back();
            // If limiting suggestions, return if limit reached
            if(suggestionLimit != -1 && temp.size() >= suggestionLimit)
                return;
        }
    }
}

// Get suggestions for each prefix of the input string
vector<vector<string>> getSuggestions(TrieNode* root, const string& input, int suggestionLimit = -1){
    TrieNode* prev = root; // Start from root
    vector<vector<string>> output; // To store suggestions for each prefix
    string prefix = "";
    for(int i = 0; i < input.length(); i++){
        char lastCh = input[i];
        int index = lastCh - 'a';
        TrieNode* curr = prev->children[index];
        if(curr == NULL){
            // If prefix not found, break (no further suggestions possible)
            break;
        }
        else{
            vector<string> temp;
            prefix.push_back(lastCh);
            storeSuggestion(curr, temp, prefix, suggestionLimit); // Collect all suggestions for current prefix
            // Optional: sort suggestions if needed
            // sort(temp.begin(), temp.end());
            output.push_back(temp);
            prev = curr; // Move to next node for next prefix
        }
    }
    return output;
}

int main(){
    // List of words to insert into Trie
    vector<string> v = {"love", "lover", "loving", "last", "lost", "lane", "lord"};

    string input = "lovi"; // Input string for which suggestions are needed

    TrieNode* root = new TrieNode('-'); // Root node (dummy character)

    // Insert all words into Trie
    for(int i = 0; i < v.size(); i++){
        insertWord(root, v[i]);
    }

    // Get suggestions for each prefix of input
    vector<vector<string>> ans = getSuggestions(root, input);

    cout << "Printing the answer" << endl;
    for(int i = 0; i < ans.size(); i++){
        cout << "Suggestions for prefix \"" << input.substr(0, i+1) << "\": ";
        for(int j = 0; j < ans[i].size(); j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

/*
-------------------------------
Dry Run for input = "lovi"
-------------------------------
Words in Trie: love, lover, loving, last, lost, lane, lord

Step-by-step:
Prefix: "l"
- All words starting with 'l': love, lover, loving, last, lost, lane, lord

Prefix: "lo"
- All words starting with 'lo': love, lover, loving, lost, lord

Prefix: "lov"
- All words starting with 'lov': love, lover, loving

Prefix: "lovi"
- All words starting with 'lovi': loving

Output:
Suggestions for prefix "l": love lover loving last lost lane lord 
Suggestions for prefix "lo": love lover loving lost lord 
Suggestions for prefix "lov": love lover loving 
Suggestions for prefix "lovi": loving 

-------------------------------
Alternative Approach (with code):
-------------------------------
1. Limit suggestions to top 3 (for each prefix):

// In storeSuggestion, add a limit parameter and stop recursion when temp.size() == 3

void storeSuggestion(TrieNode* curr, vector<string>& temp, string& prefix, int suggestionLimit = 3){
    if(curr->isTerminal){
        temp.push_back(prefix);
        if(temp.size() >= suggestionLimit)
            return;
    }
    for(char ch = 'a'; ch <= 'z'; ch++){
        int index = ch - 'a';
        TrieNode* next = curr->children[index];
        if(next != NULL){
            prefix.push_back(ch);
            storeSuggestion(next, temp, prefix, suggestionLimit);
            prefix.pop_back();
            if(temp.size() >= suggestionLimit)
                return;
        }
    }
}

2. Use unordered_map for Unicode or case-insensitive support.

3. Store full word at terminal node to avoid reconstructing prefix.

4. Use iterative DFS/BFS for large Tries.

-------------------------------
*/