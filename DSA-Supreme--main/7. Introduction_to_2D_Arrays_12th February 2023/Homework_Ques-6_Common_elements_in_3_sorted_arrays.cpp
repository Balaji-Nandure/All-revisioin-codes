/*
Approach Used:
---------------
- The code finds common elements in three sorted arrays.
- It uses three pointers (i, j, k) to traverse the arrays simultaneously.
- If the current elements of all three arrays are equal, it adds the element to a set (to ensure uniqueness).
- If not, it increments the pointer(s) of the array(s) with the smallest value, thus moving towards a possible match.
- Finally, it prints all unique common elements.

Time Complexity: O(n1 + n2 + n3) where n1, n2, n3 are the sizes of the three arrays.
Space Complexity: O(x) where x is the number of common elements (for the set).

Better Alternatives:
--------------------
1. If duplicate elements are not present in the arrays, we can avoid using a set and directly print/store the result.
2. If arrays can have duplicates and we want to print each common element only once, we can skip duplicates while traversing.
3. If arrays are not sorted, we can use hash maps to store frequencies and find common elements, but that would increase space complexity.

Alternative Approach (with skipping duplicates, no set needed):
---------------------------------------------------------------
/*
void commonElements(vector<int>&A,vector<int>&B,vector<int>&C){
    int n1 = A.size(), n2 = B.size(), n3 = C.size();
    int i = 0, j = 0, k = 0;
    vector<int> ans;
    while(i < n1 && j < n2 && k < n3){
        if(A[i] == B[j] && B[j] == C[k]){
            ans.push_back(A[i]);
            int val = A[i];
            while(i < n1 && A[i] == val) i++;
            while(j < n2 && B[j] == val) j++;
            while(k < n3 && C[k] == val) k++;
        }
        else{
            int mn = min({A[i], B[j], C[k]});
            if(A[i] == mn) i++;
            if(B[j] == mn) j++;
            if(C[k] == mn) k++;
        }
    }
    for(int x : ans) cout << x << " ";
}
*/

#include<iostream>
#include<vector>
#include<set>
using namespace std;

// Function to find and print common elements in three sorted arrays
void commonElements(vector<int>&A,vector<int>&B,vector<int>&C){
    int n1 = A.size(); // Size of first array
    int n2 = B.size(); // Size of second array
    int n3 = C.size(); // Size of third array

    set<int>st; // To store unique common elements

    int i = 0, j = 0, k = 0; // Pointers for A, B, C

    // Traverse all arrays until any one is exhausted
    while(i < n1 && j < n2 && k < n3){
        // If current elements are equal in all arrays
        if(A[i] == B[j] && B[j] == C[k]){
            st.insert(A[i]); // Insert into set to ensure uniqueness
            i++; j++; k++;   // Move all pointers forward
        }
        // If A[i] is smallest, move i forward
        else if(A[i] < B[j]){
            i++;
        }
        // If B[j] is smallest, move j forward
        else if(B[j] < C[k]){
            j++;
        }
        // Else, C[k] is smallest, move k forward
        else{
            k++;
        }
    }

    // Print all unique common elements
    for(auto val : st){
        cout << val << " ";
    }
    cout << endl;
}

/*
Dry Run:
--------
A = [1, 5, 10, 20, 40, 80]
B = [6, 7, 20, 80, 100]
C = [3, 4, 15, 20, 30, 70, 80, 120]

Step-by-step:
i=0,j=0,k=0: A[0]=1, B[0]=6, C[0]=3 -> 1<6, i++
i=1,j=0,k=0: A[1]=5, B[0]=6, C[0]=3 -> 5<6, i++
i=2,j=0,k=0: A[2]=10, B[0]=6, C[0]=3 -> 6<10, j++
i=2,j=1,k=0: A[2]=10, B[1]=7, C[0]=3 -> 7<10, j++
i=2,j=2,k=0: A[2]=10, B[2]=20, C[0]=3 -> 10<20, i++
i=3,j=2,k=0: A[3]=20, B[2]=20, C[0]=3 -> 3<20, k++
i=3,j=2,k=1: A[3]=20, B[2]=20, C[1]=4 -> 4<20, k++
i=3,j=2,k=2: A[3]=20, B[2]=20, C[2]=15 -> 15<20, k++
i=3,j=2,k=3: A[3]=20, B[2]=20, C[3]=20 -> All equal, insert 20, i++,j++,k++
i=4,j=3,k=4: A[4]=40, B[3]=80, C[4]=30 -> 30<40, k++
i=4,j=3,k=5: A[4]=40, B[3]=80, C[5]=70 -> 40<80, i++
i=5,j=3,k=5: A[5]=80, B[3]=80, C[5]=70 -> 70<80, k++
i=5,j=3,k=6: A[5]=80, B[3]=80, C[6]=80 -> All equal, insert 80, i++,j++,k++
i=6,j=4,k=7: i==n1, loop ends

Output: 20 80
*/

int main(){
    vector<int>A{1, 5, 10, 20, 40, 80}; // First sorted array
    vector<int>B{6, 7, 20, 80, 100};    // Second sorted array
    vector<int>C{3, 4, 15, 20, 30, 70, 80, 120}; // Third sorted array

    commonElements(A,B,C); // Find and print common elements

    return 0;
}