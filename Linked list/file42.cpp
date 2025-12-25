//Deletion from a Circular Linked List.
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int value) {
        data = value;
        next = nullptr;
    }
};

Node* deleteLastNode(Node* last) {
    if (last == nullptr) {
        return nullptr;
    }
    Node* head = last->next;

    // If there is only one node in the list
    if (head == last) {
        delete last;
        last = nullptr;
        return last;
    }
    // Traverse the list to find the second last node
    Node* curr = head;
    while (curr->next != last) {
        curr = curr->next;
    }
    // Update the second last node's next pointer
    // to point to head
    curr->next = head;
    delete last;
    last = curr;

    return last;
}

void printList(Node* last) {
    if(last == NULL) return ;
 
    Node *head = last->next;
    while (true){
        
        cout << head->data;
        
        head = head->next;
        if (head == last->next) break;
        
        cout << " <-> ";
    }
    cout << endl;
}

int main() {
    Node* first = new Node(2);
    first->next = new Node(3);
    first->next->next = new Node(4);

    Node* last = first->next->next;
    last->next = first;

    last = deleteLastNode(last);

    printList(last);

    return 0;
}