//Next Smaller Element
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> nextSmallerEle(vector<int>& arr) {
    int n = arr.size();
   
    // initialize all NSEs as -1
    vector<int> result(n, -1); 
    
    stack<int> st; 

    // traverse the array from right to left
    for (int i = n - 1; i >= 0; i--) {
        
        // pop elements from stack which are >= current element
        while (!st.empty() && st.top() >= arr[i]) {
            st.pop();
        }

        // if stack is not empty, top element is NSE
        if (!st.empty()) {
            result[i] = st.top();
        }

        // push current element onto stack
        st.push(arr[i]);
    }

    return result;
}

int main() {
    vector<int> arr = {4, 8, 5, 2, 25};
    vector<int> nse = nextSmallerEle(arr);

    for (int x : nse) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}