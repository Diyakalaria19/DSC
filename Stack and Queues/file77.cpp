//Interleave the first half of the queue with second half
#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void rearrangeQueue(queue<int>& q){

    stack<int> s;
    int halfSize = q.size() / 2;

    // Push first half elements into the stack
    for (int i = 0; i < halfSize; i++) {
        s.push(q.front());
        q.pop();
    }

    // enqueue back the stack elements
    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }

    // dequeue the first half elements of
    // queue and enqueue them back
    for (int i = 0; i < halfSize; i++) {
        q.push(q.front());
        q.pop();
    }

    // Again push the first half elements into the stack
    for (int i = 0; i < halfSize; i++) {
        s.push(q.front());
        q.pop();
    }

    // interleave the elements of queue and stack
    while (!s.empty()) {
        q.push(s.top());
        s.pop();
        q.push(q.front());
        q.pop();
    }
}

int main() {
    
    queue<int> q;
    q.push(2);
    q.push(4);
    q.push(3);
    q.push(1);
    rearrangeQueue(q);
    int length = q.size();
    for (int i = 0; i < length; i++) {
        cout << q.front() << " ";
        q.pop();
    }
    return 0;
}