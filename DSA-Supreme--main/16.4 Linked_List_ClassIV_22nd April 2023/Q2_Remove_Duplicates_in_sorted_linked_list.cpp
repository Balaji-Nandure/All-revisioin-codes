/*
================================================================================
Approach Used: (Optimal for Sorted Linked List)
================================================================================
- Since the linked list is sorted, all duplicates will be adjacent.
- Traverse the list with a pointer (curr).
- If curr->data == curr->next->data, remove curr->next node (duplicate).
- Else, move curr forward.
- Continue until end of list.

Time Complexity: O(N)
Space Complexity: O(1)
================================================================================
Dry Run:
================================================================================
Input: 1 -> 2 -> 2 -> 3 -> 4 -> 4
Step 1: curr=1, 1!=2, move curr
Step 2: curr=2, 2==2, remove duplicate (second 2)
List: 1->2->3->4->4
Step 3: curr=2, 2!=3, move curr
Step 4: curr=3, 3!=4, move curr
Step 5: curr=4, 4==4, remove duplicate (second 4)
List: 1->2->3->4
Done.

================================================================================
*/

#include<iostream>
using namespace std;

// Node class for singly linked list
class Node{
    public:
        int data;      // Data stored in node
        Node* next;    // Pointer to next node

        // Constructor to initialize node
        Node(int data){
            this->data = data;
            this->next = NULL;
        }
};

// Utility function to print the linked list
void print(Node* &head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" "; // Print current node's data
        temp = temp->next;     // Move to next node
    }
    cout << endl;
}

// Function to remove duplicates from sorted linked list
void removeDuplicates(Node* &head){
    // Edge case: Empty list
    if(head == NULL){
        return;
    }
    // Edge case: Only one node
    if(head->next == NULL){
        return;
    }
    Node* curr = head; // Start from head
    // Traverse the list
    while(curr != NULL && curr->next != NULL){
        // If current node and next node have same data, remove next node
        if(curr->data == curr->next->data){
            Node* temp = curr->next;         // Store duplicate node
            curr->next = curr->next->next;   // Bypass duplicate node
            temp->next = NULL;               // Isolate duplicate node
            delete temp;                     // Free memory
        }
        else{
            curr = curr->next; // Move to next node if no duplicate
        }
    }
}

int main(){
    // Creating linked list: 1->2->2->3->4->4
    Node* head = new Node(1);
    Node* first = new Node(2);
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(4);
    Node* fifth = new Node(4);

    // Linking nodes
    head->next = first;
    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;

    cout<<"Input Linked List: ";
    print(head);

    removeDuplicates(head);

    cout<<"Output Linked List: ";
    print(head);

    return 0;
}

/*
================================================================================
Dry Run:
================================================================================
Input: 1 -> 2 -> 2 -> 3 -> 4 -> 4

Step 1: curr=1, curr->next=2, 1!=2, move curr
Step 2: curr=2, curr->next=2, 2==2, remove duplicate (second 2)
        List: 1->2->3->4->4
Step 3: curr=2, curr->next=3, 2!=3, move curr
Step 4: curr=3, curr->next=4, 3!=4, move curr
Step 5: curr=4, curr->next=4, 4==4, remove duplicate (second 4)
        List: 1->2->3->4
Step 6: curr=4, curr->next=NULL, done

Output: 1 2 3 4
================================================================================
*/