//Implement the coin change problem using a greedy approach

/*
The coin change problem is a classic problem in computer science that involves finding the minimum number of coins required to make change for a given amount of money. Given a set of coin denominations and a target amount, the goal is to find the minimum number of coins needed to make change for the target amount. The problem is commonly encountered in everyday life when making change at a cash register or vending machine.

For example, suppose we have coins with denominations of 1, 5, 10, and 25 cents. If we need to make change for 36 cents, we can do so using one 25-cent coin, one 10-cent coin, and one 1-cent coin, for a total of three coins. However, we could also use three 12-cent coins, which would also add up to 36 cents but would require more coins. The coin change problem asks us to find the minimum number of coins required to make change for a given amount, in this case, 36 cents.

The coin change problem can be solved using various techniques, such as dynamic programming or greedy algorithms.
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> coinChange(int amount, vector<int>& coins) {
    vector<int> result(coins.size(), 0);
    int i = coins.size() - 1;
    while (amount > 0 && i >= 0) {
        if (coins[i] <= amount) {
            result[i] = amount / coins[i];
            amount -= result[i] * coins[i];
        }
        i--;
    }
    if (amount > 0) {
        result.clear();
        result.push_back(-1);
    }
    return result;
}

int main() {
    int amount = 36;
    vector<int> coins = {1, 5, 10, 25};
    vector<int> result = coinChange(amount, coins);
    if (result.empty()) {
        cout << "No solution found" << endl;
    } else {
        cout << "Minimum number of coins required: ";
        for (int i = 0; i < result.size(); i++) {
            cout << result[i] << " x " << coins[i] << "c, ";
        }
        cout << endl;
    }
    return 0;
}

/*
This implementation uses a coinChange function that takes two arguments: amount is the amount of money to make change for, and coins is a vector of available coin denominations. The function returns a vector result that contains the minimum number of coins required for each denomination. The algorithm iterates through the coin denominations in descending order and subtracts as many coins as possible from the remaining amount. If the remaining amount is greater than zero and all coin denominations have been checked, the function returns an empty vector to indicate that no solution was found.

The time complexity of this algorithm is O(n), where n is the number of coin denominations. The space complexity is also O(n), since the algorithm stores the minimum number of coins required for each denomination in a vector. */