/*
    Approach Used:
    --------------
    This code finds the starting point of a loop (cycle) in a singly linked list using Floyd's Cycle Detection Algorithm (Tortoise and Hare approach).

    Steps:
    1. Detect if a loop exists using two pointers (slow and fast).
    2. If a loop is found, move one pointer to the head and keep the other at the meeting point.
    3. Move both pointers one step at a time; the point where they meet is the starting node of the loop.

    Why this works:
    - When slow and fast meet inside the loop, the distance from head to loop start equals the distance from meeting point to loop start (inside the loop).
    - Moving both pointers at the same speed from head and meeting point will make them meet at the loop's starting node.

    

    ------------------------------------------------
    Dry Run:
    --------
    Example: 10->20->30->40->50->60->70->80->90
                              ^                   |
                              |-------------------|
    - slow and fast start at 10.
    - They meet at node 70 (inside the loop).
    - Move slow to head (10), keep fast at 70.
    - Move both one step at a time: 10->20->30->40->50, 70->80->90->50.
    - They meet at node 50, which is the starting point of the loop.

*/

#include<iostream>
using namespace std;

// Node class for singly linked list
class Node{
    public:
        int data;      // Stores the value of the node
        Node* next;    // Pointer to the next node

        // Constructor to initialize node with data and next as NULL
        Node(int data){
            this->data = data;
            this->next = NULL;
        }
};

// Function to find the starting point of the loop in the linked list
Node* findStart(Node* head){
    if(head == NULL) return NULL; // Empty list, no loop

    Node* slow = head; // Slow pointer starts at head
    Node* fast = head; // Fast pointer starts at head

    // Step 1: Detect if a loop exists using Floyd's Cycle Detection
    bool isLoop = false;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;           // Move slow by 1
        fast = fast->next->next;     // Move fast by 2

        if(slow == fast){            // Loop detected
            isLoop = true;
            break;
        }
    }

    if(!isLoop) return NULL; // No loop found

    // Step 2: Find the starting node of the loop
    slow = head; // Move slow to head
    // Both pointers move one step at a time; they meet at loop start
    while(slow != fast){
        slow = slow->next;
        fast = fast->next;
    }
    return slow; // Starting node of the loop
}

// Utility function to print the linked list (prints up to n nodes to avoid infinite loop)
void print(Node* head, int n = 20){
    Node* temp = head;
    int count = 0;
    while(temp != NULL && count < n){
        cout << temp->data << " ";
        temp = temp->next;
        count++;
    }
    if(count == n) cout << "... (possible loop detected)";
    cout << endl;
}

int main(){
    // Creating nodes
    Node* head = new Node(10);
    Node* first = new Node(20);
    Node* second = new Node(30);
    Node* third = new Node(40);
    Node* fourth = new Node(50);
    Node* fifth = new Node(60);
    Node* sixth = new Node(70);
    Node* seventh = new Node(80);
    Node* eighth = new Node(90);

    // Linking nodes to form the list
    head->next = first;
    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = seventh;
    seventh->next = eighth;
    eighth->next = fourth; // Creating a loop: 90->50

    // Find the starting point of the loop
    Node* starting = findStart(head);

    if(starting != NULL)
        cout << "Starting point of loop is: " << starting->data << endl;
    else
        cout << "No loop detected in the linked list." << endl;

    // Uncomment below to print the list (will print up to 20 nodes to avoid infinite loop)
    // print(head);

    return 0;
}

/*
Dry Run Example:
----------------
List: 10->20->30->40->50->60->70->80->90
                          ^             |
                          |-------------|
Step 1: slow and fast start at 10.
Step 2: Move slow by 1, fast by 2:
    slow=20, fast=30
    slow=30, fast=50
    slow=40, fast=70
    slow=50, fast=90
    slow=60, fast=60 (meet)
Step 3: Move slow to head (10), keep fast at meeting point (60).
    Move both by 1:
    slow=10, fast=60
    slow=20, fast=70
    slow=30, fast=80
    slow=40, fast=90
    slow=50, fast=50 (meet)
So, starting point of loop is 50.
*/