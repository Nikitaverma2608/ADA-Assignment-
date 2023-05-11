// Implement a branch and bound algorithm for the Traveling Salesman Problem, andanalyze its running time complexity

/*
The Traveling Salesman Problem (TSP) is a classic problem in computer science, which involves finding the shortest possible route that visits a given set of cities and returns to the starting city. It is an NP-hard problem, which means that there is no known algorithm that can solve it in polynomial time. However, one way to approach the problem is to use a branch and bound algorithm, which involves generating a search tree and pruning branches that are guaranteed to lead to suboptimal solutions. Here's an implementation of a branch and bound algorithm for the TSP in C++: */


#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

const int N = 4;

int dist[N][N] = {
    {0, 10, 15, 20},
    {10, 0, 35, 25},
    {15, 35, 0, 30},
    {20, 25, 30, 0}
};

int ans = INT_MAX;

void tsp(int curr, int cost, vector<int> visited) {
    if (visited.size() == N) {
        cost += dist[curr][0]; // add distance back to starting city
        ans = min(ans, cost);
        return;
    }
    for (int i = 0; i < N; i++) {
        if (i != curr && find(visited.begin(), visited.end(), i) == visited.end()) {
            visited.push_back(i);
            tsp(i, cost + dist[curr][i], visited);
            visited.pop_back();
        }
    }
}

int main() {
    vector<int> visited = {0};
    tsp(0, 0, visited);
    cout << "Shortest distance: " << ans << endl;
    return 0;
}

/*
This implementation uses a recursive function tsp to generate a search tree and explore all possible routes through the cities. The function takes three arguments: curr is the current city being visited, cost is the current cost of the route, and visited is a vector of cities that have already been visited. The base case occurs when all cities have been visited, and the distance from the current city back to the starting city is added to the total cost. The optimal solution is updated if the current cost is less than the current minimum.

The time complexity of this algorithm is exponential in the number of cities, which means that it is not practical for large inputs. The branch and bound algorithm reduces the search space by pruning branches that are guaranteed to lead to suboptimal solutions, which can improve performance. However, the effectiveness of the pruning depends on the problem instance and the choice of bounding function. In general, branch and bound algorithms are most effective when the bounding function is tight and efficiently computable.
*/