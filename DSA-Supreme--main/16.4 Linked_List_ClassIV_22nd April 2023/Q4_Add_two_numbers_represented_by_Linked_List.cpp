// List1: 2 -> 4 -> 3   (represents 342)
// List2: 5 -> 6 -> 4   (represents 465)
// Output: 7 -> 0 -> 8  (represents 807)

#include <iostream>                          // Include iostream for input/output
using namespace std;                         // Use standard namespace

// Definition for singly-linked list.
struct ListNode {
    int val;                                // Value stored in node
    ListNode* next;                         // Pointer to next node
    ListNode(int x) : val(x), next(nullptr) {}  // Constructor to initialize value and next pointer
};

// Function to add two numbers represented by linked lists
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode dummy(0);                      // Create a dummy node to ease result list handling
    ListNode* curr = &dummy;                // Pointer to build the new list
    int carry = 0;                          // Carry-over value for digits sum

    while (l1 != nullptr || l2 != nullptr || carry) { // Loop until both lists are done and carry is zero
        int sum = carry;                    // Initialize sum to carry
        if (l1) {                           // If l1 is not null
            sum += l1->val;                 // Add value from l1
            l1 = l1->next;                  // Move to next node in l1
        }
        if (l2) {                           // If l2 is not null
            sum += l2->val;                 // Add value from l2
            l2 = l2->next;                  // Move to next node in l2
        }

        carry = sum / 10;                   // Calculate new carry after the sum
        curr->next = new ListNode(sum % 10); // Create new node with the digit value
        curr = curr->next;                  // Move pointer to the new node
    }

    return dummy.next;                      // Return the next node of dummy (real head)
}

// Helper function to print linked list
void printList(ListNode* node) {
    while (node) {                          // Traverse each node
        cout << node->val;                  // Print value of node
        if (node->next) cout << " -> ";     // Print arrow if not the last node
        node = node->next;                  // Move to next node
    }
    cout << endl;                           // Print a new line after list
}

// Helper function to create linked list from array
ListNode* createList(int arr[], int n) {
    if (n == 0) return nullptr;             // Return null if array is empty
    ListNode* head = new ListNode(arr[0]);  // Create head node
    ListNode* current = head;               // Pointer to current node
    for (int i = 1; i < n; i++) {           // Loop through rest of array
        current->next = new ListNode(arr[i]); // Create new node for each element
        current = current->next;            // Move to the new node
    }
    return head;                            // Return pointer to head node
}

int main() {
    int a1[] = {2, 4, 3};                   // First number as an array
    int a2[] = {5, 6, 4};                   // Second number as an array

    ListNode* l1 = createList(a1, 3);       // Create first linked list
    ListNode* l2 = createList(a2, 3);       // Create second linked list

    cout << "First number: ";               // Print label for first number
    printList(l1);                          // Print first linked list

    cout << "Second number: ";              // Print label for second number
    printList(l2);                          // Print second linked list

    ListNode* result = addTwoNumbers(l1, l2); // Add two numbers represented by linked lists
    cout << "Sum: ";                        // Print label for result
    printList(result);                      // Print resulting linked list

    return 0;                               // Return success
}
