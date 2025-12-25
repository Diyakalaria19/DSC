//Implement a method to insert an element at its bottom without using any other data structure.
#include <iostream>
#include <stack>
using namespace std;

void insertAtBottom(stack<int> s, int x)
{
    stack<int> temp;

    while (!s.empty()) {
        temp.push(s.top());
        s.pop();
    }

    s.push(x);

    while (!temp.empty()) {
        s.push(temp.top());
        temp.pop();
    }

    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
}

int main()
{
    stack<int> s;
    s.push(5);
    s.push(4);
    s.push(3);
    s.push(2);
    s.push(1);

    int x = 7;

    insertAtBottom(s, x);

    return 0;
}