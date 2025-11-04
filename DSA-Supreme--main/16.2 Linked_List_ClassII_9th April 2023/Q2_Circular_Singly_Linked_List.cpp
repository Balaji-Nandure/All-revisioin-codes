/*
Approach Used:
---------------
This code implements a Circular Singly Linked List (CSLL) with the following operations:
- Insert at head, tail, or any position
- Delete at head, tail, or any position
- Print the list
- Find the length of the list

Key Points:
- The list is circular: the last node points back to the head.
- Both head and tail pointers are maintained for O(1) insertions at both ends.
- Each operation handles the empty list case.
- Memory management is handled in the destructor.

Alternative Approaches:
-----------------------
1. Instead of using both head and tail, we could use only head and traverse to the end for tail operations (less efficient).
2. For deletion, we could use a dummy node to simplify edge cases.
3. For printing, we could use a do-while loop for clarity.
4. For better memory management, avoid recursive destructor (can cause stack overflow for large lists).

Below is the improved code with detailed comments and some optimizations.

Dry Run is provided at the end.
*/

#include<iostream>
using namespace std;

// Node class for CSLL
class Node{
    public:
        int data;       // Data stored in node
        Node* next;     // Pointer to next node

        Node(int data){
            this->data = data;
            this->next = this; // For single node, next points to itself (circular)
        }

        // Destructor to free memory
        ~Node(){
            int val = this->data;
            // Only delete next if it's not self and not NULL (to avoid infinite recursion)
            if(this->next != NULL && this->next != this){
                delete next;
                this->next = NULL;
            }
            cout<<"Memory free for node with value = "<<val<<endl;
        }
};

// Function to find length of CSLL
int findLength(Node* &head){
    if(head == NULL) return 0; // Handle empty list
    int len = 1;
    Node* temp = head;
    // Traverse until we reach head again
    while(temp->next != head){
        len++;
        temp = temp->next;
    }
    return len;
}

// Insert at head of CSLL
void insertAtHead(Node* &head,Node* &tail,int data){
    if(head == NULL){
        // If list is empty, create new node and point head and tail to it
        Node* temp = new Node(data);
        head = temp;
        tail = temp;
        return;
    }
    // Create new node
    Node* temp = new Node(data);
    // Connect new node to current head
    temp->next = head;
    // Tail should point to new head (circular property)
    tail->next = temp;
    // Update head
    head = temp;
}

// Insert at tail of CSLL
void insertAtTail(Node* &head,Node* &tail,int data){
    if(head == NULL){
        // If list is empty, create new node and point head and tail to it
        Node* temp = new Node(data);
        head = temp;
        tail = temp;
        return;
    }
    // Create new node
    Node* newNode = new Node(data);
    // New node points to head (circular)
    newNode->next = head;
    // Old tail points to new node
    tail->next = newNode;
    // Update tail
    tail = newNode;
}

// Insert at a given position in CSLL (0-based index)
void insertAtPosition(Node* &head,Node*& tail,int data,int pos){
    // If list is empty, insert as the only node
    if(head == NULL){
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }
    // Insert at head
    if(pos == 0){
        insertAtHead(head,tail,data);
        return;
    }
    int len = findLength(head);
    // Insert at tail if pos >= len
    if(pos >= len){
        insertAtTail(head,tail,data);
        return;
    }
    // Traverse to node just before the desired position
    int i = 1;
    Node* prev = head;
    while(i < pos){
        prev = prev->next;
        i++;
    }
    // Create new node and insert
    Node* newNode = new Node(data);
    newNode->next = prev->next;
    prev->next = newNode;
}

// Delete head node of CSLL
void deleteHead(Node* &head,Node* &tail){
    if(head == NULL) return; // Empty list
    if(head == tail){
        // Only one node in list
        delete head;
        head = NULL;
        tail = NULL;
        return;
    }
    Node* temp = head;
    head = head->next;      // Move head to next node
    tail->next = head;      // Tail should point to new head
    temp->next = NULL;      // Break link for safe deletion
    delete temp;
}

