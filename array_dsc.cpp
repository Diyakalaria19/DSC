//15 questions


#include <bits/stdc++.h>
using namespace std;

// 1. Reverse the array
void reverseArray(vector<int>& arr) {
    int i = 0, rev = arr.size()-1;
    while(i < rev) {
        swap(arr[i], arr[rev]);
        i++; 
        rev--;
    }
}

// 2. Find max and min in array
void findMaxMin(vector<int>& arr) {
    int max = arr[0], min = arr[0];
    for(int i = 1; i<arr.size(); i++) {
        if(arr[i] > max) 
        {
            max = arr[i];
        }
        if(arr[i] < min){
            min = arr[i];
        } 
    }
    cout<<"Max: "<< max <<" Min: "<<min<<endl;
}

// 3. Kth smallest element
int kthSmallest(vector<int> arr, int k) {
    sort(arr.begin(), arr.end());
    return arr[k-1];
}

// 4. Sort array of 0s,1s,2s
void sort012(vector<int>& arr) {
    int count0 = 0,count1 = 0,count2 = 0;
    for(int x : arr) {
        if(x == 0){
             count0++;
        }
        else if(x == 1){
             count1++;
        }
        else{
            count2++;
        } 
    }
    int idx = 0;
    while(count0--){
        arr[idx++] = 0;
    }
    while(count1--){
         arr[idx++] = 1;
    }
    while(count2--){
         arr[idx++] = 2;
    }
}

// 5. Move negative numbers to one side
void moveNegatives(vector<int>& arr) {
    int j = 0;
    for(int i = 0; i <arr.size(); i++) {
        if(arr[i]<0) {
            swap(arr[i],arr[j]);
            j++;
        }
    }
}

// 6. Union of two arrays
// vector<int> unionArrays(vector<int>& a, vector<int>& b) {
//     set<int> st;
//     for(int x : a) st.insert(x);
//     for(int x : b) st.insert(x);
//     return vector<int>(st.begin(), st.end());
// }

// // 7. Intersection of two arrays
// vector<int> intersectionArrays(vector<int>& a, vector<int>& b) {
//     vector<int> res;
//     sort(a.begin(), a.end());
//     sort(b.begin(), b.end());
//     int i = 0, j = 0;
//     while(i < a.size() && j < b.size()) {
//         if(a[i] == b[j]) {
//             res.push_back(a[i]); i++; j++;
//         } else if(a[i] < b[j]) i++;
//         else j++;
//     }
//     return res;
// }

// 8. Cyclic rotate by one
void rotateByOne(vector<int>& arr) {
    int last = arr.back();
    for(int i = arr.size()-1; i > 0; i--)
        arr[i] = arr[i-1];
    arr[0] =last;
}

// 9. Check if array is subset
bool isSubset(vector<int>& a, vector<int>& b) {
    unordered_set<int> s(a.begin(), a.end());
    for(int x : b)
        if(s.find(x) == s.end()) return false;
    return true;
}

// 10. Chocolate Distribution Problem
int chocolateDistribution(vector<int>& arr, int m) {
    if(m == 0 || arr.size() < m) return 0;
    sort(arr.begin(), arr.end());
    int ans = INT_MAX;
    for(int i = 0; i + m - 1 < arr.size(); i++) {
        ans = min(ans, arr[i+m-1] - arr[i]);
    }
    return ans;
}

// 11. Palindromic array
bool isPalindromicArray(vector<int>& arr) {
    int i = 0, j =arr.size()-1;
    while(i < j) {
        if(arr[i] != arr[j]){
            return false;
        }
        i++; 
        j--;
    }
    return true;
}

// 12. Triplet sum
bool tripletSum(vector<int>& arr, int sum) {
    sort(arr.begin(),arr.end());
    for(int i = 0; i <arr.size(); i++) {
        int l = i+1, r = arr.size()-1;
        while(l<r) {
            int curr =arr[i] +arr[l]+arr[r];
            if(curr == sum){
                return true;
            }
            else if(curr < sum) l++;
            else r--;
        }
    }
    return false;
}

// REMAINING ARRAY & STRING QUESTIONS (from your list)
// Simple, readable, human-written C++ code
// Focus on correctness, not over-optimization

#include <bits/stdc++.h>
using namespace std;

// ===================== ARRAYS =====================

// 1. Kadane's Algorithm (Max Subarray Sum)
int maxSubarraySum(vector<int>& arr) {
    int currSum = 0, maxSum = INT_MIN;
    for(int x : arr) {
        currSum += x;
        maxSum = max(maxSum, currSum);
        if(currSum < 0) currSum = 0;
    }
    return maxSum;
}

// 2. Minimize the Heights
int minimizeHeights(vector<int>& arr, int k) {
    sort(arr.begin(), arr.end());
    int n = arr.size();
    int ans = arr[n-1] - arr[0];

    for(int i = 1; i < n; i++) {
        if(arr[i] - k < 0) continue;
        int mn = min(arr[0] + k, arr[i] - k);
        int mx = max(arr[n-1] - k, arr[i-1] + k);
        ans = min(ans, mx - mn);
    }
    return ans;
}

// 3. Minimum Number of Jumps
int minJumps(vector<int>& arr) {
    if(arr[0] == 0) return -1;
    int maxReach = arr[0], step = arr[0], jump = 1;

    for(int i = 1; i < arr.size(); i++) {
        if(i == arr.size() - 1) return jump;
        maxReach = max(maxReach, i + arr[i]);
        step--;
        if(step == 0) {
            jump++;
            if(i >= maxReach) return -1;
            step = maxReach - i;
        }
    }
    return -1;
}

// 4. Median of Two Sorted Arrays (Different Size)
double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
    vector<int> temp;
    temp.insert(temp.end(), a.begin(), a.end());
    temp.insert(temp.end(), b.begin(), b.end());
    sort(temp.begin(), temp.end());
    int n = temp.size();
    if(n % 2 == 0)
        return (temp[n/2] + temp[n/2 - 1]) / 2.0;
    return temp[n/2];
}

// 5. Maximum Profit by Buying and Selling Stock (At most twice)
int maxProfit(vector<int>& prices) {
    int buy1 = INT_MAX, buy2 = INT_MAX;
    int profit1 = 0, profit2 = 0;

    for(int p : prices) {
        buy1 = min(buy1, p);
        profit1 = max(profit1, p - buy1);
        buy2 = min(buy2, p - profit1);
        profit2 = max(profit2, p - buy2);
    }
    return profit2;
}

