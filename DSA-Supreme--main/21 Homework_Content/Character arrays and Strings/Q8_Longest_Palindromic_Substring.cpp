class Solution {
    public:
        int expandFromCenter(const string &s, int left, int right) { // Expand around center // check for palindrome
            int n = s.size(); // Get string length // used for bounds
            while(left >= 0 && right < n && s[left] == s[right]) { // Check bounds and match // expand as long as palindrome
                left--; // Move left pointer left // try to grow palindrome
                right++; // Move right pointer right // try to grow palindrome
            }
            return right - left - 1; // Return palindrome length // subtract overshoot
        }
    
        string longestPalindrome(string s) { // Find longest palindromic substring // main function
            int n = s.size(); // Get string length // used for loop and checks
            if(n <= 1) return s; // If string is empty or single char // it's already a palindrome
            int start = 0, maxLen = 1; // Initialize start index and max length // default to first char
            for(int i = 0; i < n; i++) { // Loop through each character // consider each as center
                int len1 = expandFromCenter(s, i, i); // Odd length palindrome // center at i
                int len2 = expandFromCenter(s, i, i + 1); // Even length palindrome // center between i and i+1
                int len = max(len1, len2); // Take longer palindrome // compare both cases
                if(len > maxLen) { // If found longer palindrome // update result
                    maxLen = len; // Update max length // store new length
                    start = i - (len - 1) / 2; // Calculate new start index // adjust for even/odd length
                }
            }
            return s.substr(start, maxLen); // Return longest palindrome substring // use start and length
        }
    };