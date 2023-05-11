// Implement the knapsack problem using dynamic programming in C++
// Analyze the time and space complexity of your implementation and compare it with the
// time and space complexity of a greedy algorithm.

#include <iostream>
#include <vector>

using namespace std;

int knapsack(int W, vector<int> wt, vector<int> val, int n) {
    vector<vector<int>> K(n + 1, vector<int>(W + 1));
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0) {
                K[i][w] = 0;
            } else if (wt[i - 1] <= w) {
                K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
            } else {
                K[i][w] = K[i - 1][w];
            }
        }
    }
    return K[n][W];
}

int main() {
    int W, n;
    cout << "Enter the maximum weight capacity of the knapsack: ";
    cin >> W;
    cout << "Enter the number of items: ";
    cin >> n;
    vector<int> wt(n);
    vector<int> val(n);
    cout << "Enter the weight and value of each item:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> wt[i] >> val[i];
    }
    cout << "The maximum value that can be carried in the knapsack is: " << knapsack(W, wt, val, n) << endl;
    return 0;
}


/*
In this implementation, we use a 2D vector K to store the maximum value that can be obtained with each combination of items and weight. We initialize the first row and column of K to 0, since there is no value that can be obtained with 0 weight or 0 items. Then, for each subsequent row i and column w, we consider two cases: either we include item i in the knapsack, in which case the maximum value is the sum of the value of item i and the maximum value that can be obtained with the remaining weight and items, or we exclude item i from the knapsack, in which case the maximum value is the same as the maximum value that can be obtained with the remaining items and weight. We take the maximum of these two cases and store it in K[i][w].

The time complexity of this implementation is O(nW), where n is the number of items and W is the maximum weight capacity of the knapsack. This is because we must fill in a 2D array of size (n+1) x (W+1) in order to compute the maximum value that can be obtained with each combination of items and weight.

In terms of space complexity, the dynamic programming approach uses O(nW) space to store the 2D vector K, which can be quite large for large values of n and W.

In comparison, the greedy approach has a time complexity of O(n log n) and a space complexity of O(1), but may not always give an optimal solution. The greedy approach selects items in order of their value-to-weight ratio, but this may not always lead to the maximum possible value. In contrast, the dynamic programming approach guarantees an optimal solution, but may be slower and require more memory.
*/