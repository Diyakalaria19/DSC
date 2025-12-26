//inorder
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int x) : data(x), left(NULL), right(NULL) {}
};

void inorderRec(Node* root) {
    if (!root) return;
    inorderRec(root->left);
    cout << root->data << " ";
    inorderRec(root->right);
}

void inorderIter(Node* root) {
    stack<Node*> st;
    Node* cur = root;
    while (cur || !st.empty()) {
        while (cur) {
            st.push(cur);
            cur = cur->left;
        }
        cur = st.top(); st.pop();
        cout << cur->data << " ";
        cur = cur->right;
    }
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    inorderRec(root);
    cout << endl;
    inorderIter(root);
    return 0;
}
