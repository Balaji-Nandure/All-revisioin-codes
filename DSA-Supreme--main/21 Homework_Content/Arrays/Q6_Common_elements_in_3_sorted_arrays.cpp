// https://practice.geeksforgeeks.org/problems/common-elements1132/1

/*
Approach Used: 3 Pointer Approach
---------------------------------
- Since all three arrays are sorted, we can use three pointers (i, j, k) to traverse each array.
- At each step, compare the elements at the current pointers:
    - If all three are equal, it's a common element. Add to result and move all pointers forward.
    - If not, increment the pointer(s) pointing to the smallest value(s) to catch up.
- To avoid duplicates in the result, we skip over duplicate values in each array after processing a common element.
- This approach works in O(n1 + n2 + n3) time and O(1) extra space (excluding output).

Alternative Approaches (with code in comments):
-----------------------------------------------
1. Using Hash Maps/Sets:
   - Store all elements of first array in a set.
   - For second array, store elements present in set1 in set2.
   - For third array, check if element is in set2 and add to result.
   - Time: O(n1 + n2 + n3), Space: O(n1 + n2)
   - Not optimal for sorted arrays.

2. Using STL set_intersection (C++ STL):
   - Use std::set_intersection twice to get common elements.
   - Time: O(n1 + n2 + n3), Space: O(n1 + n2 + n3)
   - Example:
     // vector<int> temp;
     // set_intersection(A, A+n1, B, B+n2, back_inserter(temp));
     // vector<int> ans;
     // set_intersection(temp.begin(), temp.end(), C, C+n3, back_inserter(ans));

Below is the improved code with detailed comments and duplicate skipping for better performance.
*/

class Solution
{
    public:    
       vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
        {
            vector<int> ans; // To store the final answer
            int i = 0, j = 0, k = 0; // Pointers for A, B, C

            while(i < n1 && j < n2 && k < n3) {
                // If all three elements are equal, it's a common element
                if(A[i] == B[j] && B[j] == C[k]) {
                    // To avoid duplicates in the answer
                    if(ans.empty() || ans.back() != A[i]) {
                        ans.push_back(A[i]);
                    }
                    int val = A[i];
                    // Skip duplicates in A
                    while(i < n1 && A[i] == val) i++;
                    // Skip duplicates in B
                    while(j < n2 && B[j] == val) j++;
                    // Skip duplicates in C
                    while(k < n3 && C[k] == val) k++;
                }
                // If not equal, move the pointer(s) with the smallest value(s)
                else {
                    int minVal = min({A[i], B[j], C[k]});
                    // Move i if A[i] is the smallest
                    while(i < n1 && A[i] == minVal) i++;
                    // Move j if B[j] is the smallest
                    while(j < n2 && B[j] == minVal) j++;
                    // Move k if C[k] is the smallest
                    while(k < n3 && C[k] == minVal) k++;
                }
            }
            return ans;
        }
};

/*
Dry Run Example:
----------------
A = [1, 5, 10, 20, 40, 80]
B = [6, 7, 20, 80, 100]
C = [3, 4, 15, 20, 30, 70, 80, 120]

i=0, j=0, k=0: A[0]=1, B[0]=6, C[0]=3 -> min=1, move i
i=1, j=0, k=0: A[1]=5, B[0]=6, C[0]=3 -> min=3, move k
i=1, j=0, k=1: A[1]=5, B[0]=6, C[1]=4 -> min=4, move k
i=1, j=0, k=2: A[1]=5, B[0]=6, C[2]=15 -> min=5, move i
i=2, j=0, k=2: A[2]=10, B[0]=6, C[2]=15 -> min=6, move j
i=2, j=1, k=2: A[2]=10, B[1]=7, C[2]=15 -> min=7, move j
i=2, j=2, k=2: A[2]=10, B[2]=20, C[2]=15 -> min=10, move i
i=3, j=2, k=2: A[3]=20, B[2]=20, C[2]=15 -> min=15, move k
i=3, j=2, k=3: A[3]=20, B[2]=20, C[3]=20 -> all equal, add 20, skip duplicates
i=4, j=3, k=4: A[4]=40, B[3]=80, C[4]=30 -> min=30, move k
i=4, j=3, k=5: A[4]=40, B[3]=80, C[5]=70 -> min=40, move i
i=5, j=3, k=5: A[5]=80, B[3]=80, C[5]=70 -> min=70, move k
i=5, j=3, k=6: A[5]=80, B[3]=80, C[6]=80 -> all equal, add 80, skip duplicates
i=6, j=4, k=7: i>=n1, loop ends

Output: [20, 80]
*/