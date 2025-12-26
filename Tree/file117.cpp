#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int x) : data(x), left(NULL), right(NULL) {}
};

void leftView(Node* root) {
    if (!root) return;
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int n = q.size();
        for (int i = 1; i <= n; i++) {
            Node* cur = q.front(); q.pop();
            if (i == 1) cout << cur->data << " ";
            if (cur->left) q.push(cur->left);
            if (cur->right) q.push(cur->right);
        }
    }
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    leftView(root);
    return 0;
}