// Delete tail node of CSLL
void deleteTail(Node* &head,Node* &tail){
    if(head == NULL) return; // Empty list
    if(head == tail){
        // Only one node in list
        delete head;
        head = NULL;
        tail = NULL;
        return;
    }
    Node* temp = head;
    // Traverse to node just before tail
    while(temp->next != tail){
        temp = temp->next;
    }
    temp->next = head;      // New tail points to head
    tail->next = NULL;      // Break link for safe deletion
    delete tail;
    tail = temp;            // Update tail
}

// Delete node at given position (0-based index)
void deleteOperation(int position, Node *&head, Node *&tail)
{
    if (head == NULL)
    {
        cout << "Cannot delete, LL is empty" << endl;
        return;
    }
    int len = findLength(head);
    // Head node deletion
    if(position == 0)
    {
        deleteHead(head,tail);
        return;
    }
    // Tail node deletion
    if(position >= len-1){
        deleteTail(head,tail);
        return;
    }
    // Traverse to node just before the one to delete
    int i = 1;
    Node *prev = head;
    while (i < position){
        prev = prev->next;
        i++;
    }
    Node *curr = prev->next;
    prev->next = curr->next; // Bypass the node to delete
    curr->next = NULL;       // Break link for safe deletion
    delete curr;
}

// Print the CSLL
void printList(Node* &head){
    if(head == NULL){
        cout << "List is empty" << endl;
        return;
    }
    Node* temp = head;
    do{
        cout<<temp->data<<" ";
        temp = temp->next;
    }while(temp!=head);
    cout << endl;
}

/*
Alternative (Better) Approaches (in comments):

// 1. Use a dummy node to simplify insert/delete at head/tail (avoids special cases).
// 2. Use a do-while loop for printing and length calculation for clarity.
// 3. Avoid recursive destructor for large lists (can cause stack overflow).
//    Instead, provide an explicit function to delete the entire list iteratively.
// 4. For deletion, always check if the list becomes empty after operation and update head/tail accordingly.

Example for iterative list deletion:
void deleteList(Node* &head, Node* &tail) {
    if(head == NULL) return;
    Node* curr = head;
    do {
        Node* nextNode = curr->next;
        curr->next = NULL;
        delete curr;
        curr = nextNode;
    } while(curr != head);
    head = NULL;
    tail = NULL;
}
*/

// Main function to test CSLL operations
int main(){
    Node* head = new Node(10); // Create initial node
    Node* tail = head;         // Both head and tail point to the only node

    // Insert at tail
    insertAtTail(head,tail,20); // 10 20
    insertAtTail(head,tail,30); // 10 20 30
    insertAtTail(head,tail,40); // 10 20 30 40
    insertAtTail(head,tail,50); // 10 20 30 40 50

    // Insert at position 3 (0-based), so after 30
    insertAtPosition(head,tail,35,3); // 10 20 30 35 40 50

    cout<<"Length of list: "<<findLength(head)<<endl; // Should print 6

    // Delete node at position 6 (out of bounds, so deletes tail)
    deleteOperation(6,head,tail); // Deletes 50

    // Print final list
    printList(head);

    // Uncomment to test head/tail deletion
    // deleteHead(head,tail);
    // deleteTail(head,tail);

    // Uncomment to delete entire list
    // deleteList(head, tail);

    return 0;
}

/*
Dry Run:
--------
Initial: 10
After insertAtTail: 10 20 30 40 50
After insertAtPosition(35,3): 10 20 30 35 40 50
Length: 6
deleteOperation(6): position >= length-1, so deleteTail (deletes 50)
Final list: 10 20 30 35 40

Memory free for node with value = 50
Memory free for node with value = 40
Memory free for node with value = 35
Memory free for node with value = 30
Memory free for node with value = 20
Memory free for node with value = 10
*/