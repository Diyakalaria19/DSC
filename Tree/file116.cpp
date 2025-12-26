#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int x) : data(x), left(NULL), right(NULL) {}
};

void postorderRec(Node* root) {
    if (!root) return;
    postorderRec(root->left);
    postorderRec(root->right);
    cout << root->data << " ";
}

void postorderIter(Node* root) {
    stack<Node*> st1, st2;
    st1.push(root);
    while (!st1.empty()) {
        Node* cur = st1.top(); st1.pop();
        st2.push(cur);
        if (cur->left) st1.push(cur->left);
        if (cur->right) st1.push(cur->right);
    }
    while (!st2.empty()) {
        cout << st2.top()->data << " ";
        st2.pop();
    }
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    postorderRec(root);
    cout << endl;
    postorderIter(root);
    return 0;
}
