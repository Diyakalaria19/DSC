//Find the first circular tour that visits all Petrol Pumps
#include <iostream>
#include <vector>
using namespace std;

int startStation(vector<int> &gas, vector<int> &cost) {
    int n = gas.size();
    int startIdx = 0;
    
    // Initially tank is empty
    int currGas = 0;
    
    for(int i = 0; i < n; i++) {
        currGas = currGas + gas[i] - cost[i];
        
        // If currGas becomes less than zero, then
        // It's not possible to proceed with this startIdx
        if(currGas < 0) {
            startIdx = i + 1;
            currGas = 0;
        }
    }
    
    
    // Checking if startIdx can be a valid 
    // starting point for the Circular tour
    currGas = 0;
    for(int i = 0; i < n; i++) {
        
        // Circular Index
        int idx = (i + startIdx) % n;
      	currGas = currGas + gas[idx] - cost[idx];
        if(currGas < 0)
            return -1;
    }
    
    return startIdx;
}

int main() {
    vector<int> gas = {4,5,7,4};
    vector<int> cost = {6, 6, 3, 5};
    cout << startStation(gas, cost) << endl;
    return 0;
}