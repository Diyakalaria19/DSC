//preorder
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int x) : data(x), left(NULL), right(NULL) {}
};

void preorderRec(Node* root) {
    if (!root) return;
    cout << root->data << " ";
    preorderRec(root->left);
    preorderRec(root->right);
}

void preorderIter(Node* root) {
    stack<Node*> st;
    st.push(root);
    while (!st.empty()) {
        Node* cur = st.top(); st.pop();
        cout << cur->data << " ";
        if (cur->right) st.push(cur->right);
        if (cur->left) st.push(cur->left);
    }
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    preorderRec(root);
    cout << endl;
    preorderIter(root);
    return 0;
}
