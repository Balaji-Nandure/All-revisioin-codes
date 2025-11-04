/*
Approach Used:
---------------
We are implementing a Trie (Prefix Tree) data structure to efficiently store and search words. 
Each node represents a character and has up to 26 children (for each lowercase/uppercase English letter).
- insertWord: Recursively inserts each character of the word into the Trie.
- searchWord: Recursively searches for a word in the Trie.

Improvements made:
------------------
- Consistent handling of uppercase/lowercase (original code had a bug: insert used 'a', search used 'A').
- Used references and const correctness where possible.
- Used vector instead of raw array for children for better safety and flexibility.
- Added destructor to free memory.
- Added comments for all important lines.
- Provided a dry run at the end.
- Provided an alternative iterative approach in comments.
*/

#include <iostream>
#include <vector>
using namespace std;

// Trie Node definition
class TrieNode {
public:
    char data; // Character stored at this node
    vector<TrieNode*> children; // Pointers to child nodes (size 26 for a-z/A-Z)
    bool isTerminal; // True if this node marks the end of a word

    TrieNode(char d) : data(d), children(26, nullptr), isTerminal(false) {}

    // Destructor to free memory recursively
    ~TrieNode() {
        for (TrieNode* child : children) {
            if (child) delete child;
        }
    }
};

// Helper function to convert character to index (handles both uppercase and lowercase)
inline int charToIndex(char ch) {
    if (ch >= 'a' && ch <= 'z') return ch - 'a';
    if (ch >= 'A' && ch <= 'Z') return ch - 'A';
    return -1; // Invalid character
}

// Recursive function to insert a word into the Trie
void insertWord(TrieNode* root, const string& word) {
    // Base case: If word is empty, mark current node as terminal
    if (word.empty()) {
        root->isTerminal = true;
        return;
    }

    char ch = word[0];
    int index = charToIndex(ch); // Get index for the character

    if (index == -1) {
        // Ignore invalid characters
        insertWord(root, word.substr(1));
        return;
    }

    TrieNode* child;
    // If child node for this character exists, use it
    if (root->children[index] != nullptr) {
        child = root->children[index];
    } else {
        // Else, create a new node and link it
        child = new TrieNode(ch);
        root->children[index] = child;
    }

    // Recurse for the remaining substring
    insertWord(child, word.substr(1));
}

// Recursive function to search for a word in the Trie
bool searchWord(TrieNode* root, const string& word) {
    // Base case: If all characters are checked, return isTerminal
    if (word.empty())
        return root->isTerminal;

    char ch = word[0];
    int index = charToIndex(ch);

    if (index == -1) {
        // Ignore invalid characters
        return searchWord(root, word.substr(1));
    }

    TrieNode* child = root->children[index];
    // If child does not exist, word is not present
    if (child == nullptr)
        return false;

    // Recurse for the remaining substring
    return searchWord(child, word.substr(1));
}

/*
Alternative Iterative Approach (for insert and search):
-------------------------------------------------------
void insertWordIterative(TrieNode* root, const string& word) {
    TrieNode* curr = root;
    for (char ch : word) {
        int index = charToIndex(ch);
        if (index == -1) continue;
        if (!curr->children[index])
            curr->children[index] = new TrieNode(ch);
        curr = curr->children[index];
    }
    curr->isTerminal = true;
}

bool searchWordIterative(TrieNode* root, const string& word) {
    TrieNode* curr = root;
    for (char ch : word) {
        int index = charToIndex(ch);
        if (index == -1) continue;
        if (!curr->children[index])
            return false;
        curr = curr->children[index];
    }
    return curr->isTerminal;
}
*/

// Main function to demonstrate Trie operations
int main() {
    TrieNode* root = new TrieNode('-'); // Root node with dummy character

    // Insert words into the Trie
    insertWord(root, "CODING");
    insertWord(root, "COD");
    insertWord(root, "CODIN");
    insertWord(root, "CODER");
    insertWord(root, "CODINGO");
    insertWord(root, "FLAMINGO");

    // Search for a word in the Trie
    if (searchWord(root, "C")) {
        cout << "Found" << endl;
    } else {
        cout << "Not found" << endl;
    }

    // Clean up memory
    delete root;
    return 0;
}

/*
Dry Run:
--------
Insert "CODING":
- C: root->children[2] is null, create node for 'C'
- O: children[14] is null, create node for 'O'
- D: children[3] is null, create node for 'D'
- I: children[8] is null, create node for 'I'
- N: children[13] is null, create node for 'N'
- G: children[6] is null, create node for 'G'
- End: mark isTerminal = true

Insert "COD":
- C: already exists
- O: already exists
- D: already exists
- End: mark isTerminal = true

Search "C":
- C: exists, move to node
- End: isTerminal? No (since only "COD", "CODING", etc. are terminal, not "C")
- Output: Not found

Better Alternatives:
--------------------
- Use unordered_map<char, TrieNode*> for children to save space if alphabet is large or sparse.
- Use iterative approach for better stack usage.
- Use smart pointers for automatic memory management.
- Support for Unicode or non-English alphabets by generalizing children structure.

*/