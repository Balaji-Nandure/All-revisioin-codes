// leetcode 17 letter combination of a phone number


class Solution {
    public:
        vector<string> result;
        vector<string> mapping = {
            "",     // 0
            "",     // 1
            "abc",  // 2
            "def",  // 3
            "ghi",  // 4
            "jkl",  // 5
            "mno",  // 6
            "pqrs", // 7
            "tuv",  // 8
            "wxyz"  // 9
        };
    
        void backtrack(const string &digits, int index, string &current) {
            if (index == digits.size()) {
                result.push_back(current);
                return;
            }
    
            int digit = digits[index] - '0'; // convert char to int
            const string &letters = mapping[digit];
            for (char ch : letters) {
                current.push_back(ch);                // add letter
                backtrack(digits, index + 1, current); // recurse for next digit
                current.pop_back();                   // backtrack
            }
        }
    
        vector<string> letterCombinations(string digits) {
            if (digits.empty()) return {}; // edge case: empty input
            string current;
            backtrack(digits, 0, current);
            return result;
        }
    };
    