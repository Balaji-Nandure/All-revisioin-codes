#include <iostream>               // Include input-output stream library for cin, cout
using namespace std;              // Use standard namespace throughout the program

// Node structure for singly linked list
struct Node {
    int data;                     // Stores the integer value for the node
    Node* next;                   // Pointer to next node in the list
    Node(int val) : data(val), next(nullptr) {} // Constructor to initialize data and set next as null
};

// Insert node at the end of the linked list
void insertEnd(Node*& head, int data) {
    Node* newNode = new Node(data);        // Create a new node with the passed data
    if (!head) {                          // If the list is empty (head is null)
        head = newNode;                   // Make the new node the head
        return;                           // Return since the node is already inserted
    }
    Node* temp = head;                    // Start from the head node
    while (temp->next)                    // Traverse till the last node
        temp = temp->next;                // Move the temp pointer to next node
    temp->next = newNode;                 // Attach the newly created node at the end
}

// Print all elements of the linked list
void printList(Node* head) {
    Node* temp = head;                    // Start from head
    while (temp) {                        // Iterate through all nodes
        cout << temp->data << " ";        // Print the node's data
        temp = temp->next;                // Move to the next node
    }
    cout << endl;                         // Print newline after list is printed
}

//
// -------------------- METHOD 1 --------------------
// Sorting by counting (data replacement)
//

// Sort the linked list by counting the number of 0s, 1s, and 2s
void sort012_count(Node* head) {
    int count0 = 0, count1 = 0, count2 = 0;   // Counters for 0's, 1's, and 2's
    Node* temp = head;                        // Pointer for traversing the list

    // Count number of 0s, 1s, and 2s in the list
    while (temp) {
        if (temp->data == 0) count0++;        // If data is 0, increment count0
        else if (temp->data == 1) count1++;   // If data is 1, increment count1
        else count2++;                        // Otherwise increment count2 (should be 2)
        temp = temp->next;                    // Move to the next node
    }

    // Overwrite node data with 0s, 1s, then 2s, using counted values
    temp = head;                              // Go back to beginning of the list
    while (temp) {
        if (count0 > 0) {                     // First write all 0s
            temp->data = 0;
            count0--;
        } else if (count1 > 0) {              // Then write all 1s
            temp->data = 1;
            count1--;
        } else {                              // Then write all 2s
            temp->data = 2;
            count2--;
        }
        temp = temp->next;                    // Move to next node
    }
}

//
// -------------------- METHOD 2 --------------------
// Sorting without data replacement (pointer rearrangement)
//
// Sorts using node rearrangement (does not change any node's actual data)
Node* sort012_links(Node* head) {
    if (!head || !head->next) return head;    // If list empty or only one node, already sorted

    Node* zeroHead = new Node(-1);            // Dummy head for 0's list
    Node* oneHead = new Node(-1);             // Dummy head for 1's list
    Node* twoHead = new Node(-1);             // Dummy head for 2's list
    Node* zero = zeroHead;                    // Tail pointer for 0's list
    Node* one = oneHead;                      // Tail pointer for 1's list
    Node* two = twoHead;                      // Tail pointer for 2's list

    Node* curr = head;                        // Pointer to traverse original list
    while (curr) {
        if (curr->data == 0) {                // If current node is 0
            zero->next = curr;                // Append to 0's list
            zero = zero->next;                // Move tail forward
        } else if (curr->data == 1) {         // If current node is 1
            one->next = curr;                 // Append to 1's list
            one = one->next;                  // Move tail forward
        } else {                              // Must be 2
            two->next = curr;                 // Append to 2's list
            two = two->next;                  // Move tail forward
        }
        curr = curr->next;                    // Move to next node in main list
    }

    // Connect the three segregated lists together: 0's -> 1's -> 2's
    zero->next = (oneHead->next) ? oneHead->next : twoHead->next; // Connect 0's list to 1's, or 2's if 1's empty
    one->next = twoHead->next;                                    // Connect 1's list to 2's list
    two->next = nullptr;                                          // Make sure 2's tail points to null

    // Head is now the next node after 0's dummy node
    Node* newHead = zeroHead->next;            // Set new head reference

    // Delete the dummy nodes to avoid memory leak
    delete zeroHead;
    delete oneHead;
    delete twoHead;

    return newHead;                             // Return the newly arranged head pointer
}

// Test the above functions with an example
int main() {
    Node* head = nullptr;              // Start with empty linked list

    // Create linked list: 1 -> 0 -> 2 -> 1 -> 0 -> 2 -> 1
    insertEnd(head, 1);                // Insert 1 at end
    insertEnd(head, 0);                // Insert 0 at end
    insertEnd(head, 2);                // Insert 2 at end
    insertEnd(head, 1);                // Insert 1 at end
    insertEnd(head, 0);                // Insert 0 at end
    insertEnd(head, 2);                // Insert 2 at end
    insertEnd(head, 1);                // Insert 1 at end

    cout << "Original list: ";         // Print before sorting (method 1)
    printList(head);                   // Show the list

    // ---- Method 1: Counting (with data replacement)
    sort012_count(head);               // Sort using count method (changes node data)
    cout << "After sorting (Method 1 - counting): "; // Print header for method 1 result
    printList(head);                   // Print sorted list

    // ---- Reset list and test Method 2
    head = nullptr;                    // Reset head to null for fresh list
    insertEnd(head, 1);                // Re-populate list with same values
    insertEnd(head, 0);
    insertEnd(head, 2);
    insertEnd(head, 1);
    insertEnd(head, 0);
    insertEnd(head, 2);
    insertEnd(head, 1);

    head = sort012_links(head);        // Sort list using pointer rearrangement (no data changes)
    cout << "After sorting (Method 2 - link rearrangement): "; // Print header for method 2 result
    printList(head);                   // Print the rearranged list

    return 0;                          // Signal successful termination to OS
}
