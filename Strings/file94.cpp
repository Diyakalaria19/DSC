//Word Wrap Problem [VERY IMP].
// C++ program to minimize the cost to
// wrap the words.

#include <bits/stdc++.h>
using namespace std;

int calculateCost(int curr, int n, vector<int> &arr,
                  int k, vector<int> &memo) {

	// Base case: If current index is beyond or at
	// the last word, no cost
	if (curr >= n)
		return 0;

	if (memo[curr] != -1)
		return memo[curr];

	// Keeps track of the current line's total character
	// count
	int sum = 0;

	// Initialize with a large value to find the minimum cost
	int ans = INT_MAX;

	// Try placing words from the current position to the next
	for (int i = curr; i < n; i++) {

		// Add the length of the current word
		sum += arr[i];

		// Including spaces between words
		int tot = sum + (i - curr);

		// If the total exceeds the line width,
		// break out of the loop
		if (tot > k)
			break;

		// If this is not the last word in the array, compute
		// the cost for the next line
		if (i != n - 1) {
			int temp = (k - tot) * (k - tot) +
			           calculateCost(i + 1, n, arr, k, memo);
			ans = min(ans, temp);
		}
		else {

			// If it's the last word, there's no cost added
			ans = 0;
		}
	}

	return memo[curr] = ans;
}

int solveWordWrap(vector<int> &arr, int k) {
	int n = arr.size();
	vector<int> memo(n, -1);
	return calculateCost(0, n, arr, k, memo);
}

int main() {
	int k = 6;
	vector<int> arr = {3, 2, 2, 5};
	int res =  solveWordWrap(arr, k);
	cout << res << endl;
	return 0;
}