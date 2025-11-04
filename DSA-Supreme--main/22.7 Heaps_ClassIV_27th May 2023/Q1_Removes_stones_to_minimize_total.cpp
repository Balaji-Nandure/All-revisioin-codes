// https://leetcode.com/problems/remove-stones-to-minimize-the-total/description/

/*
Approach Used:
---------------
- We use a max heap (priority_queue in C++) to always access the largest pile efficiently.
- For k operations, we repeatedly remove the largest pile, reduce it by floor(pile/2), and push it back.
- After k operations, we sum all remaining stones in the heap for the answer.

Why Max Heap?
-------------
- We always want to remove the most stones in each operation, so we always pick the largest pile.

Time Complexity:
----------------
- Building the heap: O(n)
- Each operation: O(log n) for pop and push, repeated k times => O(k log n)
- Summing up: O(n log n) (since each pop is O(log n), but can be considered O(n) for small n)

Possible Better Alternatives:
-----------------------------
- If k is very large compared to n, we can optimize by using a frequency map or bucket sort for very large piles, but for constraints in Leetcode, the heap approach is optimal and simple.
- If k >= total number of stones, we can directly return 0.

Alternative Approach (using multiset for custom heap):
------------------------------------------------------
/*
#include <set>
int minStoneSum(vector<int>& piles, int k) {
    multiset<int> ms(piles.begin(), piles.end(), greater<int>());
    while (k--) {
        int top = *ms.begin();
        ms.erase(ms.begin());
        top -= top/2;
        ms.insert(top);
    }
    int sum = 0;
    for (int x : ms) sum += x;
    return sum;
}
*/

Dry Run Example:
----------------
Input: piles = [5,4,9], k = 2

Step 1: Build maxHeap: [9,5,4]
Operation 1: Pop 9, reduce to 5 (9-4), push 5. Heap: [5,5,4]
Operation 2: Pop 5, reduce to 3 (5-2), push 3. Heap: [5,4,3]
Sum: 5+4+3 = 12

*/

class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        // Max heap to always get the largest pile efficiently
        priority_queue<int> maxHeap;

        // Push all pile sizes into the max heap
        for(int i = 0; i < piles.size(); i++){
            maxHeap.push(piles[i]); // O(n) for all pushes
        }

        // Perform k operations
        while(k--){
            int topElement = maxHeap.top(); // Get the largest pile
            maxHeap.pop();                  // Remove it from heap

            // Reduce the pile by floor(topElement/2)
            int reduced = topElement - topElement/2;

            maxHeap.push(reduced);          // Push the reduced pile back
        }

        // Sum up all remaining stones in the heap
        int sum = 0;
        while(!maxHeap.empty()){
            sum += maxHeap.top(); // Add the top element to sum
            maxHeap.pop();        // Remove the element
        }
        return sum; // Return the minimized total
    }
};

/*
Dry Run:
--------
Input: piles = [5,4,9], k = 2

Initial maxHeap: [9,5,4]
1st operation: pop 9, reduce to 5, push 5 => [5,5,4]
2nd operation: pop 5, reduce to 3, push 3 => [5,4,3]
Sum: 5+4+3 = 12

Output: 12
*/