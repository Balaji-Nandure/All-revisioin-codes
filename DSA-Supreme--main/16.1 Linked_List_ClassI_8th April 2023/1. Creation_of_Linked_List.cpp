
#include<iostream>
using namespace std;

// Node class definition for singly linked list
class Node{
    public:
        int data;      // Data stored in the node
        Node* next;    // Pointer to the next node

        // Default constructor: initializes data to 0 and next to NULL
        Node(){
            this->data = 0;
            this->next = NULL;
        }

        // Parameterized constructor: initializes data to given value and next to NULL
        Node(int data){
            this->data = data;
            this->next = NULL;
        }
};

// Function to print the linked list from given head node
void printList(Node* head) {
    Node* temp = head; // Start from the head node
    while(temp != NULL) { // Traverse until the end of the list
        cout << temp->data << " "; // Print current node's data
        temp = temp->next; // Move to the next node
    }
    cout << endl;
}

int main(){
    // Step 1: Creation of Nodes of Linked list
    Node* first = new Node(1);   // Create first node with data=1
    Node* second = new Node(2);  // Create second node with data=2
    Node* third = new Node(3);   // Create third node with data=3

    // Step 2: Connecting nodes to form the linked list
    first->next = second;        // Link first node to second node
    second->next = third;        // Link second node to third node
    third->next = NULL;          // Last node points to NULL (end of list)

    // Step 3: Print the linked list to verify
    cout << "Linked List: ";
    printList(first);

    // (Optional) Step 4: Free allocated memory (good practice)
    delete first;
    delete second;
    delete third;

    return 0;
}
