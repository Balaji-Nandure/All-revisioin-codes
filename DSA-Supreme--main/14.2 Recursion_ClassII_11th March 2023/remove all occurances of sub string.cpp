#include <iostream>
using namespace std;

// class Solution {
//     public:
//         string removeOccurrences(string s, string part) {
//             int pos = s.find(part); 
//             while(pos >= 0) {
//                 s.erase(pos, part.size()); 
//                 pos = s.find(part); 
//             }
//             return s;
//         }
//     };

// Recursive function to remove all occurrences of a substring from a string
string removeAllOccurrences(string s, const string& part) {
    // Base case: if substring 'part' not found, return original string
    auto pos = s.find(part);
    if (pos == -1) return s;
 
    // Remove the substring at found position
    string newStr = s.substr(0, pos) + s.substr(pos + part.length());

    // Recursive call to remove any further occurrences
    return removeAllOccurrences(newStr, part);
}

int main() {
    string s, part;
    cout << "Enter main string: ";
    getline(cin, s);
    cout << "Enter substring to remove: ";
    getline(cin, part);

    string result = removeAllOccurrences(s, part);
    cout << "After removing all occurrences of '" << part << "': " << result << endl;
    return 0;
}
