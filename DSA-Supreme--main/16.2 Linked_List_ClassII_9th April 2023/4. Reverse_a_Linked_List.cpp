#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Insert node at the end
void insertEnd(Node*& head, int data) {
    Node* newNode = new Node(data);
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next)
        temp = temp->next;
    temp->next = newNode;
}

// Print list
void printList(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Reverse using iteration
void reverseIterative(Node*& head) {
    Node* prev = nullptr;
    Node* curr = head;
    Node* next = nullptr;

    while (curr) {
        next = curr->next;  // store next
        curr->next = prev;  // reverse current node
        prev = curr;        // move prev forward
        curr = next;        // move curr forward
    }

    head = prev;
}

// Reverse using recursion
Node* reverseRecursive(Node* head) {
    if (!head || !head->next)
        return head;  // base case: empty or single node

    Node* newHead = reverseRecursive(head->next); // reverse rest
    head->next->next = head;  // make next node point to current
    head->next = nullptr;     // set current node next to null

    return newHead;
}

// Test both methods
int main() {
    Node* head = nullptr;

    // Insert nodes
    insertEnd(head, 1);
    insertEnd(head, 2);
    insertEnd(head, 3);
    insertEnd(head, 4);
    insertEnd(head, 5);

    cout << "Original list: ";
    printList(head);

    // Reverse iteratively
    reverseIterative(head);
    cout << "Reversed iteratively: ";
    printList(head);

    // Reverse recursively
    head = reverseRecursive(head);
    cout << "Reversed recursively: ";
    printList(head);

    return 0;
}
