
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int x) {
        data = x;
        prev = nullptr;
        next = nullptr;
    }
};

// Function to rotate the doubly-linked list
Node* rotateDLL(Node* head, int p) {

    Node* curr = head;

    // Traverse to the p-th node
    for (int i = 1; i < p; i++) {
        curr = curr->next;
    }

    if (!curr || !curr->next) return head;

    // Update pointers to perform the rotation
    Node* newHead = curr->next;
    newHead->prev = nullptr;
    curr->next = nullptr;

    Node* tail = newHead;
    while (tail->next) {
        tail = tail->next;
    }

    // Connect the old tail to the old head
    tail->next = head;
    head->prev = tail;

    return newHead;
}

void printList(Node* head) {
    Node* curr = head;
    while (curr) {
        cout << curr->data;
        if (curr->next) cout << " ";
        curr = curr->next;
    }
    cout << endl;
}

int main() {
  
    Node* head = new Node(2);
    head->next = new Node(6);
    head->next->prev = head;
    head->next->next = new Node(5);
    head->next->next->prev = head->next;
    head->next->next->next = new Node(4);
    head->next->next->next->prev = head->next->next;

    int p = 3;
    head = rotateDLL(head, p);
    printList(head);

    return 0;
}