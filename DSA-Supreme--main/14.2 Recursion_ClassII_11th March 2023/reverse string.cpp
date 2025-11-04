#include <iostream>
using namespace std;

// Recursive function to reverse a string in-place
void reverseString(string& str, int left, int right) {
    if (left >= right) return; // Base case: done reversing
    swap(str[left], str[right]);
    reverseString(str, left + 1, right - 1);
}
    
int main() {
    string s = "recursion";
    reverseString(s, 0, s.length() - 1);
    cout << "Reversed: " << s << endl;
    return 0;
}
