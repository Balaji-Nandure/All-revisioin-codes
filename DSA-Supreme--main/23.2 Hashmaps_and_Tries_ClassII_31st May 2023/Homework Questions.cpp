
/*
Approach:
We implement a Trie (Prefix Tree) with insertion, search, and deletion functionalities.
- Each node contains an array of pointers to its children (for 26 lowercase English letters) and a boolean to mark the end of a word.
- Insertion: Traverse the Trie, creating nodes as needed for each character.
- Search: Traverse the Trie, checking if each character exists.
- Deletion: Recursively delete nodes, only removing nodes that are not prefixes for other words.

Better Alternatives:
- Use unordered_map<char, TrieNode*> instead of a fixed-size array for space efficiency if the character set is sparse.
- Use smart pointers (e.g., std::unique_ptr) for automatic memory management.
- For Unicode or large alphabets, use hash maps instead of arrays.

Below is the improved code with detailed comments and a dry run at the end.
*/

#include <iostream>
using namespace std;

// Trie Node definition
class TrieNode {
public:
    TrieNode* children[26]; // Pointers to child nodes for each letter
    bool isEndOfWord;       // True if node represents end of a word

    TrieNode() {
        // Initialize all children as nullptr and isEndOfWord as false
        for (int i = 0; i < 26; ++i)
            children[i] = nullptr;
        isEndOfWord = false;
    }
};

// Trie class encapsulating root node and operations
class Trie {
private:
    TrieNode* root;

    // Helper function for deletion
    bool deleteHelper(TrieNode* node, const string& key, int depth) {
        if (!node) return false;

        // If last character of key is being processed
        if (depth == key.size()) {
            // This node is no more end of word after removal of given key
            if (node->isEndOfWord)
                node->isEndOfWord = false;

            // If node has no children, it is safe to delete
            for (int i = 0; i < 26; ++i)
                if (node->children[i])
                    return false; // Not safe to delete

            delete node;
            return true; // Node deleted
        }

        int index = key[depth] - 'a';
        if (deleteHelper(node->children[index], key, depth + 1)) {
            // Last node marked, delete the link
            node->children[index] = nullptr;

            // Check if current node is now useless
            if (!node->isEndOfWord) {
                for (int i = 0; i < 26; ++i)
                    if (node->children[i])
                        return false;
                delete node;
                return true;
            }
        }
        return false;
    }

public:
    Trie() {
        root = new TrieNode();
    }

    // Insert a word into the Trie
    void insert(const string& key) {
        TrieNode* node = root;
        for (char ch : key) {
            int index = ch - 'a';
            // Create node if not present
            if (!node->children[index])
                node->children[index] = new TrieNode();
            node = node->children[index];
        }
        node->isEndOfWord = true; // Mark end of word
    }

    // Search for a word in the Trie
    bool search(const string& key) {
        TrieNode* node = root;
        for (char ch : key) {
            int index = ch - 'a';
            if (!node->children[index])
                return false; // Character path not found
            node = node->children[index];
        }
        return node->isEndOfWord; // True if end of word is reached
    }

    // Delete a word from the Trie
    void remove(const string& key) {
        deleteHelper(root, key, 0);
    }
};

/*
Alternative Approach (using unordered_map for children):
// #include <unordered_map>
// class TrieNode {
// public:
//     unordered_map<char, TrieNode*> children;
//     bool isEndOfWord;
//     TrieNode() : isEndOfWord(false) {}
// };
// This saves space for sparse alphabets but is slower for dense, fixed-size alphabets.
*/

// Dry Run Example:

/*
Insert: "cat", "cap", "can", "dog", "dot", "dove"
Search: "cat", "cap", "can", "dog", "dot", "dove", "cow" (should return false for "cow")
Delete: "cat", "dog"
Search again: "cat" (should be false), "cap" (should be true), "dog" (should be false), "dot" (should be true)

Sample Output:
Insert: cat
Insert: cap
Insert: can
Insert: dog
Insert: dot
Insert: dove
Search cat: 1
Search cap: 1
Search can: 1
Search dog: 1
Search dot: 1
Search dove: 1
Search cow: 0
Delete cat
Delete dog
Search cat: 0
Search cap: 1
Search dog: 0
Search dot: 1
*/

int main() {
    Trie trie;
    // Insert words
    trie.insert("cat");
    trie.insert("cap");
    trie.insert("can");
    trie.insert("dog");
    trie.insert("dot");
    trie.insert("dove");

    // Search words
    cout << "Search cat: " << trie.search("cat") << endl;
    cout << "Search cap: " << trie.search("cap") << endl;
    cout << "Search can: " << trie.search("can") << endl;
    cout << "Search dog: " << trie.search("dog") << endl;
    cout << "Search dot: " << trie.search("dot") << endl;
    cout << "Search dove: " << trie.search("dove") << endl;
    cout << "Search cow: " << trie.search("cow") << endl;

    // Delete words
    trie.remove("cat");
    trie.remove("dog");

    // Search again after deletion
    cout << "Search cat: " << trie.search("cat") << endl;
    cout << "Search cap: " << trie.search("cap") << endl;
    cout << "Search dog: " << trie.search("dog") << endl;
    cout << "Search dot: " << trie.search("dot") << endl;

    return 0;
}
