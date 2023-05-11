// Implement the 0/1 knapsack problem using a greedy approach in c++ ?

/*
The 0/1 knapsack problem cannot be solved optimally using a greedy approach. However, we can solve it using dynamic programming.
*/

#include <iostream>
#include <vector>

using namespace std;

int knapsack(int capacity, vector<int>& weights, vector<int>& values, int n) {
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1));

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= capacity; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            } else if (weights[i - 1] <= j) {
                dp[i][j] = max(values[i - 1] + dp[i - 1][j - weights[i - 1]], dp[i - 1][j]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[n][capacity];
}

int main() {
    int capacity = 50;
    vector<int> weights = {10, 20, 30};
    vector<int> values = {60, 100, 120};
    int n = weights.size();

    int maxValue = knapsack(capacity, weights, values, n);

    cout << "Maximum value: " << maxValue << endl;

    return 0;
}

/*
This implementation uses a 2D vector dp to store the maximum value that can be obtained with a subset of the items up to the current item and a knapsack with the current remaining capacity. The outer loop iterates over the items, and the inner loop iterates over the remaining capacities. The if statement inside the loop checks if the current item can be added to the knapsack without exceeding the capacity and updates the dp array accordingly. Finally, the knapsack function returns the maximum value that can be obtained with all the items and the given capacity. The main function initializes the weights, values, and capacity and calls the knapsack function to get the maximum value.
*/
