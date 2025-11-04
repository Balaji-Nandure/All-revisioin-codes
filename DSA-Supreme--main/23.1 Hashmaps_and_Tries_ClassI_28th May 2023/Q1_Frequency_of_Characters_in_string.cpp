/*
Approach:
----------
We are given a string and need to find the frequency of each character in it.
We use an unordered_map (hashmap) to store the frequency of each character.
We iterate through the string, and for each character, we increment its count in the map.
Finally, we print each character and its frequency.

This approach has O(n) time complexity, where n is the length of the string.

Better alternatives:
--------------------
1. If the string contains only lowercase/uppercase English letters, we can use an array of size 26 for faster access.
2. For case-insensitive counting, we can convert all characters to lower/upper case before counting.
3. For Unicode or large character sets, unordered_map is preferred.

Alternative code using array (for lowercase English letters only):
------------------------------------------------------------------
    string str = "bhavya";
    int freq[26] = {0};
    for(char ch : str) {
        freq[ch - 'a']++;
    }
    for(int i = 0; i < 26; ++i) {
        if(freq[i] > 0)
            cout << char('a' + i) << " " << freq[i] << endl;
    }

Dry Run:
--------
Input: "bhavya"
Step 1: freq['b'] = 1
Step 2: freq['h'] = 1
Step 3: freq['a'] = 1
Step 4: freq['v'] = 1
Step 5: freq['y'] = 1
Step 6: freq['a'] = 2 (incremented)
Final Output:
b 1
h 1
a 2
v 1
y 1
(Actual order may vary due to unordered_map)

*/

// Include necessary headers
#include<iostream>
#include<unordered_map>
using namespace std;

int main(){
    string str = "bhavya"; // Input string whose character frequencies are to be counted

    unordered_map<char,int> freq; // Hashmap to store frequency of each character

    // Iterate over each character in the string
    for(char ch : str){
        freq[ch]++; // Increment the frequency count for character 'ch'
    }

    // Print each character and its frequency
    for(const auto& entry : freq){
        cout << entry.first << " " << entry.second << endl; // Output: character and its frequency
    }

    return 0; // Indicate successful program termination
}

/*
Alternative approach using array (for lowercase English letters only):

    string str = "bhavya";
    int freq[26] = {0};
    for(char ch : str) {
        freq[ch - 'a']++;
    }
    for(int i = 0; i < 26; ++i) {
        if(freq[i] > 0)
            cout << char('a' + i) << " " << freq[i] << endl;
    }

Dry Run:
--------
Input: "bhavya"
Step-by-step:
str[0] = 'b' -> freq['b'] = 1
str[1] = 'h' -> freq['h'] = 1
str[2] = 'a' -> freq['a'] = 1
str[3] = 'v' -> freq['v'] = 1
str[4] = 'y' -> freq['y'] = 1
str[5] = 'a' -> freq['a'] = 2

Final freq map:
a: 2
b: 1
h: 1
v: 1
y: 1

Output (unordered_map order may vary):
b 1
h 1
a 2
v 1
y 1
*/