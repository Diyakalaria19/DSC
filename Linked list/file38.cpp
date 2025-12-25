//Find the middle Element of a linked list.
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int x) {
        this->data = x;
        this->next = nullptr;
    }
};

int getMiddle(Node* head) {
  
    Node* slowptr = head;
    Node* fastptr = head;

    while (fastptr != NULL && fastptr->next != NULL) {

        // move the fast pointer by two nodes
        fastptr = fastptr->next->next;

        // move the slow pointer by one node
        slowptr = slowptr->next;
    }

    return slowptr->data;
}

int main() {

    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = new Node(50);
    head->next->next->next->next->next = new Node(60);

    cout << getMiddle(head) << endl;

    return 0;
}