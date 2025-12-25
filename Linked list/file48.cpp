//Rotate a Doubly Linked list in group of Given Size

#include <iostream>
using namespace std;

class Node {
  public:
    int data;
    Node *next;
    Node *prev;

    Node(int x) {
        data = x;
        next = nullptr;
        prev = nullptr;
    }
};

// Helper function to reverse K nodes iteratively
Node *reverseKGroup(Node *head, int k) {
    if (head == nullptr) {
        return head;
    }

    Node *curr = head;
    Node *newHead = nullptr;
    Node *tail = nullptr;

    while (curr != nullptr) {
        Node *groupHead = curr;
        Node *prev = nullptr;
        Node *next = nullptr;
        int count = 0;

        // Reverse the nodes in the current group
        while (curr != nullptr && count < k) {
            next = curr->next;
            curr->next = prev;
            curr->prev = nullptr;
            if (prev != nullptr) {
                prev->prev = curr;
            }
            prev = curr;
            curr = next;
            count++;
        }

        // If newHead is null, set it to the
      	// last node of the first group
        if (newHead == nullptr) {
            newHead = prev;
        }

        // Connect the previous group to the 
      	// current reversed group
        if (tail != nullptr) {
            tail->next = prev;
            prev->prev = tail;
        }

        // Move tail to the end of the reversed group
        tail = groupHead;
    }

    return newHead;
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
    
    // Creating a sample doubly linked list:
    // 1 <-> 2 <-> 3 <-> 4 <-> 5 <-> 6
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->prev = head;
    head->next->next = new Node(3);
    head->next->next->prev = head->next;
    head->next->next->next = new Node(4);
    head->next->next->next->prev = head->next->next;
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->prev = head->next->next->next;
    head->next->next->next->next->next = new Node(6);
    head->next->next->next->next->next->prev = head->next->next->next->next;

    head = reverseKGroup(head, 2);
    printList(head);

    return 0;
}