//Implement the Prim's algorithm to find the minimum spanning tree of a given graph


/*
Prim's algorithm is a greedy algorithm used to find the minimum spanning tree of a connected, weighted undirected graph. The minimum spanning tree is a tree that connects all the nodes in the graph with the minimum total weight of edges.

The algorithm starts with a single node, and iteratively adds the nearest node to the tree, until all the nodes are included in the tree. In each iteration, the algorithm selects the node with the smallest weight edge that connects it to the tree, and adds it to the tree. This process continues until all the nodes are included in the tree.

The steps of Prim's algorithm are as follows:

1. Start with a single node in the graph.
2. For each node in the tree, find the edge with the smallest weight that connects it to a node that is not in the tree.
3. Add the node with the smallest weight edge to the tree.
4. Repeat steps 2 and 3 until all the nodes are included in the tree.


Prim's algorithm can be implemented using a priority queue to keep track of the smallest weight edges, and a set to keep track of the nodes in the tree. The time complexity of Prim's algorithm is O(E log V), where E is the number of edges in the graph and V is the number of nodes in the graph.
*/

#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

int prim(vector<vector<pair<int, int>>>& adjList, int startNode) {
    int n = adjList.size();
    vector<bool> visited(n, false);
    vector<int> minDist(n, INF);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, startNode));
    minDist[startNode] = 0;

    int minCost = 0;

    while (!pq.empty()) {
        int node = pq.top().second;
        pq.pop();

        if (visited[node]) {
            continue;
        }

        visited[node] = true;
        minCost += minDist[node];

        for (auto neighbor : adjList[node]) {
            int neighborNode = neighbor.first;
            int weight = neighbor.second;

            if (!visited[neighborNode] && weight < minDist[neighborNode]) {
                minDist[neighborNode] = weight;
                pq.push(make_pair(minDist[neighborNode], neighborNode));
            }
        }
    }

    return minCost;
}

int main() {
    int n = 5; // Number of nodes
    vector<vector<pair<int, int>>> adjList(n);
    adjList[0] = {{1, 2}, {3, 6}};
    adjList[1] = {{0, 2}, {2, 3}, {3, 8}, {4, 5}};
    adjList[2] = {{1, 3}, {4, 7}};
    adjList[3] = {{0, 6}, {1, 8}, {4, 9}};
    adjList[4] = {{1, 5}, {2, 7}, {3, 9}};

    int startNode = 0;

    int minCost = prim(adjList, startNode);

    cout << "Minimum cost of the minimum spanning tree: " << minCost << endl;

    return 0;
}

/*
In this implementation, the prim function takes an adjacency list representation of the graph and a starting node as inputs. It uses a priority queue to keep track of the edges with the minimum weight, and a visited array to keep track of visited nodes. It starts by initializing the minDist array to a large value, except for the starting node, which is initialized to 0. It then pushes the starting node onto the priority queue with a weight of 0.

The while loop continues until the priority queue is empty. In each iteration, it pops the edge with the minimum weight from the priority queue, and checks if the destination node has already been visited. If it has been visited, the loop continues. Otherwise, it marks the node as visited and updates the minCost variable. It then checks all the neighbors of the node and updates their distances and adds them to the priority queue if their distance is smaller than their current distance.

In this implementation, the main function creates an example graph, initializes the starting node to 0, and calls the prim function to find the minimum cost of the minimum spanning tree. The output of this program will be the minimum cost of the minimum spanning tree of the given graph.
*/