/*
Approach Used:
---------------
We are given an array and need to find the first repeating element (the element that appears more than once and whose first occurrence is earliest). 
The current approach uses a counting array to store the frequency of each element, then traverses the array to find the first element with count >= 2.

Improvements:
-------------
- The current code assumes all elements are non-negative and less than 1,000,000. This is not always safe.
- We can use an unordered_map to handle negative numbers and large values efficiently.
- We can also optimize to find the first repeating element in a single pass using a set.

Alternative Approaches (with code) are provided at the end as comments.

*/

// Include necessary headers
#include<iostream>
#include<vector>
#include<unordered_map> // For better alternative
#include<unordered_set> // For optimal approach
using namespace std;

// Function to find the first repeating element in the array
int findRepeatingElement(const vector<int>& arr){
    // Using unordered_map to store the count of each element (handles negatives and large values)
    unordered_map<int, int> countMap; // key: element, value: count

    // Count the frequency of each element
    for(int num : arr){
        countMap[num]++; // Increment count for each element
    }

    // Traverse the array to find the first element with count >= 2
    for(int num : arr){
        if(countMap[num] >= 2){ // If element repeats
            return num; // Return the first repeating element
        }
    }
    return -1; // If no repeating element exists
}

int main(){
    // Example input array
    vector<int> arr{1,5,3,4,3,5,6};

    // Call the function to find the first repeating element
    int ans = findRepeatingElement(arr);

    // Output the result
    cout<<ans;
    return 0;
}