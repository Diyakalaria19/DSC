

#include <bits/stdc++.h>
using namespace std;

// Singly Linked List Node
struct Node {
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

// 1. Print Linked List
void printList(Node* head) {
    Node* temp = head;
    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// 2. Reverse a Linked List
Node* reverseList(Node* head) {
    Node* prev = NULL;
    Node* cur = head;
    while(cur != NULL) {
        Node* nextNode = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nextNode;
    }
    return prev;
}

// 3. Find Middle of Linked List
Node* findMiddle(Node* head) {
    Node* slow = head;
    Node* fast = head;
    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

// 4. Check if Linked List is Palindrome
bool isPalindrome(Node* head) {
    vector<int> vals;
    Node* temp = head;
    while(temp != NULL) {
        vals.push_back(temp->data);
        temp = temp->next;
    }
    int i = 0, j = vals.size() - 1;
    while(i < j) {
        if(vals[i] != vals[j]) return false;
        i++; j--;
    }
    return true;
}

// 5. Detect Loop in Linked List
bool detectLoop(Node* head) {
    Node* slow = head;
    Node* fast = head;
    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) return true;
    }
    return false;
}

// 6. Add 1 to a Number Represented as Linked List
Node* addOne(Node* head) {
    head = reverseList(head);
    Node* temp = head;
    int carry = 1;
    while(temp != NULL && carry) {
        int sum = temp->data + carry;
        temp->data = sum % 10;
        carry = sum / 10;
        if(temp->next == NULL && carry)
            temp->next = new Node(0);
        temp = temp->next;
    }
    return reverseList(head);
}

// 7. Intersection of Two Sorted Linked Lists
Node* intersectionSorted(Node* head1, Node* head2) {
    Node* dummy = new Node(-1);
    Node* tail = dummy;
    while(head1 != NULL && head2 != NULL) {
        if(head1->data == head2->data) {
            tail->next = new Node(head1->data);
            tail = tail->next;
            head1 = head1->next;
            head2 = head2->next;
        } else if(head1->data < head2->data)
            head1 = head1->next;
        else
            head2 = head2->next;
    }
    return dummy->next;
}

// 8. Intersection Point of Two Linked Lists
Node* getIntersectionNode(Node* head1, Node* head2) {
    Node* a = head1;
    Node* b = head2;
    while(a != b) {
        a = (a == NULL) ? head2 : a->next;
        b = (b == NULL) ? head1 : b->next;
    }
    return a;
}

// 9. Remove Loop from Linked List
void removeLoop(Node* head) {
    if(head == NULL) return;
    Node* slow = head;
    Node* fast = head;
    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) break;
    }
    if(slow != fast) return;
    slow = head;
    while(slow->next != fast->next) {
        slow = slow->next;
        fast = fast->next;
    }
    fast->next = NULL;
}

// 10. Move Last Element to Front
Node* moveLastToFront(Node* head) {
    if(head == NULL || head->next == NULL) return head;
    Node* secLast = NULL;
    Node* last = head;
    while(last->next != NULL) {
        secLast = last;
        last = last->next;
    }
    secLast->next = NULL;
    last->next = head;
    return last;
}
