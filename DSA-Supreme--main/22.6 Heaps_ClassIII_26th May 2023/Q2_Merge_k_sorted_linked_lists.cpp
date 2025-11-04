/*
================================================================================
Approach Used: Merge K Sorted Linked Lists using Min Heap (Priority Queue)
================================================================================
- We are given k sorted linked lists.
- The goal is to merge all these lists into a single sorted linked list efficiently.

Logic:
------
- Use a min heap (priority_queue with custom comparator) to always extract the node with the minimum value among the current heads of all lists.
- Each heap node stores a pointer to a ListNode.
- Initially, push the head of each non-empty list into the min heap.
- Repeatedly extract the smallest node from the heap, add it to the result list, and if the extracted node has a next node, push that next node into the heap.
- Continue until the heap is empty.

Time Complexity: O(N log k), where N is the total number of nodes and k is the number of lists.
Space Complexity: O(k) for the heap.

================================================================================
Better Alternatives:
================================================================================
1. **Divide and Conquer (Pairwise Merge):**
   - Merge lists in pairs (like merge sort), reducing the number of lists by half each time.
   - Time Complexity: O(N log k)
   - Space Complexity: O(1) (if merging in-place)
   - Code:
     ```
     ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
         ListNode dummy(0), *tail = &dummy;
         while (l1 && l2) {
             if (l1->val < l2->val) { tail->next = l1; l1 = l1->next; }
             else { tail->next = l2; l2 = l2->next; }
             tail = tail->next;
         }
         tail->next = l1 ? l1 : l2;
         return dummy.next;
     }
     ListNode* mergeKLists(vector<ListNode*>& lists) {
         if (lists.empty()) return nullptr;
         int n = lists.size();
         while (n > 1) {
             for (int i = 0; i < n/2; ++i)
                 lists[i] = mergeTwoLists(lists[i], lists[n-i-1]);
             n = (n+1)/2;
         }
         return lists[0];
     }
     ```
2. **Brute Force:**
   - Collect all nodes, sort them, and relink.
   - Time: O(N log N), Space: O(N)

================================================================================
Dry Run Example
================================================================================
Suppose k = 3, lists:
L1: 1 -> 4 -> 5
L2: 1 -> 3 -> 4
L3: 2 -> 6

Heap after initialization: [1(L1), 1(L2), 2(L3)]
Pop 1(L1), push 4(L1): [1(L2), 2(L3), 4(L1)]
Pop 1(L2), push 3(L2): [2(L3), 3(L2), 4(L1)]
Pop 2(L3), push 6(L3): [3(L2), 4(L1), 6(L3)]
Pop 3(L2), push 4(L2): [4(L1), 4(L2), 6(L3)]
Pop 4(L1), push 5(L1): [4(L2), 5(L1), 6(L3)]
Pop 4(L2): [5(L1), 6(L3)]
Pop 5(L1): [6(L3)]
Pop 6(L3): []

Result: 1->1->2->3->4->4->5->6

================================================================================
Implementation with Detailed Comments
================================================================================
*/

// https://leetcode.com/problems/merge-k-sorted-lists/

// Custom comparator for min heap: returns true if a's value is greater than b's value
class compare {
public:
    bool operator()(ListNode* a, ListNode* b) {
        // Min heap: node with smaller value has higher priority
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // Min heap to store the current head node of each list
        priority_queue<ListNode*, vector<ListNode*>, compare> minHeap;

        int k = lists.size(); // Number of linked lists

        // Edge case: if no lists, return NULL
        if (k == 0)
            return NULL;

        // Push the head of each non-empty list into the min heap
        for (int i = 0; i < k; i++) {
            if (lists[i] != NULL) {
                minHeap.push(lists[i]);
            }
        }

        // Dummy node to simplify result list construction
        ListNode dummy(0);
        ListNode* tail = &dummy; // Tail pointer for result list

        // While there are nodes in the heap
        while (!minHeap.empty()) {
            // Extract the node with the smallest value
            ListNode* temp = minHeap.top();
            minHeap.pop();

            // Append this node to the result list
            tail->next = temp;
            tail = temp;

            // If the extracted node has a next node, push it into the heap
            if (temp->next != NULL) {
                minHeap.push(temp->next);
            }
        }

        // Return the merged list (skipping dummy node)
        return dummy.next;
    }
};

/*
================================================================================
Dry Run (Step by Step)
================================================================================
Input:
lists = [
  1 -> 4 -> 5,
  1 -> 3 -> 4,
  2 -> 6
]

Heap after initialization: [1(L1), 1(L2), 2(L3)]
Result list: (empty)

1. Pop 1(L1), push 4(L1): Heap=[1(L2),2(L3),4(L1)], Result=1
2. Pop 1(L2), push 3(L2): Heap=[2(L3),3(L2),4(L1)], Result=1->1
3. Pop 2(L3), push 6(L3): Heap=[3(L2),4(L1),6(L3)], Result=1->1->2
4. Pop 3(L2), push 4(L2): Heap=[4(L1),4(L2),6(L3)], Result=1->1->2->3
5. Pop 4(L1), push 5(L1): Heap=[4(L2),5(L1),6(L3)], Result=1->1->2->3->4
6. Pop 4(L2): Heap=[5(L1),6(L3)], Result=1->1->2->3->4->4
7. Pop 5(L1): Heap=[6(L3)], Result=1->1->2->3->4->4->5
8. Pop 6(L3): Heap=[], Result=1->1->2->3->4->4->5->6

Final Output: 1->1->2->3->4->4->5->6
================================================================================
*/