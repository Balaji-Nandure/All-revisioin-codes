
#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int data = 0) : data(data), next(nullptr) {}
};

void insertAtHead(Node*& head, Node*& tail, int data) {
    Node* newNode = new Node(data);
    if (!head) {
        head = tail = newNode;
    } else {
        newNode->next = head;
        head = newNode;
    }
}

void insertAtTail(Node*& head, Node*& tail, int data) {
    Node* newNode = new Node(data);
    if (!head) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

void print(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void freeList(Node*& head) {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    Node* head = nullptr;
    Node* tail = nullptr;

    cout << "Testing insertAtTail:" << endl;
    insertAtTail(head, tail, 10);
    insertAtTail(head, tail, 20);
    insertAtTail(head, tail, 30);
    print(head); // 10 20 30

    cout << "Testing insertAtHead:" << endl;
    insertAtHead(head, tail, 5);
    insertAtHead(head, tail, 2);
    print(head); // 2 5 10 20 30

    cout << "Testing empty list creation with head insertion:" << endl;
    freeList(head);
    tail = nullptr;
    insertAtHead(head, tail, 99);
    insertAtHead(head, tail, 98);
    insertAtTail(head, tail, 100);
    print(head); // 98 99 100

    freeList(head);
    tail = nullptr;
    cout << "Testing insertAtTail with empty list:" << endl;
    insertAtTail(head, tail, 42);
    print(head); // 42

    freeList(head);
    return 0;
}
