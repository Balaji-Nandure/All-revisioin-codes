
#include<iostream>
using namespace std;

// Node class for singly linked list
class Node{
    public:
        int data;       // stores data of node
        Node* next;     // pointer to next node

        // Constructor to initialize node with data
        Node(int data){
            this->data = data;
            this->next = NULL;
        }

        // Destructor to free memory recursively
        ~Node(){
            int val = this->data;
            // If next is not NULL, delete the next node recursively
            if(this->next!=NULL){
                delete next;
                this->next = NULL;
            }
            cout<<"Memory free of node with value = "<<val<<endl;
        }
};

// Insert a new node at the head (beginning) of the list
void insertAtHead(Node* &head,int data){
    // If list is empty, create new node and set as head
    if(head == NULL){
        Node* temp = new Node(data);
        head = temp;
        return;
    }
    // Create new node and point its next to current head
    Node* newNode = new Node(data);
    newNode->next = head;
    // Update head to new node
    head = newNode;
}

// Insert a new node at the tail (end) of the list
void insertAtTail(Node* &head,int data){
    // If list is empty, create new node and set as head
    if(head == NULL){
        Node* temp = new Node(data);
        head = temp;
        return;
    }
    // Traverse to the last node
    Node* temp = head;
    while(temp -> next != NULL){
        temp = temp->next;
    }
    // Create new node and link it at the end
    Node* newNode = new Node(data);
    temp->next = newNode;
}

// Find the length of the linked list
int findLength(Node* &head){
    if (head == NULL) return 0; // handle empty list
    Node* temp = head;
    int len = 1;
    // Traverse till the end, incrementing length
    while(temp->next!=NULL){
        len++;
        temp = temp->next;
    }
    return len;
}

// Insert a new node at a given position (0-based index)
void insertAtPosition(Node* &head,int data,int pos){
    // If list is empty, insert at head
    if(head == NULL){
        Node* newNode = new Node(data);
        head = newNode;
        return;
    }
    // If position is 0, insert at head
    if(pos == 0){
        insertAtHead(head,data);
        return;
    }
    int len = findLength(head);
    cout<<"Current Length: "<<len<<endl;
    // If position is at the end, insert at tail
    if(len == pos){
        insertAtTail(head,data);
        return;
    }
    // If position is invalid (greater than length), do nothing or handle error
    if(pos > len || pos < 0){
        cout << "Invalid position for insertion." << endl;
        return;
    }
    // Traverse to the node just before the desired position
    int i = 1;
    Node* prev = head;
    while(i<pos){
        prev = prev->next;
        i++;
    }
    // Create new node and insert it at the position
    Node* newNode = new Node(data);
    newNode -> next = prev->next;
    prev->next = newNode;
}

// Print all elements of the linked list
void printList(Node* &head){
    Node* temp = head;
    // Traverse and print each node's data
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout << endl;
}

int main(){
    // Create initial list with one node (10)
    Node* head = new Node(10);

    // Insert nodes at the tail
    insertAtTail(head,20);   // List: 10 20
    insertAtTail(head,30);   // List: 10 20 30
    insertAtTail(head,40);   // List: 10 20 30 40
    insertAtTail(head,50);   // List: 10 20 30 40 50
    insertAtTail(head,60);   // List: 10 20 30 40 50 60

    // Insert 25 at position 1 (after 10)
    insertAtPosition(head,25,1); // List: 10 25 20 30 40 50 60

    // Print the final list
    printList(head);

    // Memory will be freed automatically due to destructor
    return 0;
}
