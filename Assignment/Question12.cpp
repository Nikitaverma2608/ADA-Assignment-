//Implement the fractional knapsack problem using a greedy approach in flowchart.

/*
The knapsack problem is a well-known optimization problem in which we need to maximize the total value of items that can be included in a knapsack of limited capacity. The greedy approach to the knapsack problem involves choosing the items with the highest value-to-weight ratio until the knapsack is full. Here's the implementation of the knapsack problem using the greedy approach in C++:

*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Item {
    int value;
    int weight;
};

bool cmp(Item a, Item b) {
    return (double)a.value / a.weight > (double)b.value / b.weight;
}

double fractionalKnapsack(int W, vector<Item>& items) {
    sort(items.begin(), items.end(), cmp);
    double totalValue = 0;
    int n = items.size();
    for (int i = 0; i < n; i++) {
        if (W == 0) {
            return totalValue;
        }
        int a = min(W, items[i].weight);
        totalValue += a * (double)items[i].value / items[i].weight;
        W -= a;
    }
    return totalValue;
}

int main() {
    int n, W;
    cout << "Enter the number of items: ";
    cin >> n;
    cout << "Enter the capacity of the knapsack: ";
    cin >> W;
    vector<Item> items(n);
    cout << "Enter the value and weight of each item: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> items[i].value >> items[i].weight;
    }
    double totalValue = fractionalKnapsack(W, items);
    cout << "The maximum total value that can be obtained is: " << totalValue << endl;
    return 0;
}

/*
In this implementation, we define a struct called Item to represent each item, with two properties: value and weight. We then define a comparison function cmp that compares the value-to-weight ratios of two items. We use sort to sort the items in decreasing order of their value-to-weight ratios.

We then define the fractionalKnapsack function that takes as input the capacity W of the knapsack and a vector items of Item structs representing the available items. We initialize totalValue to 0 and iterate through the sorted items, adding as many items as possible to the knapsack in order of their value-to-weight ratios. If we can't fit a whole item into the knapsack, we add a fraction of the item based on the remaining capacity of the knapsack.

Finally, we prompt the user to input the number of items, the capacity of the knapsack, and the value and weight of each item. We then call the fractionalKnapsack function to calculate the maximum total value that can be obtained, and print the result to the console.

The time complexity of this implementation is O(n log n), dominated by the sorting step. However, this implementation may not always produce an optimal solution to the knapsack problem, as it does not consider all possible combinations of items.
*/