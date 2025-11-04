#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

// Function to insert a node at a specific position (0-based index)
void insertAtPosition(Node*& head, int data, int position) {
    Node* newNode = createNode(data);

    // Case 1: Insert at the beginning
    if (position == 0) {
        newNode->next = head;
        head = newNode;
        return;
    }

    // Traverse to the (position - 1)th node
    Node* curr = head;
    for (int i = 0; curr != nullptr && i < position - 1; i++) {
        curr = curr->next;
    }

    // If position is invalid (greater than list length)
    if (curr == nullptr) {
        cout << "Position out of range!\n";
        delete newNode;
        return;
    }

    // Insert node
    newNode->next = curr->next;
    curr->next = newNode;
}

// Function to print the linked list
void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

// Function to append nodes at the end (for convenience)
void append(Node*& head, int data) {
    Node* newNode = createNode(data);
    if (head == nullptr) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr)
        temp = temp->next;
    temp->next = newNode;
}

// Main function
int main() {
    Node* head = nullptr;

    // Create linked list: 10 -> 20 -> 30
    append(head, 10);
    append(head, 20);
    append(head, 30);

    cout << "Original list: ";
    printList(head);

    // Insert 5 at position 0 (beginning)
    insertAtPosition(head, 5, 0);
    cout << "After inserting 5 at position 0: ";
    printList(head);

    // Insert 15 at position 2 (middle)
    insertAtPosition(head, 15, 2);
    cout << "After inserting 15 at position 2: ";
    printList(head);

    // Insert 40 at position 10 (invalid position)
    insertAtPosition(head, 40, 10);

    // Insert 35 at position 5 (end)
    insertAtPosition(head, 35, 5);
    cout << "After inserting 35 at position 5: ";
    printList(head);

    return 0;
}


