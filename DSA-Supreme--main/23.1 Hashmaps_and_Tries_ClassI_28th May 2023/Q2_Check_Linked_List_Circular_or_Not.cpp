#include<iostream>
#include<unordered_map>
using namespace std;

/*
Approach Used:
---------------
We need to check if a singly linked list is circular (i.e., the last node points back to the head or any previous node, forming a loop).
The current approach uses a hash map to keep track of visited nodes. If we encounter a node that we've already visited, the list is circular.

Improvements:
-------------
- The original code had logical errors and typos (e.g., 'visted' instead of 'visited', and the logic for checking/marking visited nodes was inverted).
- We should mark a node as visited when we first see it, and if we see it again, return true (circular).
- If we reach NULL, the list is not circular.
- Also, we should handle the case when the list is empty (head == NULL).

Alternative (Better) Approach:
------------------------------
- Use Floyd's Cycle Detection Algorithm (Tortoise and Hare), which uses O(1) space and is more efficient.
- See the commented code below for this approach.

Dry Run:
--------
Suppose the list is: 1 -> 2 -> 3 -> 4 -> 2 (cycle at node with value 2)
- temp = 1: not visited, mark as visited
- temp = 2: not visited, mark as visited
- temp = 3: not visited, mark as visited
- temp = 4: not visited, mark as visited
- temp = 2: already visited, return true (circular)

Suppose the list is: 1 -> 2 -> 3 -> 4 -> NULL (no cycle)
- temp = 1: not visited, mark as visited
- temp = 2: not visited, mark as visited
- temp = 3: not visited, mark as visited
- temp = 4: not visited, mark as visited
- temp = NULL: exit loop, return false (not circular)
*/

// Definition for singly-linked list node
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(NULL) {}
};

// Function to check if the linked list is circular using hashing
bool checkCircular(Node* head){
    // Hash map to store visited nodes
    unordered_map<Node*, bool> visited;
    Node* temp = head;

    // Traverse the linked list
    while(temp != NULL){
        // If current node is already visited, cycle detected
        if(visited.find(temp) != visited.end()){
            return true; // List is circular
        }
        // Mark current node as visited
        visited[temp] = true;
        // Move to next node
        temp = temp->next;
    }
    // If we reach here, no cycle found
    return false; // List is not circular
}

/*
Alternative Efficient Approach: Floyd's Cycle Detection (Tortoise and Hare)
----------------------------------------------------------------------------
This approach uses two pointers moving at different speeds. If there is a cycle, they will meet.

bool checkCircularFloyd(Node* head) {
    if (!head) return false; // Empty list is not circular
    Node* slow = head;
    Node* fast = head;
    while (fast && fast->next) {
        slow = slow->next;           // Move slow by 1
        fast = fast->next->next;     // Move fast by 2
        if (slow == fast) return true; // Cycle detected
    }
    return false; // No cycle
}
*/

int main(){
    // Example usage:
    // Node* head = new Node(1);
    // head->next = new Node(2);
    // head->next->next = new Node(3);
    // head->next->next->next = head; // Creates a cycle
    // cout << (checkCircular(head) ? "Circular" : "Not Circular") << endl;

    return 0;
}

/*
Dry Run Example:
----------------
List: 1 -> 2 -> 3 -> 4 -> 2 (cycle at node 2)
Step 1: temp = 1, not visited, mark as visited
Step 2: temp = 2, not visited, mark as visited
Step 3: temp = 3, not visited, mark as visited
Step 4: temp = 4, not visited, mark as visited
Step 5: temp = 2, already visited, return true

List: 1 -> 2 -> 3 -> 4 -> NULL (no cycle)
Step 1: temp = 1, not visited, mark as visited
Step 2: temp = 2, not visited, mark as visited
Step 3: temp = 3, not visited, mark as visited
Step 4: temp = 4, not visited, mark as visited
Step 5: temp = NULL, exit loop, return false
*/