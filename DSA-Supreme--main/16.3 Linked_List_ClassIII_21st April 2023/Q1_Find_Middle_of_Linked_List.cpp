
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

// Function to find the middle node using slow and fast pointer approach
Node* getMiddle(Node* &head){
    // Handle empty linked list
    if(head == NULL){
        cout << "Linked List is empty" << endl;
        return NULL;
    }
    // Handle single node case
    if(head->next == NULL){
        return head;
    }

    Node* slow = head; // Slow pointer starts at head
    Node* fast = head; // Fast pointer starts at head

    // Traverse the list: fast moves 2 steps, slow moves 1 step
    // When fast reaches end, slow will be at the middle
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;           // Move slow by 1
        fast = fast->next->next;     // Move fast by 2
    }
    // When loop ends, slow is at the middle node
    return slow;
}

int main(){
    // Create linked list: 10 -> 20 -> 30 -> 40
    Node* head = new Node(10);           // Head node with data 10
    Node* first = new Node(20);          // Node with data 20
    Node* second = new Node(30);         // Node with data 30
    Node* third = new Node(40);          // Node with data 40

    head->next = first;                  // Link head to first
    first->next = second;                // Link first to second
    second->next = third;                // Link second to third

    Node* middle = getMiddle(head);      // Find the middle node

    if(middle != NULL)
        cout << "Middle node = " << middle->data << endl; // Output the middle node's data

    return 0;
}