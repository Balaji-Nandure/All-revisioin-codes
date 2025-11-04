
/*
Approach & Comments for Each Problem:

1) Find space complexity of merge sort.
   // Merge Sort is a divide and conquer algorithm.
   // At each recursive call, the array is divided into two halves.
   // During the merge step, a temporary array is used to store merged output.
   // Space Complexity: O(n) due to the temporary array used for merging.
   // Also, recursion stack uses O(log n) space, but O(n) dominates.
   // Alternative: In-place merge sort can reduce space, but is complex and rarely used in practice.


   */


#include <iostream>  // Include input/output stream library for console operations
#include <string>    // Include string library for string manipulation functions
#include <vector>    // Include vector library for dynamic array operations
#include <unordered_map>  // Include hash map library for key-value pair storage

using namespace std;  // Use standard namespace to avoid std:: prefix


// 1) Last occurrence - Find the last position of a character in string
int lastOccurrence(const string& s, char c, int index) {  // Function signature with string reference, target character, and current index
    if(index < 0) return -1;  // Base case: if index goes negative, character not found
    if(s[index] == c) return index;  // Base case: if current character matches, return current index
    return lastOccurrence(s, c, index - 1);  // Recursive call: move to previous index and continue search
}

// 2) Reverse String - Reverse a string using recursion by swapping characters
string reverseString(const string& s, int index = 0) {  // Function with string reference and starting index (default 0)
    if(index >= s.size() / 2) return s;  // Base case: when we reach middle, string is fully reversed
    string reversed = s;  // Create a copy of the string to modify and return
    swap(reversed[index], reversed[s.size() - index - 1]);  // Swap character at current index with its mirror position
    return reverseString(reversed, index + 1);  // Recursive call: move to next index and continue swapping
}

// 3) Add 2 strings - Add two numbers represented as strings digit by digit
string addStrings(const string& num1, const string& num2, int carry = 0, int i = -1, int j = -1) {  // Function with two number strings, carry value, and indices
    if(i == -1) i = num1.size() - 1;  // Initialize first string index to last digit if not set
    if(j == -1) j = num2.size() - 1;  // Initialize second string index to last digit if not set
    if(i < 0 && j < 0 && carry == 0) return "";  // Base case: all digits processed and no carry remaining
    int n1 = i >= 0 ? num1[i] - '0' : 0;  // Get digit from first string or 0 if index out of bounds
    int n2 = j >= 0 ? num2[j] - '0' : 0;  // Get digit from second string or 0 if index out of bounds
    int sum = n1 + n2 + carry;  // Calculate sum of two digits plus any carry from previous addition
    return addStrings(num1, num2, sum / 10, i - 1, j - 1) + char(sum % 10 + '0');  // Recursive call with new carry and append current digit to result
}

// 4) Palindrome check - Check if string reads same forwards and backwards
bool isPalindrome(const string& s, int start = 0) {  // Function with string reference and starting position (default 0)
    int end = s.size() - start - 1;  // Calculate corresponding end position for current start position
    if(start >= end) return true;  // Base case: when pointers meet or cross, string is palindrome
    if(s[start] != s[end]) return false;  // If characters at start and end don't match, not a palindrome
    return isPalindrome(s, start + 1);  // Recursive call: move start pointer inward and continue checking
}

// 5) Subarray print - Print all possible subarrays of an array recursively
void printSubarrays(vector<int>& arr, int start, int end) {  // Function with array reference, start and end indices
    if(end == arr.size()) return;  // Base case: when end reaches array size, all subarrays printed
    else if(start > end) printSubarrays(arr, 0, end + 1);  // If start exceeds end, move to next ending position
    else {  // Current subarray from start to end needs to be printed
        for(int i = start; i <= end; i++) {  // Loop through current subarray elements
            cout << arr[i] << " ";  // Print each element followed by space
        }
        cout << endl;  // Print newline after each subarray for better formatting
        printSubarrays(arr, start + 1, end);  // Recursive call: move start position forward for next subarray
    }
}

// 6) Remove character - Recursively remove all occurrences of a character from string
string removeCharacter(const string& s, char c, int index = 0) {  // Function with string reference, target character, and current index
    if(index == s.size()) return "";  // Base case: reached end of string, return empty string
    if(s[index] == c) return removeCharacter(s, c, index + 1);  // If current character matches target, skip it and continue
    return s[index] + removeCharacter(s, c, index + 1);  // Include current character in result and continue with next index
}

// 7) Integer to English words - Convert digits to their English word representation
string digitToWords(int n) {  // Function that takes an integer and returns its word representation
    if(n < 0) return "Negative " + digitToWords(-n);  // Handle negative numbers by adding "Negative" prefix
    vector<string> words = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};  // Array of digit names
    return n < 10 ? words[n] : digitToWords(n / 10) + " " + words[n % 10];  // Return single digit word or recursively process multiple digits
}

