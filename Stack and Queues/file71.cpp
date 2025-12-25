//Implement Queue using Stack  
#include <iostream>
#include <stack>
using namespace std;

class myQueue {
private:

     // single stack for queue elements
    stack<int> s;  

public:

    // Enqueue an item to the queue
    void enqueue(int x) {
        s.push(x);
    }

    // Dequeue an item from the queue 
    void dequeue() {
        if (s.empty()) {
            cout << "Queue Underflow\n";
            return;
        }

        int x = s.top();
        s.pop();

        // If this is the last element (bottom), return it
        if (s.empty())
            return;

        // Recursive call to pop remaining elements
        dequeue();

        // Push current element back
        s.push(x);

        return;
    }

    // Return the front element without removing it 
    int front() {
        if (s.empty()) {
            cout << "Queue is empty\n";
            return -1;
        }

        int x = s.top();
        s.pop();

        if (s.empty()) {
            s.push(x);  
            return x;
        }

        int item = front();  
        s.push(x);
        return item;
    }

    // Return the current size of the queue 
    int size() {
        return s.size();
    }
};

int main() {
    myQueue q;

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    cout << "Front: " << q.front() << endl;   
    cout << "Size: " << q.size() << endl;     

    q.dequeue(); 
    cout << "Front: " << q.front() << endl;     
    cout << "Size: " << q.size() << endl;       

    return 0;
}