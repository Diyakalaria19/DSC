#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

void topView(Node* root) {
    if (root == NULL) return;

    map<int, int> mp;
    queue<pair<Node*, int>> q;

    q.push(make_pair(root, 0));

    while (!q.empty()) {
        pair<Node*, int> temp = q.front();
        q.pop();

        Node* node = temp.first;
        int hd = temp.second;

        if (mp.find(hd) == mp.end())
            mp[hd] = node->data;

        if (node->left)
            q.push(make_pair(node->left, hd - 1));

        if (node->right)
            q.push(make_pair(node->right, hd + 1));
    }

    for (auto it = mp.begin(); it != mp.end(); it++)
        cout << it->second << " ";
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root->left->right->right = new Node(5);
    root->left->right->right->right = new Node(6);

    topView(root);
    return 0;
}
