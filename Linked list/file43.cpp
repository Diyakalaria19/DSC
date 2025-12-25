//Reverse a Doubly Linked list.
#include <iostream>
using namespace std;

class Node {
  public:
    int data;
    Node *next;
    Node *prev;
    Node(int new_data) {
        data = new_data;
        next = NULL;
        prev = NULL;
    }
};

Node *reverse(Node *head) {

    // If the list is empty or has only one node,
  	// return the head as is
    if (head == nullptr || head->next == nullptr)
        return head;

    Node *prevNode = NULL;
    Node *currNode = head;

    // Traverse the list and reverse the links
    while (currNode != nullptr) {
      
      	// Swap the next and prev pointers
        prevNode = currNode->prev;
        currNode->prev = currNode->next;
        currNode->next = prevNode;
      
      	// Move to the next node in the original list 
      	// (which is now previous due to reversal)
        currNode = currNode->prev;
    }

    return prevNode->prev;
}

void printList(Node *node) {
    while (node != nullptr) {
        cout << node->data;
        if(node->next != nullptr){
            cout << " <-> ";
        }
        node = node->next;
    }
    cout << endl;
}

int main() {
  
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->prev = head;
    head->next->next = new Node(3);
    head->next->next->prev = head->next;
   
    head = reverse(head);
    printList(head);
    return 0;
}