// 8) Count ones - Count number of digit '1' occurrences in an integer
int countOnes(int n) {  // Function that takes an integer and counts occurrences of digit 1
    if(n == 0) return 0;  // Base case: when number becomes 0, no more digits to check
    return (n % 10 == 1) + countOnes(n / 10);  // Add 1 if last digit is 1, then recursively check remaining digits
}

// 9) Wildcard matching - Match string with pattern containing '?' wildcard
bool isMatch(const string& s, const string& pattern, int i = 0, int j = 0) {  // Function with string, pattern, and current indices
    if(j == pattern.size()) return i == s.size();  // Base case: if pattern exhausted, string should also be exhausted
    bool match = (i < s.size() && (s[i] == pattern[j] || pattern[j] == '?'));  // Check if current characters match or pattern has wildcard
    if(match) return isMatch(s, pattern, i + 1, j + 1);  // If match found, advance both pointers and continue
    return false;  // If no match and no wildcard, pattern doesn't match string
}

// 10) House robbery - Find maximum money that can be robbed without robbing adjacent houses
int robHouses(vector<int>& nums, int index = 0) {  // Function with money array and current house index
    if(index >= nums.size()) return 0;  // Base case: no more houses to rob, return 0
    return max(nums[index] + robHouses(nums, index + 2), robHouses(nums, index + 1));  // Choose max between robbing current house (skip next) or skipping current house
}

// 11) Stock profit - Find maximum profit from buying and selling stock once
int maxProfit(vector<int>& prices, int index = 0, int minPrice = INT_MAX) {  // Function with price array, current index, and minimum price seen so far
    if(index == prices.size()) return 0;  // Base case: processed all prices, return 0
    minPrice = min(minPrice, prices[index]);  // Update minimum price if current price is lower
    return max(maxProfit(prices, index + 1, minPrice), prices[index] - minPrice);  // Return max of future profit or profit from selling today
}

// 12) Perfect square - Check if a number is a perfect square using linear search
bool isPerfectSquare(int num, int i = 1) {  // Function with target number and current candidate (starting from 1)
    if(i * i == num) return true;  // Base case: found exact square root, number is perfect square
    if(i * i > num) return false;  // Base case: exceeded target, number is not perfect square
    return isPerfectSquare(num, i + 1);  // Recursive call: try next candidate number
}

// 13) Ticket cost - Find minimum cost to travel on given days with different ticket options
int minCostTickets(vector<int>& days, vector<int>& costs, int index = 0, unordered_map<int, int> memo = {}) {  // Function with travel days, ticket costs, current index, and memoization map
    if(index >= days.size()) return 0;  // Base case: no more travel days, cost is 0
    if(memo.count(index)) return memo[index];  // If result already computed, return memoized value
    int option1 = costs[0] + minCostTickets(days, costs, index + 1);  // Option 1: buy 1-day ticket and move to next day
    int i = index;  // Initialize pointer for finding days within 7-day window
    while(i < days.size() && days[i] < days[index] + 7) i++;  // Find first day outside 7-day ticket coverage
    int option2 = costs[1] + minCostTickets(days, costs, i);  // Option 2: buy 7-day ticket and skip covered days
    while(i < days.size() && days[i] < days[index] + 30) i++;  // Find first day outside 30-day ticket coverage
    int option3 = costs[2] + minCostTickets(days, costs, i);  // Option 3: buy 30-day ticket and skip covered days
    memo[index] = min({option1, option2, option3});  // Store minimum cost among all options in memo
    return memo[index];  // Return the computed minimum cost
}

// 14) Dice rolls - Count ways to achieve target sum with given number of dice
int numRollsToTarget(int d, int f, int target) {  // Function with number of dice, faces per die, and target sum
    if(target < 0) return 0;  // Base case: negative target is impossible, return 0 ways
    if(d == 0) return target == 0;  // Base case: no dice left, check if target is exactly 0
    int ways = 0;  // Initialize counter for number of ways to achieve target
    for(int i = 1; i <= f; i++) {  // Try each possible face value on current die
        ways += numRollsToTarget(d - 1, f, target - i);  // Add ways from remaining dice with reduced target
    }
    return ways;  // Return total number of ways to achieve target sum
}

