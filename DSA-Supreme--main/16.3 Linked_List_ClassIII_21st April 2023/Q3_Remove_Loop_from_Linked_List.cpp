#include<iostream>
using namespace std;

/*

---------------------------------
Dry Run:
---------------------------------
List: 10->20->30->40->50->60->70->80->90
Loop: 90->next points to 50

Step 1: Detect loop (slow and fast meet at node 70)
Step 2: Move slow to head, move both pointers one step at a time
        They meet at node 50 (start of loop)
Step 3: prev is at node 90, set prev->next = NULL

Final List: 10 20 30 40 50 60 70 80 90
*/


// Node class for singly linked list
class Node{
    public:
        int data;      // Data stored in node
        Node* next;    // Pointer to next node

        // Constructor to initialize node
        Node(int data){
            this->data = data;
            this->next = NULL;
        }
};

// Utility function to get length of linked list
int getLength(Node* &head){
    int len = 0;
    Node* temp = head;
    while(temp != NULL){
        temp = temp->next; // Move to next node
        len++;             // Increment length
    }
    return len;
}

// Function to reverse nodes in groups of k
Node *reverseKNodes(Node* &head,int k){
    // If list is empty, return as is
    if(head == NULL){
        return head;
    }
    // If k is greater than length, do not reverse
    int len = getLength(head);
    if(k > len){
        return head;
    }
    // Reverse first k nodes
    Node* prev = NULL;
    Node* curr = head;
    Node* forward = curr->next;
    int count = 0;
    while(count < k && curr != NULL){
        forward = curr->next;   // Store next node
        curr->next = prev;      // Reverse current node's pointer
        prev = curr;            // Move prev forward
        curr = forward;         // Move curr forward
        count++;
    }
    // Recursively reverse next k nodes
    if(forward != NULL){
        head->next = reverseKNodes(forward,k); // Connect reversed part to next
    }
    // Return new head after reversal
    return prev;
}

// Function to detect and remove loop in linked list
void removeLoop(Node* &head){
    if(head == NULL){
        // Empty list, nothing to do
        return;
    }
    Node* slow = head; // Slow pointer
    Node* fast = head; // Fast pointer
    bool loopExists = false;

    // Step 1: Detect loop using Floyd's algorithm
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;         // Move slow by 1
        fast = fast->next->next;   // Move fast by 2

        if(slow == fast){
            // Loop detected
            loopExists = true;
            break;
        }
    }

    if(!loopExists){
        // No loop found, return
        return;
    }

    // Step 2: Find start of loop
    slow = head; // Move slow to head
    Node* prev = NULL; // To keep track of node before fast

    // Move both pointers at same speed, they will meet at loop start
    while(slow != fast){
        prev = fast;         // Store previous node of fast
        slow = slow->next;   // Move slow by 1
        fast = fast->next;   // Move fast by 1
    }

    // Step 3: Remove loop
    // 'prev' is the last node in the loop, so set its next to NULL
    prev->next = NULL;
}

// Function to print linked list
void print(Node* &head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" "; // Print data
        temp = temp->next;     // Move to next node
    }
    cout << endl;
}

int main(){
    // Creating nodes
    Node* head = new Node(10);
    Node* first = new Node(20);
    Node* second = new Node(30);
    Node* third = new Node(40);
    Node* fourth = new Node(50);
    Node* fifth = new Node(60);
    Node* sixth = new Node(70);
    Node* seventh = new Node(80);
    Node* eigth = new Node(90);

    // Linking nodes to form a list
    head->next = first;
    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = seventh;
    seventh->next = eigth;

    // Creating a loop: eigth->next points to fourth (50)
    eigth->next = fourth;

    // Remove loop if present
    removeLoop(head);

    // Print the list after loop removal
    print(head);

    return 0;
}

