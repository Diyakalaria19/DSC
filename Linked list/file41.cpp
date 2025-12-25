
//Write a Program to check whether the Singly Linked list is a palindrome or not.
#include <iostream>
#include <stack>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int d) { 
        data = d; 
        next = nullptr;
    }
};

// Function to check if the linked list 
// is palindrome or not
bool isPalindrome(Node* head) {
    Node* currNode = head;

    // Declare a stack
    stack<int> s;

    // Push all elements of the list to the stack
    while (currNode != nullptr) {
        s.push(currNode->data);
        currNode = currNode->next;
    }

    // Iterate in the list again and check by
  	// popping from the stack
    while (head != nullptr) {
      
        // Get the topmost element
        int c = s.top();
        s.pop();

        // Check if data is not same as popped element
        if (head->data != c) {
            return false;
        }

        // Move ahead
        head = head->next;
    }

    return true;
}

int main() {
  
    // Linked list : 1->2->3->2->1
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(2);
    head->next->next->next->next = new Node(1);

    bool result = isPalindrome(head);

    if (result)
        cout << "true\n";
    else
        cout << "false\n";

    return 0;
}
