/*
Develop an approximation algorithm for the Set Cover Problem, and analyze its
approximation ratio and running time complexity
*/

/*
The Set Cover Problem is an NP-hard problem, which means there is no known polynomial time algorithm that can solve it exactly. However, we can use approximation algorithms to find near-optimal solutions.

One such approximation algorithm for the Set Cover Problem is the Greedy Algorithm. The algorithm works as follows:

Initialize the set of uncovered elements as the entire universe U.
While there are still uncovered elements, do the following:
a. Select the set S that covers the largest number of uncovered elements.
b. Add S to the set of chosen sets.
c. Remove the elements covered by S from the set of uncovered elements.
Return the set of chosen sets.*/

#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

vector<int> set_cover(vector<unordered_set<int>> sets, int n) {
    vector<int> ans;
    unordered_set<int> uncovered;

    for (int i = 1; i <= n; i++) {
        uncovered.insert(i);
    }

    while (!uncovered.empty()) {
        int best_set = -1;
        int best_set_size = -1;

        for (int i = 0; i < sets.size(); i++) {
            int set_size = 0;
            for (auto x : sets[i]) {
                if (uncovered.find(x) != uncovered.end()) {
                    set_size++;
                }
            }
            if (set_size > best_set_size) {
                best_set = i;
                best_set_size = set_size;
            }
        }

        ans.push_back(best_set);

        for (auto x : sets[best_set]) {
            uncovered.erase(x);
        }
    }

    return ans;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<unordered_set<int>> sets(m);

    for (int i = 0; i < m; i++) {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            int x;
            cin >> x;
            sets[i].insert(x);
        }
    }

    vector<int> ans = set_cover(sets, n);

    cout << "Minimum number of sets needed: " << ans.size() << endl;
    cout << "The sets needed are: ";
    for (auto x : ans) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}

/*This implementation uses a greedy algorithm that iteratively selects the set that covers the most uncovered elements until all elements are covered. The time complexity of this algorithm is O(m * n^2), where m is the number of sets and n is the number of elements, since we need to iterate over all sets and all elements in each iteration. The approximation ratio of this algorithm is ln(n), which means that the algorithm is guaranteed to produce a set cover that is no more than ln(n) times larger than the optimal set cover.*/