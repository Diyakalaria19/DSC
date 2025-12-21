//15 questions 



#include <bits/stdc++.h>
using namespace std;

// 1. Implement Queue using Array
class MyQueue {
    int arr[100];
    int front, rear;
public:
    MyQueue() {
        front = 0;
        rear = 0;
    }
    void push(int x) {
        if(rear==100) {
            cout<<"Queue Full"<< endl;
            return;
        }
        arr[rear++] = x;
    }
    void pop() {
        if(front== rear) {
            cout<<"Queue Empty"<<endl;
            return;
        }
        front++;
    }
    int peek() {
        if(front == rear){
             return -1;
        }
        return arr[front];
    }
};

// 2. Implement Circular Queue
class CircularQueue {
    int arr[100];
    int front, rear, size;
public:
    CircularQueue() {
        front = -1;
        rear = -1;
        size = 100;
    }
    bool isFull() {
        return (front == (rear + 1) % size);
    }
    bool isEmpty() {
        return front == -1;
    }
    void enqueue(int x) {
        if(isFull()) {
            cout << "Queue Full" << endl;
            return;
        }
        if(front == -1){
             front = 0;
        }
        rear = (rear + 1) % size;
        arr[rear] = x;
    }

    void dequeue() {
        if(isEmpty()) {
            cout<<"Queue Empty"<<endl;
            return;
        }
        if(front == rear){
            front = rear = -1;
        } else{
            front = (front + 1) % size;
        }
    }
};

// 3. Implement Queue using Stack
class QueueUsingStack {
    stack<int> st1, st2;
public:
    void push(int x) {
        st1.push(x);
    }
    int pop() {
        if(st1.empty() && st2.empty()){
             return -1;
        }
        if(st2.empty()) {
            while(!st1.empty()) {
                st2.push(st1.top());
                st1.pop();
            }
        }
        int val = st2.top();
        st2.pop();
        return val;
    }
};

// 4. Reverse a Queue
void reverseQueue(queue<int>& q) {
    stack<int> st;
    while(!q.empty()) {
        st.push(q.front());
        q.pop();
    }
    while(!st.empty()) {
        q.push(st.top());
        st.pop();
    }
}

// 5. Reverse First K Elements of Queue
void reverseFirstK(queue<int>& q, int k) {
    stack<int> st;
    for(int i=0; i<k;i++){
        st.push(q.front());
        q.pop();
    }
    while(!st.empty()){
        q.push(st.top());
        st.pop();
    }
    int rem = q.size() - k;
    while(rem--){
        q.push(q.front());
        q.pop();
    }
}

// 6. Interleave First Half with Second Half
void interleaveQueue(queue<int>& q) {
    int n = q.size();
    queue<int> q2;

    for(int i = 0; i<n/2; i++){
        q2.push(q.front());
        q.pop();
    }
    while(!q2.empty()) {
        q.push(q2.front());
        q2.pop();
        q.push(q.front());
        q.pop();
    }
}

// 7. First Negative Integer in Every Window of Size K
vector<int> firstNegative(vector<int>& arr, int k) {
    deque<int> dq;
    vector<int> res;

    for(int i = 0; i <arr.size();i++) {
        if(arr[i]<0)
            dq.push_back(i);

        if(i >= k - 1){
            while(!dq.empty() && dq.front() <= i - k){
                dq.pop_front();
            }
            if(dq.empty()){
                 res.push_back(0);
            }
            else{
                res.push_back(arr[dq.front()]);
            } 
        }
    }
    return res;
}

// 8. First Non-Repeating Character in a Stream
string firstNonRepeating(string s) {
    queue<char> q;
    unordered_map<char, int> freq;
    string res = "";

    for(char c : s) {
        freq[c]++;
        q.push(c);
        while(!q.empty() && freq[q.front()] > 1){
            q.pop();
        }
        if(q.empty()){
             res = res+ '#';
        }
        else{
        res = res + q.front();
        }
    }
    return res;
}

// 9. Rotten Oranges Problem
int rottenOranges(vector<vector<int>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();
    queue<pair<int,int>> q;
    int fresh = 0, time = 0;

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            if(grid[i][j] == 2) q.push({i, j});
            else if(grid[i][j] == 1) fresh++;
        }
    }

    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};

    while(!q.empty() && fresh > 0) {
        int sz = q.size();
        while(sz--) {
            auto cur = q.front(); q.pop();
            for(int d = 0; d < 4; d++) {
                int ni = cur.first + dx[d];
                int nj = cur.second + dy[d];
                if(ni >= 0 && nj >= 0 && ni < rows && nj < cols && grid[ni][nj] == 1) {
                    grid[ni][nj] = 2;
                    fresh--;
                    q.push({ni, nj});
                }
            }
        }
        time++;
    }
    if(fresh > 0) return -1;
    return time;
}



// ===================== QUEUE (NEXT 5 EASY) =====================

// 6. Implement Stack using Deque
class StackUsingDeque {
    deque<int> dq;
public:
    void push(int x) {
        dq.push_back(x);
    }

    void pop() {
        if(!dq.empty()) dq.pop_back();
    }

    int top() {
        if(dq.empty()) return -1;
        return dq.back();
    }
};

// 7. Implement Queue using Deque
class QueueUsingDeque {
    deque<int> dq;
public:
    void push(int x) {
        dq.push_back(x);
    }

    void pop() {
        if(!dq.empty()) dq.pop_front();
    }

    int front() {
        if(dq.empty()) return -1;
        return dq.front();
    }
};

// 8. Reverse Queue Using Recursion
void reverseQueueRec(queue<int>& q) {
    if(q.empty()) return;
    int x = q.front();
    q.pop();
    reverseQueueRec(q);
    q.push(x);
}

// 9. First Circular Tour (Petrol Pump)
int circularTour(vector<int>& petrol, vector<int>& dist) {
    int balance = 0, deficit = 0, start = 0;
    for(int i = 0; i < petrol.size(); i++) {
        balance += petrol[i] - dist[i];
        if(balance < 0) {
            deficit += balance;
            start = i + 1;
            balance = 0;
        }
    }
    return (balance + deficit >= 0) ? start : -1;
}

// 10. Sum of Min and Max of All Subarrays of Size K
int sumMinMax(vector<int>& arr, int k) {
    deque<int> maxi, mini;
    int sum = 0;

    for(int i = 0; i < arr.size(); i++) {
        while(!maxi.empty() && arr[maxi.back()] <= arr[i]) maxi.pop_back();
        while(!mini.empty() && arr[mini.back()] >= arr[i]) mini.pop_back();

        maxi.push_back(i);
        mini.push_back(i);

        if(i >= k - 1) {
            if(maxi.front() <= i - k) maxi.pop_front();
            if(mini.front() <= i - k) mini.pop_front();
            sum += arr[maxi.front()] + arr[mini.front()];
        }
    }
    return sum;
}
