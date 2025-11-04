#include<iostream>
#include<string> // use <string> instead of <string.h> for C++ strings
using namespace std;

/*
Approach:
- Demonstrate various string operations using C++ STL string class.
- Show input methods, string manipulation, and inbuilt functions.
- Highlight best practices and alternatives in comments.
*/

int main(){
    // Input a string without spaces (stops at whitespace)
    string str;
    cout << "Enter a word (no spaces): ";
    cin >> str; // reads input until first whitespace

    // To read a full line (with spaces), use getline
    cout << "Enter a sentence (with spaces): ";
    cin.ignore(); // clear input buffer before getline to avoid skipping
    getline(cin, str); // reads entire line including spaces

    // Demonstrate inbuilt string functions
    string st = "Bhavya";

    // Print length of string
    cout << "Length of st: " << st.length() << endl; // .length() returns number of characters

    // Check if string is empty
    cout << "Is st empty? " << (st.empty() ? "Yes" : "No") << endl; // .empty() returns true if string is empty

    // Add a character at the end
    st.push_back('A'); // st becomes "BhavyaA"

    // Remove last character
    st.pop_back(); // st becomes "Bhavya" again

    // Print substring from index 0 to 5 (6 characters)
    cout << "Substring (0,6): " << st.substr(0,6) << endl; // .substr(start, length)

    // Compare string with another string
    cout << "Comparison with 'Bhavya': " << st.compare("Bhavya") << endl; // returns 0 if equal

    // Find substring in a string
    string sentence = "Hello all";
    cout << "Index of 'Hello' in sentence: " << sentence.find("Hello") << endl; // returns starting index or npos

    // Replace part of string (replace 0-4 with "hi")
    sentence.replace(0,5,"hi"); // sentence becomes "hi all"
    cout << "After replace: " << sentence << endl;

    // Erase part of string (erase from index 0, 5 characters)
    sentence.erase(0,5); // sentence becomes "ll" (since "hi al" is erased)
    cout << "After erase: " << sentence << endl;

    return 0;
}

/*
Better/Alternative Approaches (in comments):

- For input, always clear the input buffer before using getline after cin.
- Use std::getline for all string input if you want to handle spaces.
- For string comparison, prefer == operator for readability: (st == "Bhavya")
- For checking if a substring exists, check if .find() != string::npos.
- For string concatenation, use + operator or append().
- For erasing or replacing, always check bounds to avoid exceptions.

Dry Run Example:
----------------
Suppose user inputs:
  Enter a word (no spaces): Hello
  Enter a sentence (with spaces): Hello all

- str after cin: "Hello"
- str after getline: "Hello all"
- st: "Bhavya"
- st.length(): 6
- st.empty(): false
- st after push_back('A'): "BhavyaA"
- st after pop_back(): "Bhavya"
- st.substr(0,6): "Bhavya"
- st.compare("Bhavya"): 0
- sentence: "Hello all"
- sentence.find("Hello"): 0
- sentence after replace(0,5,"hi"): "hi all"
- sentence after erase(0,5): "ll"

Output:
Length of st: 6
Is st empty? No
Substring (0,6): Bhavya
Comparison with 'Bhavya': 0
Index of 'Hello' in sentence: 0
After replace: hi all
After erase: ll
*/