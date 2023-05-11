//Develop a dynamic programming algorithm for the coin change problem. Analyze the time and space complexity of your implementation and compare it with the time and space complexity of a greedy algorithm

/*Here's an implementation of the coin change problem using dynamic programming in C++:*/


#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int coinChange(vector<int>& coins, int amount) {
    int n = coins.size();
    vector<vector<int>> dp(n + 1, vector<int>(amount + 1, INT_MAX));

    for(int i = 0; i <= n; i++){
        dp[i][0] = 0;
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= amount; j++){
            if(j >= coins[i-1]){
                dp[i][j] = min(dp[i-1][j], dp[i][j-coins[i-1]] + 1);
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][amount] == INT_MAX ? -1 : dp[n][amount];
}

int main() {
    vector<int> coins = {1, 2, 5};
    int amount = 11;

    cout << "Minimum number of coins required: " << coinChange(coins, amount) << endl;
    return 0;
}

/*
The time complexity of this implementation is O(namount), where n is the number of coins and amount is the target amount. The space complexity is also O(namount) because we use a 2D array to store the intermediate results.

Comparing this with a greedy algorithm, the time complexity of the greedy algorithm is O(nlogn), where n is the number of coins, as we need to sort the coins first. The space complexity is O(1) because we only need to store a few variables.

The dynamic programming approach guarantees an optimal solution, while the greedy algorithm may not always give an optimal solution. Therefore, while the dynamic programming approach may have a higher time and space complexity, it is more reliable and gives a guaranteed optimal solution.  */