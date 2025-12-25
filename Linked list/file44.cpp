//Find pairs with a given sum in a DLL.

#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node *next, *prev;

    Node(int value) {
        data = value;
        next = nullptr;
        prev = nullptr;
    }
};


vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target) {

    vector<pair<int, int>> res;

    Node *first = head;
    Node *second = head;

    // Move second to the end of the DLL
    while (second->next != nullptr)
        second = second->next;

    bool found = false;

    // The loop terminates when two pointers
    // cross each other (second->next == first),
    // or they become the same (first == second)
    while (first != second && second->next != first) {

        // If the sum of the two nodes is equal to x, print the pair
        if ((first->data + second->data) == target) {
            found = true;
            res.push_back({first->data, second->data});

            // Move first in forward direction
            first = first->next;

            // Move second in backward direction
            second = second->prev;
        }
        else {
            if ((first->data + second->data) < target)
                first = first->next;
            else
                second = second->prev;
        }
    }

    // If no pair is found
    return res;
}

int main() {

    // Create a doubly linked list: 1 <-> 2 <-> 4 <-> 5
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->prev = head;
    head->next->next = new Node(4);
    head->next->next->prev = head->next;
    head->next->next->next = new Node(5);
    head->next->next->next->prev = head->next->next;

    int target = 7;
    vector<pair<int, int>> pairs = findPairsWithGivenSum(head, target);

    if (pairs.empty()) {
        cout << "No pairs found." << endl;
    }
    else {
        for (auto &pair : pairs) {
            cout << pair.first << " " << pair.second << endl;
        }
    }
    return 0;
}