#include <iostream>
using namespace std;

/*
How it works:
---------------
- Check if at least k nodes exist in the current segment. If fewer, leave as is.
- Reverse exactly k nodes iteratively.
- Recursively reverse the remaining nodes and connect to the current reversed segment.
- Returns new head of the reversed group each time.
*/

// Node structure
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Insert node at end
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

// Reverse k nodes in linked list
Node* reverseKGroup(Node* head, int k) {
    if (!head) return nullptr;

    Node* curr = head;
    Node* prev = nullptr;
    Node* next = nullptr;
    int count = 0;

    // Check if there are at least k nodes left
    Node* temp = head;
    int nodeCount = 0;
    while (temp && nodeCount < k) {
        temp = temp->next;
        nodeCount++;
    }
    if (nodeCount < k) return head; // less than k nodes remain

    // Reverse first k nodes
    count = 0;
    curr = head;
    while (curr && count < k) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    // head is now the last node in reversed group
    // recursively reverse remaining list and connect
    if (next)
        head->next = reverseKGroup(next, k);

    return prev; // new head of reversed group
}

// Test the function
int main() {
    Node* head = nullptr;

    // Insert nodes
    for (int i = 1; i <= 10; i++)
        insertEnd(head, i);

    cout << "Original list: ";
    printList(head);

    int k = 3;
    head = reverseKGroup(head, k);

    cout << "List after reversing in groups of " << k << ": ";
    printList(head);

    return 0;
}
