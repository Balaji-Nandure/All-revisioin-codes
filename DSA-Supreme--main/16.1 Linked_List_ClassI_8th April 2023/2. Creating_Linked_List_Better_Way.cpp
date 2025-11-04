#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

// Insert at head
void insertAtHead(Node* &head, int data) {
    Node* newNode = new Node(data);
    newNode->next = head;
    head = newNode;
}

// Insert at tail
void insertAtTail(Node* &head, int data) {
    Node* newNode = new Node(data);
    if (head == nullptr) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Print the linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    Node* head = nullptr;

    // Testing insertAtHead
    insertAtHead(head, 10);
    insertAtHead(head, 20);
    insertAtHead(head, 30);
    cout << "After inserting at head: ";
    printList(head);

    // Testing insertAtTail
    insertAtTail(head, 40);
    insertAtTail(head, 50);
    cout << "After inserting at tail: ";
    printList(head);

    return 0;
}
