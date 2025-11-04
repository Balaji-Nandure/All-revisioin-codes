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

// Create a cycle at a given position (1-based)
void createCycle(Node* head, int pos) {
    if (!head || pos <= 0) return;

    Node* temp = head;
    Node* cycleNode = nullptr;
    int count = 1;
    while (temp->next) {
        if (count == pos)
            cycleNode = temp;
        temp = temp->next;
        count++;
    }
    temp->next = cycleNode; // form cycle
}

// Detect cycle using Floyd’s algorithm
bool hasCycle(Node* head) {
    Node* slow = head;
    Node* fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            return true;
    }
    return false;
}

// Test the cycle detection
int main() {
    Node* head = nullptr;

    // Create linked list: 1 -> 2 -> 3 -> 4 -> 5
    for (int i = 1; i <= 5; i++)
        insertEnd(head, i);

    cout << "Cycle detected? " << (hasCycle(head) ? "Yes" : "No") << endl;

    // Create a cycle at position 3 (node with value 3 points back)
    createCycle(head, 3);

    cout << "Cycle detected after creating cycle? " << (hasCycle(head) ? "Yes" : "No") << endl;

    return 0;
}
