
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int data = 0) {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }

    ~Node() {
        cout << "Deleted node with value = " << this->data << endl;
    }
};

void print(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int getLength(Node* head) {
    int len = 0;
    Node* temp = head;
    while (temp != NULL) {
        len++;
        temp = temp->next;
    }
    return len;
}

int main() {
    Node* head = new Node(10);
    Node* first = new Node(20);

    head->next = first;
    first->prev = head;

    print(head);

    cout << "Length = " << getLength(head) << endl;

    delete first;
    delete head;

    return 0;
}
