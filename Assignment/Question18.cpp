//Implement Depth First Search (DFS) algorithm to traverse a graph and find connected components

/*
DFS stands for Depth First Search. It is a graph traversal algorithm that visits all the nodes of a graph by going as deep as possible along each branch before backtracking. In other words, DFS starts at the root node (or any arbitrary node) and explores as far as possible along each branch before backtracking to the last node with unexplored neighbors.

DFS is commonly used for finding paths between two nodes, detecting cycles in a graph, and finding strongly connected components in a directed graph. It is also used for topological sorting, which is an ordering of the nodes in a directed graph that respects the ordering of the edges.


The time complexity of the DFS algorithm is represented in the form of O(V + E), where V is the number of nodes and E is the number of edges.

The space complexity of the algorithm is O(V).


*/

#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<vector<int>>& adjList, vector<bool>& visited, int node) {
    visited[node] = true;

    cout << node << " ";

    for (auto neighbor : adjList[node]) {
        if (!visited[neighbor]) {
            dfs(adjList, visited, neighbor);
        }
    }
}

int main() {
    int n = 6; // Number of nodes
    vector<vector<int>> adjList(n);
    adjList[0] = {1, 2};
    adjList[1] = {0, 3, 4};
    adjList[2] = {0, 4};
    adjList[3] = {1, 5};
    adjList[4] = {1, 2, 5};
    adjList[5] = {3, 4};

    vector<bool> visited(n, false);
    int numComponents = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            numComponents++;
            cout << "Connected component " << numComponents << ": ";
            dfs(adjList, visited, i);
            cout << endl;
        }
    }

    return 0;
}

/*

In this implementation, the dfs function takes an adjacency list representation of the graph, a visited array to keep track of visited nodes, and a node as inputs. It starts by marking the node as visited and printing its value. It then recursively calls the dfs function on each unvisited neighbor of the node. The main function creates an example graph, initializes the visited array to all false, and loops through each node of the graph. For each unvisited node, it increments the number of connected components, prints a header for the component, and calls the dfs function to traverse the component.

In this implementation, the dfs function is called once for each unvisited node of the graph, which guarantees that all connected components of the graph will be visited. The output of this program will be the nodes visited in each connected component, along with a header indicating the component number. */