
//Implement "N" stacks in an Array
#include <iostream>
using namespace std;

class kStacks {
    
    // main array to store elements
    int *arr;

    // array to store indexes of top elements of stacks
    int *top;

    // array to store next entry (for free list and stack links)
    int *next;

    // beginning index of free list
    int freeTop;

public:
    kStacks(int n, int k) {
        arr = new int[n];
        top = new int[k];
        next = new int[n];

        // initialize tops of all stacks as empty
        for (int i = 0; i < k; i++)
            top[i] = -1;

        // initialize free list
        freeTop = 0;
        for (int i = 0; i < n - 1; i++)
            next[i] = i + 1;
        next[n - 1] = -1;
    }

    // push element x into stack i
    void push(int x, int i) {
        if (freeTop == -1) {
            cout << "Stack Overflow\n";
            return;
        }

        // take index from free list
        int index = freeTop;     
        
        // update free list
        freeTop = next[index];
        
        // put element in array
        arr[index] = x;          
        
        // link new element to previous top
        next[index] = top[i];    
        
        // update top of stack
        top[i] = index;          
    }

    // pop element from stack i
    int pop(int i) {
        if (top[i] == -1) {
            cout << "Stack Underflow\n";
            return -1;
        }

        // get top index
        int index = top[i];      
        
        // update top to next element
        top[i] = next[index];    

        // add index back to free list
        next[index] = freeTop;   
        freeTop = index;

        // return popped element
        return arr[index];       
    }
};

int main() {
    int n = 9, k = 3;
    kStacks st(n, k);

    // Each query has the following format:
    // 1. Push operation → {1, value, stackNumber}
    // 2. Pop operation  → {2, stackNumber}
    int operations[][3] = {
        {1, 10, 1},
        {1, 20, 1},
        {1, 30, 1},
        {1, 100, 0},
        {1, 200, 0},
        {2, 1},
        {2, 1},
        {2, 0},
        {1, 2, 2}
    };
    
    int op = sizeof(operations) / sizeof(operations[0]);
    
    for (int i = 0; i < op; i++) {
        if (operations[i][0] == 1) {
            int x = operations[i][1], m = operations[i][2];
            st.push(x, m);
        } else if (operations[i][0] == 2) {
            int m = operations[i][1];
            int res = st.pop(m);
            if (res != -1)
                cout << "Popped Element: " << res << endl;
        }
    }

    return 0;
}
