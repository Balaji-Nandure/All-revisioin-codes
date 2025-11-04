
#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* prev;
        Node* next;

        Node(){
            this->data = 0;
            this->prev = NULL;
            this->next = NULL;
        }
        Node(int data){
            this->data = data;
            this->prev = NULL;
            this->next = NULL;
        }
};

void print(Node* &head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

int getLength(Node* &head){
    if(head == NULL) return 0;
    Node* temp = head;
    int len = 1;
    while(temp->next != NULL){
        len++;
        temp = temp->next;
    }
    return len;
}

void insertAtHead(Node* &head,Node* &tail,int data){
    if(head == NULL){
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }
    Node* newNode = new Node(data);
    newNode -> next = head;
    head -> prev = newNode;
    head = newNode;
}

void insertAtTail(Node* &head,Node* &tail,int data){
    if(head == NULL){
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }
    Node* newNode = new Node(data);
    tail->next = newNode;
    newNode -> prev = tail;
    tail = newNode;
}

void insertAtPosition(int pos, Node* &head, Node* &tail, int data) {
    if (pos <= 1) {
        insertAtHead(head, tail, data);
        return;
    }
    int i = 1;
    Node* temp = head;
    while (temp && i < pos - 1) {
        temp = temp->next;
        i++;
    }
    if (!temp || !temp->next) {
        insertAtTail(head, tail, data);
        return;
    }
    Node* newNode = new Node(data);
    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next->prev = newNode;
    temp->next = newNode;
}

int main(){
    Node* head = new Node(10);
    Node* tail = head;

    // insertAtHead(head,tail,20);

    insertAtTail(head,tail,20);
    insertAtTail(head,tail,30);
    insertAtTail(head,tail,40);
    insertAtTail(head,tail,50);

    insertAtPosition(5,head,tail,60);

    print(head);
    cout<<endl;
    cout<<"Length = "<< getLength(head);
    return 0;
}