// 15) Inversion Count - Count number of inversions using merge sort approach
long long merge(vector<int>& arr, int left, int mid, int right) {  // Merge function that counts inversions while merging two sorted halves
    vector<int> temp(right - left + 1);  // Create temporary array to store merged result
    int i = left, j = mid + 1, k = 0;  // Initialize pointers for left half, right half, and temp array
    long long invCount = 0;  // Initialize inversion counter to track number of inversions found
    
    while(i <= mid && j <= right) {  // Process elements while both halves have remaining elements
        if(arr[i] <= arr[j]) {  // If left element is smaller or equal, no inversion
            temp[k++] = arr[i++];  // Copy left element to temp array and advance left pointer
        } else {  // If right element is smaller, we have inversions
            temp[k++] = arr[j++];  // Copy right element to temp array and advance right pointer
            invCount += (mid - i + 1);  // Add number of remaining elements in left half as inversions
        }
    }
    
    while(i <= mid) temp[k++] = arr[i++];  // Copy remaining elements from left half if any
    while(j <= right) temp[k++] = arr[j++];  // Copy remaining elements from right half if any
    
    for(int i = left; i <= right; i++) {  // Copy merged result back to original array
        arr[i] = temp[i - left];  // Update original array with sorted and merged elements
    }
    
    return invCount;  // Return total number of inversions found during merge process
}

long long mergeSort(vector<int>& arr, int left, int right) {  // Recursive merge sort function that returns inversion count
    long long invCount = 0;  // Initialize inversion counter for current recursive call
    if(left < right) {  // Base case: continue only if there are at least 2 elements
        int mid = left + (right - left) / 2;  // Calculate middle point to divide array into two halves
        invCount += mergeSort(arr, left, mid);  // Recursively sort left half and add its inversion count
        invCount += mergeSort(arr, mid + 1, right);  // Recursively sort right half and add its inversion count
        invCount += merge(arr, left, mid, right);  // Merge both halves and add inversions found during merge
    }
    return invCount;  // Return total inversion count from current subarray
}

long long getInversionCount(vector<int> arr) {  // Wrapper function to find inversion count in array
    return mergeSort(arr, 0, arr.size() - 1);  // Call merge sort on entire array and return inversion count
}


int main() {  // Main function - entry point of the program
    // Test cases for the written functions
    cout << "Last Occurrence of 'a' in 'banana': " << lastOccurrence("banana", 'a', 5) << endl;  // Test last occurrence function with string "banana" and character 'a'
    cout << "Reverse of 'hello': " << reverseString("hello") << endl;  // Test string reversal function with "hello"
    cout << "Sum of '123' and '456': " << addStrings("123", "456") << endl;  // Test string addition function with two number strings
    cout << "Is 'racecar' a palindrome?: " << isPalindrome("racecar") << endl;  // Test palindrome check with classic palindrome "racecar"
    
    vector<int> arr = {1, 2, 3};  // Create test array with three elements for subarray demonstration
    cout << "Subarrays of {1, 2, 3}:" << endl;  // Print header for subarray output
    printSubarrays(arr, 0, 0);  // Call subarray printing function starting from index 0
    
    cout << "Remove 'a' from 'banana': " << removeCharacter("banana", 'a') << endl;  // Test character removal function
    cout << "123 in words: " << digitToWords(123) << endl;  // Test number to words conversion function
    cout << "Number of 1s in 10101: " << countOnes(10101) << endl;  // Test digit counting function with binary-like number
    cout << "Does 'abc' match pattern 'a?c'?: " << isMatch("abc", "a?c") << endl;  // Test wildcard pattern matching function
    
    vector<int> houses = {2, 7, 9, 3, 1};  // Create array representing money in each house
    cout << "Max robbery amount: " << robHouses(houses) << endl;  // Test house robbery optimization function
    
    vector<int> prices = {7, 1, 5, 3, 6, 4};  // Create array of stock prices over time
    cout << "Maximum profit from stock: " << maxProfit(prices) << endl;  // Test stock profit maximization function
    
    cout << "Is 16 a perfect square?: " << (isPerfectSquare(16) ? "Yes" : "No") << endl;  // Test perfect square check with 16 (4²)
    
    vector<int> days = {1, 4, 6, 7, 8, 20};  // Create array of travel days
    vector<int> costs = {2, 7, 15};  // Create array of ticket costs (1-day, 7-day, 30-day)
    cout << "Minimum cost for tickets: " << minCostTickets(days, costs) << endl;  // Test minimum ticket cost calculation
    
    cout << "Number of ways to roll 2 dice to sum 7: " << numRollsToTarget(2, 6, 7) << endl;  // Test dice roll combinations for target sum
    
    vector<int> inversionArray = {8, 4, 2, 1};  // Create test array with inversions for inversion count testing
    cout << "Inversion count in {8, 4, 2, 1}: " << getInversionCount(inversionArray) << endl;  // Test inversion count function with array containing multiple inversions

    return 0;  // Return 0 to indicate successful program execution
}

