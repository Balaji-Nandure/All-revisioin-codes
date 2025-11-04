#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

// Function to insert a new node at the end
void append(Node*& head, int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr)
        temp = temp->next;
    temp->next = newNode;
}

// Function to delete a node by value
void deleteByValue(Node*& head, int key) {
    if (head == nullptr) return;

    // If head node holds the key
    if (head->data == key) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* curr = head;
    while (curr->next != nullptr && curr->next->data != key)
        curr = curr->next;

    // Key not found
    if (curr->next == nullptr) return;

    // Delete node
    Node* temp = curr->next;
    curr->next = curr->next->next;
    delete temp;
}

// Function to delete a node by position (0-based index)
void deleteByPosition(Node*& head, int position) {
    if (head == nullptr) return;

    // Delete head node
    if (position == 0) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* curr = head;
    for (int i = 0; curr != nullptr && i < position - 1; i++)
        curr = curr->next;

    // If position is invalid
    if (curr == nullptr || curr->next == nullptr) return;

    Node* temp = curr->next;
    curr->next = curr->next->next;
    delete temp;
}

// Function to print the linked list
void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

// Main function
int main() {
    Node* head = nullptr;

    // Create linked list: 10 -> 20 -> 30 -> 40 -> NULL
    append(head, 10);
    append(head, 20);
    append(head, 30);
    append(head, 40);

    cout << "Original list: ";
    printList(head);

    // Delete by value
    deleteByValue(head, 20);
    cout << "After deleting 20: ";
    printList(head);

    // Delete by position
    deleteByPosition(head, 1);
    cout << "After deleting position 1: ";
    printList(head);

    return 0;
}
