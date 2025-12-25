
//Design a Stack that supports getMin() in O(1) time and O(1) extra space.
#include <iostream>
#include <stack>
using namespace std;

class SpecialStack {
private:
    stack<int> st;
    int minEle;
    
public:
    SpecialStack() {
        minEle = -1;
    }
    
    // Add an element to the top of stack
    void push(int x) {
        if (st.empty()) {
            minEle = x;
            st.push(x);
        }
        // If new number is less than minEle
        else if (x < minEle) {
            st.push(2 * x - minEle);
            minEle = x;
        }
        else {
            st.push(x);
        }
    }
    
    // Remove the top element from the stack
    void pop() {
        if (st.empty()) return;
        
        int top = st.top();
        st.pop();
        
        // Minimum will change if min element is removed
        if (top < minEle) {
            minEle = 2 * minEle - top;
        }
    }
    
    // Return top element of the stack
    int peek() {
        if (st.empty()) return -1;

        int top = st.top();
        return (minEle > top) ? minEle : top;
    }
    
    // Return minimum element of the stack
    int getMin() {
        if (st.empty()) return -1;
        return minEle;
    }
};

int main() {
    SpecialStack st;
    
    st.push(2);
    st.push(3);
    cout << st.peek() << " ";
    st.pop();
    cout << st.getMin() << " ";
    st.push(1);
    cout << st.getMin() << " ";
}
