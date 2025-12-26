//reverse level order
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int x) : data(x), left(NULL), right(NULL) {}
};

void reverseLevelOrder(Node* root) {
    if (!root) return;
    queue<Node*> q;
    stack<int> st;
    q.push(root);

    while (!q.empty()) {
        Node* cur = q.front(); q.pop();
        st.push(cur->data);
        if (cur->right) q.push(cur->right);
        if (cur->left) q.push(cur->left);
    }

    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    reverseLevelOrder(root);
    return 0;
}
