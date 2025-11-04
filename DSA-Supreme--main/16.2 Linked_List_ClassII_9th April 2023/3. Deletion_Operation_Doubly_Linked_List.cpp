#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* prev;
    Node* next;
    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};

// Insert at the end
void insertEnd(Node*& head, Node*& tail, int data) {
    Node* newNode = new Node(data);
    if (!head) {
        head = tail = newNode;
        return;
    }
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}

// Delete node at a given position (1-based)
void deleteAtPosition(Node*& head, Node*& tail, int pos) {
    if (!head || pos <= 0) {
        cout << "Invalid position!\n";
        return;
    }

    Node* temp = head;
    int count = 1;

    // Traverse to the node at position pos
    while (temp && count < pos) {
        temp = temp->next;
        count++;
    }

    if (!temp) {
        cout << "Position out of range!\n";
        return;
    }

    // Update head and tail if needed
    if (temp == head)
        head = head->next;
    if (temp == tail)
        tail = tail->prev;

    // Update pointers of neighboring nodes
    if (temp->next)
        temp->next->prev = temp->prev;
    if (temp->prev)
        temp->prev->next = temp->next;

    delete temp;
}

// Print list from head to tail
void printList(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Print list from tail to head
void printListReverse(Node* tail) {
    Node* temp = tail;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->prev;
    }
    cout << endl;
}

// Test the DLL with head and tail
int main() {
    Node* head = nullptr;
    Node* tail = nullptr;

    // Insert nodes
    insertEnd(head, tail, 10);
    insertEnd(head, tail, 20);
    insertEnd(head, tail, 30);
    insertEnd(head, tail, 40);
    insertEnd(head, tail, 50);

    cout << "Original list (head -> tail): ";
    printList(head);
    cout << "Original list (tail -> head): ";
    printListReverse(tail);

    // Delete middle node (position 3)
    deleteAtPosition(head, tail, 3);
    cout << "After deleting position 3 (head -> tail): ";
    printList(head);
    cout << "After deleting position 3 (tail -> head): ";
    printListReverse(tail);

    // Delete head node (position 1)
    deleteAtPosition(head, tail, 1);
    cout << "After deleting head (head -> tail): ";
    printList(head);
    cout << "After deleting head (tail -> head): ";
    printListReverse(tail);

    // Delete tail node (current position 3)
    deleteAtPosition(head, tail, 3);
    cout << "After deleting tail (head -> tail): ";
    printList(head);
    cout << "After deleting tail (tail -> head): ";
    printListReverse(tail);

    // Delete invalid position
    deleteAtPosition(head, tail, 10);

    return 0;
}
