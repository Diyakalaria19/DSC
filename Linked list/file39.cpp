//Check if a linked list is a circular linked list.
// C++ program to check if linked list is circular
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

// This function returns true if given linked
//  list is circular, else false.
bool isCircular(Node *head)
{

    // If the head is null, the linked list is empty,
    // so it is circular
    if (!head)
        return true;

    // Traverse the linked list until either the end
    // is reached or the next node is equal to the head
    Node *curr = head;
    while (curr && curr->next != head)
        curr = curr->next;

    // If the end is reached before finding
    // the head again, the linked list is not circular
    if (!curr)
        return false;

    // If the head is found again before reaching
    // the end, the linked list is circular
    return true;
}

int main()
{
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);

    isCircular(head) ? cout << "Yes\n" : cout << "No\n";

    // Making linked list circular
    head->next->next->next->next = head;

    isCircular(head) ? cout << "Yes\n" : cout << "No\n";

    return 0;
}