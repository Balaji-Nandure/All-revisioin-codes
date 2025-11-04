#include <iostream> // for input-output operations
using namespace std; // use standard C++ namespace

// Node structure
struct Node {
    int data; // store the data
    Node* next; // pointer to next node
    Node(int val) : data(val), next(nullptr) {} // constructor to initialize
};

// Insert node at end
void insertEnd(Node*& head, int data) {
    Node* newNode = new Node(data); // create new node
    if (!head) { // if list is empty
        head = newNode; // set head
        return; // done
    }
    Node* temp = head; // start at head
    while (temp->next) // traverse till last node
        temp = temp->next; // move to next node
    temp->next = newNode; // insert new node at end
}

// Print list
void printList(Node* head) {
    Node* temp = head; // start from head
    while (temp) { // traverse all nodes
        cout << temp->data << " "; // print data
        temp = temp->next; // move to next node
    }
    cout << endl; // new line at end
}

// Reverse a linked list and return new head
Node* reverseList(Node* head) {
    Node* prev = nullptr; // previous node (initially null)
    Node* curr = head; // current node (start from head)
    Node* next = nullptr; // next node placeholder
    while (curr) { // iterate through list
        next = curr->next; // save next node
        curr->next = prev; // reverse pointer
        prev = curr; // move prev forward
        curr = next; // move curr forward
    }
    return prev; // prev is new head
}

// Check if linked list is palindrome
bool isPalindrome(Node* head) {
    if (!head || !head->next) return true; // empty/single node is palindrome

    // Find middle using slow & fast pointers
    Node* slow = head; // slow pointer
    Node* fast = head; // fast pointer
    while (fast->next && fast->next->next) { // check until end
        slow = slow->next; // move slow by one
        fast = fast->next->next; // move fast by two
    }

    // Reverse second half
    Node* secondHalf = reverseList(slow->next); // reverse after middle

    // Compare first half and reversed second half
    Node* firstHalf = head; // start of first half
    Node* tempSecond = secondHalf; // start of reversed half
    bool palindrome = true; // flag to check palindrome
    while (tempSecond) { // traverse reversed second half
        if (firstHalf->data != tempSecond->data) { // mismatch
            palindrome = false; // not palindrome
            break; // exit loop
        }
        firstHalf = firstHalf->next; // move to next node
        tempSecond = tempSecond->next; // move to next node
    }

    // Restore the list (optional)
    slow->next = reverseList(secondHalf); // restore the list to original

    return palindrome; // return palindrome result
}

// Test
int main() {
    Node* head = nullptr; // create empty list

    // Create linked list: 1->2->3->2->1
    insertEnd(head, 1); // insert 1
    insertEnd(head, 2); // insert 2
    insertEnd(head, 3); // insert 3
    insertEnd(head, 2); // insert 2
    insertEnd(head, 1); // insert 1

    cout << "Linked list: "; // print statement
    printList(head); // print the list

    cout << "Is palindrome? " << (isPalindrome(head) ? "Yes" : "No") << endl; // check palindrome

    // Linked list after function (restored)
    cout << "Linked list after check: "; // print statement
    printList(head); // print restored list

    return 0; // end of main
}
