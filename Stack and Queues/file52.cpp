//find the middle element of a stack
#include <bits/stdc++.h>
using namespace std;

class myStack {
    stack<int> s;
    deque<int> dq;

public:
    void push(int data) {
        dq.push_back(data);
        if (dq.size() > s.size() + 1) {
            int temp = dq.front();
            dq.pop_front();
            s.push(temp);
        }
    }

    int pop() {
        int data = dq.back();
        dq.pop_back();
        if (s.size() > dq.size()) {
            int temp = s.top();
            s.pop();
            dq.push_front(temp);
        }
        return data;
    }

    int findMiddle() { 
        return dq.front(); 
    }

    void deleteMiddle() {
        dq.pop_front();
        if (s.size() > dq.size()) {
            int temp = s.top();
            s.pop();
            dq.push_front(temp);
        }
    }
};

int main() {
    myStack s;
    s.push(1);
    s.push(2);
    cout << s.findMiddle() << " ";
    s.deleteMiddle();
    cout << s.pop();
    return 0;
}