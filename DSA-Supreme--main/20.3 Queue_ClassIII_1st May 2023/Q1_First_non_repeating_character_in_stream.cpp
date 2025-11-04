/*
Approach Used:
---------------
We are given a stream of lowercase characters, and for each character added to the stream, we need to find the first non-repeating character in the stream so far. If there is no such character, we output '#'.

To solve this, we use:
1. A frequency array (size 26 for 'a'-'z') to keep track of how many times each character has appeared.
2. A queue to maintain the order of characters as they appear in the stream.
3. For each character, we update its frequency and push it into the queue.
4. We then check the front of the queue: if its frequency is more than 1, we pop it (since it's repeating). Otherwise, it's the first non-repeating character.
5. If the queue becomes empty, it means there is no non-repeating character at this point, so we append '#'.

This approach ensures O(1) time for each character (since queue operations and array access are O(1)), and O(N) overall for a string of length N.

Better Alternatives:
--------------------
1. **Using Doubly Linked List + Hash Map**: For a more generic solution (e.g., for all ASCII or Unicode), we can use a doubly linked list to maintain the order of non-repeating characters and a hash map to store pointers to nodes. This allows O(1) insertion, deletion, and lookup.
2. **Using Deque**: If we want to optimize for both ends, a deque can be used, but for this problem, a queue suffices.

Alternative code using doubly linked list + hash map (for all ASCII):
---------------------------------------------------------------------
/*
#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;
void solve(string& s) {
    unordered_map<char, list<char>::iterator> charPos;
    unordered_map<char, int> freq;
    list<char> dll;
    string ans = "";
    for(char ch : s) {
        freq[ch]++;
        if(freq[ch] == 1) {
            dll.push_back(ch);
            charPos[ch] = --dll.end();
        } else if(freq[ch] == 2) {
            dll.erase(charPos[ch]);
        }
        if(!dll.empty()) ans += dll.front();
        else ans += '#';
    }
    cout << ans;
}
*/

#include<iostream>
#include<queue>
using namespace std;

// Function to find first non-repeating character in a stream
void solve(string& s){
    // Frequency array to count occurrences of each character (assuming lowercase 'a'-'z')
    int count[26] = {0};

    // Queue to store characters in the order they appear
    queue<char> q;

    // String to store the answer
    string ans = "";

    // Iterate over each character in the input string
    for(int i = 0; i < s.length(); i++){
        char ch = s[i]; // Current character from stream

        count[ch - 'a']++; // Increment frequency of current character

        q.push(ch); // Add current character to the queue

        // Remove characters from the front of the queue if they are repeating
        while(!q.empty()){
            // If frequency of front character is more than 1, it's repeating, so remove it
            if(count[q.front() - 'a'] > 1){
                q.pop();
            }
            // If frequency is 1, it's the first non-repeating character
            else{
                ans.push_back(q.front());
                break; // Stop as we found the first non-repeating character
            }
        }

        // If queue is empty, there is no non-repeating character at this point
        if(q.empty()){
            ans.push_back('#');
        }
    }

    // Output the result string
    cout << ans;
}

int main(){
    string s = "aabc"; // Example input stream
    solve(s);
    return 0;
}

/*
Dry Run:
--------
Input: "aabc"

Step-by-step:
i=0, ch='a'
- count['a'] = 1
- queue: a
- front 'a' freq=1 -> ans="a"

i=1, ch='a'
- count['a'] = 2
- queue: a a
- front 'a' freq=2 -> pop
- queue: a
- front 'a' freq=2 -> pop
- queue: empty -> ans="a#"

i=2, ch='b'
- count['b'] = 1
- queue: b
- front 'b' freq=1 -> ans="a#b"

i=3, ch='c'
- count['c'] = 1
- queue: b c
- front 'b' freq=1 -> ans="a#bb"

Final Output: a#bb

Time Complexity: O(N), where N is the length of the string.
Space Complexity: O(26) for count array + O(N) for queue in worst case.
*/