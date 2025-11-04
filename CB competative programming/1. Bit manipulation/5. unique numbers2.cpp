/*
Question:
We are given an array containing n numbers. All the numbers are present twice except for two numbers 
which are present only once. Find the unique numbers in linear time without using any extra space. 
(Hint - Use Bitwise)

Approach:
1. If all elements except two occur twice, XOR of all elements gives xor = A ^ B (where A and B are the two unique numbers).
2. Find any set bit in xor (rightmost set bit can be found using xor & -xor).
3. Partition numbers into two groups:
    - One group with this set bit as 1.
    - Other group with this bit as 0.
   All duplicate numbers will pair up in their respective groups and cancel out, leaving one unique number in each group.
4. XOR numbers in each group to get the two unique numbers.

Code:
*/

#include <iostream>
#include <vector>
using namespace std;

void findUniqueNumbers(const vector<int>& nums) {
    int xor_all = 0;
    for(int num : nums) {
        xor_all ^= num;
    }
    // Get the rightmost set bit (a bit where the two numbers differ)
    // e.g xor_all = 1010, then set_bit = 0010
    // -xor_all = 0110
    // xor_all & -xor_all = 0010
    int set_bit = xor_all & -xor_all;
    // note: x & -x will give the rightmost set bit of x

    int unique1 = 0, unique2 = 0;
    for(int num : nums) {
        if(num & set_bit)
            unique1 ^= num;
        else
            unique2 ^= num;
    }

    cout << "The two unique numbers are: " << unique1 << " and " << unique2 << endl;
}

int main() {
    vector<int> arr = {2, 4, 7, 9, 2, 4};
    // In this example, 7 and 9 are unique.
    findUniqueNumbers(arr);
    return 0;
}
