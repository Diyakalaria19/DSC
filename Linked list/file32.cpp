//Add “1” to a number represented as a Linked List.

#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};

// Function to reverse the linked list
Node* reverse(Node* head) {
    Node *curr = head, *prev = nullptr, *next;
    while (curr != nullptr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

// Function to add one to a linked list and 
// return the head node of the resultant list
Node *addOneUtil(Node *head) {
    Node *res = head;
  	Node *curr = head;
    Node *last = nullptr;


    int carry = 1;
    int sum;

    while (curr != nullptr) {
        sum = carry + curr->data;

        // Update carry for next digit
        carry = (sum >= 10) ? 1 : 0;

        // Update current node's data to sum modulo 10
        curr->data = sum % 10;

        // Move to the next node
        last = curr;
        curr = curr->next;
    }

    if (carry > 0) {
        last->next = new Node(carry);
    }

    return res;
}

// Main function to add one to the linked list
Node *addOne(Node *head) {
  
    // Reverse the linked list
    head = reverse(head);

    // Add one to the reversed list
    head = addOneUtil(head);

    // Reverse the list again to restore
  	// the original order
    return reverse(head);
}

void printList(Node *head) {
    Node *curr = head;
    while (curr != nullptr) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

int main() {
  
  	// Create a hard-coded linked list:
    // 1 -> 9 -> 9 -> 9
    Node *head = new Node(1);
    head->next = new Node(9);
    head->next->next = new Node(9);
    head->next->next->next = new Node(9);

    head = addOne(head);
  
    printList(head);

    return 0;
}