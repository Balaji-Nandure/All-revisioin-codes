/*
Approach:
---------
- The goal is to arrange a list of non-negative integers such that they form the largest possible number when concatenated.
- Convert all integers to strings for easy concatenation and comparison.
- Sort the string numbers using a custom comparator: for two strings a and b, compare (a+b) and (b+a). If (a+b) is greater, a should come before b.
- After sorting, concatenate all strings to form the result.
- If the largest number is "0" (i.e., all numbers are zero), return "0" instead of something like "000...".

Dry Run:
--------
Input: nums = [3, 30, 34, 5, 9]
Step 1: Convert to strings: ["3", "30", "34", "5", "9"]
Step 2: Sort with custom comparator:
    - "9" + "5" = "95" > "5" + "9" = "59" => "9" before "5"
    - "5" + "34" = "534" > "34" + "5" = "345" => "5" before "34"
    - "34" + "3" = "343" > "3" + "34" = "334" => "34" before "3"
    - "3" + "30" = "330" > "30" + "3" = "303" => "3" before "30"
    - Final sorted: ["9", "5", "34", "3", "30"]
Step 3: Concatenate: "9534330"
Output: "9534330"
*/

class Solution { // Solution class for forming largest number // main logic container
    public:
        // Custom comparator for sorting strings // decides order for largest concatenation
        static bool cmp(string a, string b){ 
            string t1 = a+b; // Concatenate a followed by b // e.g., "3" + "30" = "330"
            string t2 = b+a; // Concatenate b followed by a // e.g., "30" + "3" = "303"
            return t1 > t2; // Return true if t1 is greater // ensures larger number comes first
        }
    
        string largestNumber(vector<int>& nums) { // Forms largest number from vector // returns as string
            vector<string> snums; // Vector to store string versions of numbers // for easy concatenation
            for(auto n: nums){ // Loop through each number in input // convert all to string
                snums.push_back(to_string(n)); // Convert integer to string and add to snums // e.g., 3 -> "3"
            }
    
            sort(snums.begin(), snums.end(), cmp); // Sort strings using custom comparator // largest combination first
            if(snums[0] == "0") return "0"; // If largest is "0", all are zero // return single "0"
            string ans = ""; // Initialize answer string // will store final result
            for(auto str: snums){ // Loop through sorted strings // build the answer
                ans += str; // Append current string to answer // concatenate in order
            }
    
            return ans; // Return the final concatenated string // largest number as string
        }
    };