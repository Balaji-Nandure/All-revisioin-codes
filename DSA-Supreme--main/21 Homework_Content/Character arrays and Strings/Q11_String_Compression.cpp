class Solution { // Solution class for string compression // main logic container
    public:
        int compress(vector<char>& chars) { // compresses chars in-place // returns new length
            int n = chars.size(); // get size of input vector // used for loop bounds
            int write = 0; // index to write compressed chars // tracks output position
            for(int i=0; i<n; ){ // iterate through chars // i is current read position
                int curr = chars[i]; // store current character // will check for repeats
                int j = i; // start j at i // j will find end of group
                // count how many times curr repeats
                while(j<n && chars[j] == curr){ // while same char and in bounds // count group length
                    j++; // move to next char // increment j for each repeat
                }
                int count = j - i; // number of times curr repeats // group size
                chars[write] = curr; // write current char to output // place at write index
                write++; // move write pointer forward // next output position
                if(count > 1){ // if group has more than 1 char // need to write count
                    string num = to_string(count); // convert count to string // for multi-digit counts
                    for(char c: num){ // iterate over each digit // write each digit separately
                        chars[write] = c; // write digit to output // place at write index
                        write++; // move write pointer forward // next output position
                    }
                }
                i = j; // move i to next new char // skip processed group
            }
            return write; // return new length of compressed array // final answer
        }
    };

    /*
    Approach:
    ---------
    The function compresses a vector of characters in-place using the following logic:
    - Iterate through the input vector, grouping consecutive repeating characters.
    - For each group:
        - Write the character once to the output position.
        - If the group size is greater than 1, write the count (as individual digits) after the character.
    - Continue this process for all groups, updating the write pointer as you go.
    - Return the new length of the compressed array.

    Key Points:
    - The function uses two pointers: 
        - `i` to read through the input,
        - `write` to write the compressed output.
    - For each group of the same character, the count is calculated as `j - i` (where `j` is the first index after the group).
    - The count is converted to a string and each digit is written separately.
    - The function modifies the input vector in-place and returns the new length.

    Time Complexity: O(N), where N is the length of the input vector (each character is read and written at most once).
    Space Complexity: O(1) extra (in-place, except for temporary string for count).

    Dry Run:
    --------
    Example 1:
    Input: chars = ['a','a','b','b','c','c','c']
    Steps:
    - i=0: curr='a', j=2 (chars[0] and chars[1] are 'a'), count=2
      - Write 'a' at write=0, then '2' at write=1
      - write=2, i=2
    - i=2: curr='b', j=4 (chars[2] and chars[3] are 'b'), count=2
      - Write 'b' at write=2, then '2' at write=3
      - write=4, i=4
    - i=4: curr='c', j=7 (chars[4], chars[5], chars[6] are 'c'), count=3
      - Write 'c' at write=4, then '3' at write=5
      - write=6, i=7 (end)
    Output: chars = ['a','2','b','2','c','3'], return 6

    Example 2:
    Input: chars = ['a']
    Steps:
    - i=0: curr='a', j=1, count=1
      - Write 'a' at write=0
      - write=1, i=1 (end)
    Output: chars = ['a'], return 1

    Example 3:
    Input: chars = ['a','b','b','b','b','b','b','b','b','b','b','b','b']
    Steps:
    - i=0: curr='a', j=1, count=1
      - Write 'a' at write=0
      - write=1, i=1
    - i=1: curr='b', j=13, count=12
      - Write 'b' at write=1, then '1' at write=2, '2' at write=3
      - write=4, i=13 (end)
    Output: chars = ['a','b','1','2'], return 4
    */