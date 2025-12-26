#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int x) : data(x), left(NULL), right(NULL) {}
};

int diameterUtil(Node* root, int &ans) {
    if (!root) return 0;
    int l = diameterUtil(root->left, ans);
    int r = diameterUtil(root->right, ans);
    ans = max(ans, l + r);
    return 1 + max(l, r);
}

int diameter(Node* root) {
    int ans = 0;
    diameterUtil(root, ans);
    return ans;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    cout << diameter(root);
    return 0;
}
