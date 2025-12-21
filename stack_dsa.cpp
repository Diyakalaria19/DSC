//15 questions


#include <bits/stdc++.h>
using namespace std;

// 1. Implement Stack using Array
class MyStack {
    int arr[100];
    int top;
public:
    MyStack() {
        top = -1;
    }
    void push(int x) {
        if(top == 99) {
            cout << "Stack Overflow" << endl;
            return;
        }
        arr[++top] = x;
    }
    void pop() {
        if(top == -1) {
            cout << "Stack Underflow" << endl;
            return;
        }
        top--;
    }
    int peek() {
        if(top == -1){
             return -1;
        }
        return arr[top];
    }
};

// 2. Reverse a String using Stack
string reverseString(string s) {
    stack<char> st;
    for(char c : s)
        st.push(c);

    for(int i = 0; i < s.length(); i++) {
        s[i] = st.top();
        st.pop();
    }
    return s;
}

// 3. Check for Balanced Parentheses
bool isBalanced(string s) {
    stack<char> st;
    for(char c : s) {
        if(c == '(' || c == '{'|| c =='[')
            st.push(c);
        else {
            if(st.empty()){
                 return false;
            }
            char topChar = st.top();
            if((c == ')' && topChar == '(') ||
               (c == '}' && topChar == '{') ||
               (c == ']' && topChar == '[')){
                st.pop();
               }
            else{
                return false;
            }
        }
    }
    return st.empty();
}

// 4. Next Greater Element
vector<int> nextGreater(vector<int>& arr) {
    stack<int> st;
    vector<int> res(arr.size(), -1);

    for(int i = arr.size()-1; i >= 0; i--) {
        while(!st.empty() && st.top() <= arr[i])
            st.pop();
        if(!st.empty()) res[i] = st.top();
        st.push(arr[i]);
    }
    return res;
}

// 5. Evaluate Postfix Expression
int evaluatePostfix(string s) {
    stack<int> st;
    for(char c : s) {
        if(isdigit(c))
            st.push(c - '0');
        else {
            int b = st.top(); st.pop();
            int a = st.top(); st.pop();
            if(c == '+'){
                 st.push(a + b);
            }
            else if(c == '-'){
                 st.push(a - b);
            }
            else if(c == '*'){
                 st.push(a * b);
            }
            else if(c == '/'){
                 st.push(a / b);
            }
        }
    }
    return st.top();
}

// 6. Find Middle Element of Stack
int findMiddle(stack<int> st) {
    int mid = st.size() / 2;
    while(mid--){
         st.pop();
    }
    return st.top();
}

// 7. Insert Element at Bottom of Stack (Recursion)
void insertAtBottom(stack<int>& st, int x) {
    if(st.empty()) {
        st.push(x);
        return;
    }
    int temp = st.top();
    st.pop();
    insertAtBottom(st, x);
    st.push(temp);
}

// 8. Reverse a Stack using Recursion
void reverseStack(stack<int>& st) {
    if(st.empty()){
         return;
    }
    int temp = st.top();
    st.pop();
    reverseStack(st);
    insertAtBottom(st,temp);
}

// 9. Sort a Stack using Recursion
void sortedInsert(stack<int>& st, int x) {
    if(st.empty()||st.top()<=x) {
        st.push(x);
        return;
    }
    int temp = st.top();
    st.pop();
    sortedInsert(st,x);
    st.push(temp);
}

void sortStack(stack<int>& st) {
    if(st.empty()){
         return;
    }
    int temp = st.top();
    st.pop();
    sortStack(st);
    sortedInsert(st,temp);
}

// 10. Check Redundant Brackets
bool redundantBrackets(string s) {
    stack<char> st;
    for(char c : s) {
        if(c == ')') {
            char topChar = st.top();
            st.pop();
            bool hasOp = false;
            while(topChar != '(') {
                if(topChar == '+' || topChar == '-' ||
                   topChar == '*' || topChar == '/'){
                    hasOp = true;
                   }
                topChar = st.top();
                st.pop();
            }
            if(!hasOp) return true;
        } else {
            st.push(c);
        }
    }
    return false;
}



// NEXT EASY STACK & QUEUE QUESTIONS
// Very simple, human-written C++ solutions
// Easy logic, interview friendly

#include <bits/stdc++.h>
using namespace std;

// ===================== STACK (NEXT 5 EASY) =====================

// 1. Implement Two Stacks in One Array
class TwoStacks {
    int *arr;
    int top1, top2, size;
public:
    TwoStacks(int n) {
        size = n;
        arr = new int[n];
        top1 = -1;
        top2 = n;
    }

    void push1(int x) {
        if(top1 + 1 < top2)
            arr[++top1] = x;
    }

    void push2(int x) {
        if(top1 + 1 < top2)
            arr[--top2] = x;
    }

    int pop1() {
        if(top1 >= 0) return arr[top1--];
        return -1;
    }

    int pop2() {
        if(top2 < size) return arr[top2++];
        return -1;
    }
};

// 2. Stack using Queue
class StackUsingQueue {
    queue<int> q;
public:
    void push(int x) {
        q.push(x);
        int sz = q.size();
        while(sz-- > 1) {
            q.push(q.front());
            q.pop();
        }
    }

    int pop() {
        if(q.empty()) return -1;
        int val = q.front();
        q.pop();
        return val;
    }
};

// 3. Find Minimum Element in Stack (Using Extra Stack)
class MinStack {
    stack<int> st, minSt;
public:
    void push(int x) {
        st.push(x);
        if(minSt.empty() || x <= minSt.top())
            minSt.push(x);
    }

    void pop() {
        if(st.top() == minSt.top())
            minSt.pop();
        st.pop();
    }

    int getMin() {
        if(minSt.empty()) return -1;
        return minSt.top();
    }
};

// 4. Check Stack Permutation
bool isStackPermutation(vector<int>& a, vector<int>& b) {
    stack<int> st;
    int j = 0;
    for(int i = 0; i < a.size(); i++) {
        st.push(a[i]);
        while(!st.empty() && st.top() == b[j]) {
            st.pop();
            j++;
        }
    }
    return st.empty();
}

// 5. Next Smaller Element
vector<int> nextSmaller(vector<int>& arr) {
    stack<int> st;
    vector<int> res(arr.size(), -1);

    for(int i = arr.size()-1; i >= 0; i--) {
        while(!st.empty() && st.top() >= arr[i])
            st.pop();
        if(!st.empty()) res[i] = st.top();
        st.push(arr[i]);
    }
    return res;
}

