// https://leetcode.com/problems/integer-to-roman/description/

/*
Approach Used in This Code:
---------------------------
- This code uses a **greedy approach** to convert an integer to its Roman numeral representation.
- The idea is to always subtract the largest possible Roman value from the number and append the corresponding symbol to the result string.
- The process continues until the number becomes zero.

Steps:
1. Prepare two arrays: one for Roman symbols (from largest to smallest, including subtractive notations like "CM", "IV", etc.), and one for their corresponding integer values.
2. Iterate through the arrays, and for each value, subtract it from the number as many times as possible, appending the symbol each time.
3. Continue until the number is reduced to zero.

Time Complexity: O(1) (since the number of Roman numeral symbols is constant and the loop runs at most a fixed number of times)
Space Complexity: O(1) extra (ignoring output string)

Better Alternatives:
--------------------
1. **Hardcoded Place Value Mapping (Faster, Less Flexible):**
   - Predefine the Roman numeral representation for each digit at each place (thousands, hundreds, tens, ones).
   - Build the result by concatenating the corresponding strings for each digit.
   - Example code:
     ```
     string intToRoman(int num) {
         string thousands[] = {"", "M", "MM", "MMM"};
         string hundreds[]  = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
         string tens[]      = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
         string ones[]      = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
         return thousands[num/1000] + hundreds[(num%1000)/100] + tens[(num%100)/10] + ones[num%10];
     }
     ```
   - This is even faster and more direct, but less general.

2. **Recursive Approach:**
   - Use recursion to repeatedly subtract the largest possible value and build the string.
   - Not recommended for this problem due to unnecessary overhead.

3. **Using Map (Less Efficient):**
   - Use a map to store value-symbol pairs and iterate in descending order.
   - Not as efficient as using arrays.

Dry Run Example:
----------------
Input: num = 1994

Step-by-step:
- Start with num = 1994, ans = ""
- i=0: values[0]=1000, RomanSymbols[0]="M"
    - 1994 >= 1000: ans += "M", num = 994
- i=1: values[1]=900, RomanSymbols[1]="CM"
    - 994 >= 900: ans += "CM", num = 94
- i=2: values[2]=500, 94<500; i=3: 94<400; i=4: 94<100
- i=5: values[5]=90, RomanSymbols[5]="XC"
    - 94 >= 90: ans += "XC", num = 4
- i=6: values[6]=50, 4<50; i=7: 4<40; i=8: 4<10; i=9: 4<9; i=10: 4<5
- i=11: values[11]=4, RomanSymbols[11]="IV"
    - 4 >= 4: ans += "IV", num = 0
- Done. Final ans = "MCMXCIV"

*/

class Solution {
public:
    string intToRoman(int num) {
        // Array of Roman numeral symbols, ordered from largest to smallest (including subtractive notations)
        const string RomanSymbols[] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        // Corresponding integer values for the Roman symbols
        const int values[] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
        string ans = ""; // Resultant Roman numeral string

        // Iterate over all Roman values from largest to smallest
        for(int i = 0; i < 13; i++){
            // While the current value can be subtracted from num
            while(num >= values[i]){
                ans += RomanSymbols[i]; // Append the Roman symbol to the result
                num -= values[i];       // Subtract the value from num
            }
        }
        return ans; // Return the final Roman numeral string
    }
};

/*
Alternative (Hardcoded Place Value Mapping) - Fastest:
------------------------------------------------------
string intToRoman(int num) {
    string thousands[] = {"", "M", "MM", "MMM"};
    string hundreds[]  = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
    string tens[]      = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
    string ones[]      = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
    return thousands[num/1000] + hundreds[(num%1000)/100] + tens[(num%100)/10] + ones[num%10];
}
*/