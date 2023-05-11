//Implement Breadth First Search (BFS) algorithm to find the shortest path between
//two nodes in a graph

/*
BFS stands for Breadth First Search. It is a graph traversal algorithm that visits all the nodes of a graph in breadth-first order, i.e., it visits all the nodes at the same level (or distance from the starting node) before moving on to the next level. In other words, BFS starts at the root node (or any arbitrary node) and visits all the nodes that are at distance 1 from the root node before visiting the nodes that are at distance 2, and so on.

BFS is commonly used for finding the shortest path between two nodes in an unweighted graph, as it guarantees that the path found is the shortest possible path. However, BFS can also be used for other graph-related problems such as connected components, cycle detection, and topological sorting.

The time complexity of the BFS algorithm is represented in the form of O(V + E), where V is the number of nodes and E is the number of edges.

The space complexity of the algorithm is O(V).
*/

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void bfs(vector<vector<int>>& adjList, int start, int end) {
    vector<int> visited(adjList.size(), false);
    queue<int> q;
    vector<int> parent(adjList.size(), -1);

    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        for (auto neighbor : adjList[curr]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                parent[neighbor] = curr;
                q.push(neighbor);

                if (neighbor == end) {
                    // Path found
                    vector<int> path;
                    int node = end;
                    while (node != -1) {
                        path.push_back(node);
                        node = parent[node];
                    }

                    cout << "Shortest path: ";
                    for (int i = path.size() - 1; i >= 0; i--) {
                        cout << path[i] << " ";
                    }
                    cout << endl;

                    return;
                }
            }
        }
    }

    cout << "No path found" << endl;
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

    int start = 0;
    int end = 5;

    bfs(adjList, start, end);

    return 0;
}



/*
In this implementation, the bfs function takes an adjacency list representation of the graph, the start node, and the end node as inputs. It initializes a visited array to keep track of visited nodes, a queue to store nodes to be processed, and a parent array to keep track of the parent of each node in the BFS tree. It starts by marking the start node as visited and adding it to the queue. It then enters a loop that dequeues a node, visits its unvisited neighbors, and enqueues them. If the end node is visited, the function constructs the shortest path by tracing back the parent array from the end node to the start node and prints it. If the queue is empty and the end node is not visited, the function prints a message indicating that no path was found. The main function creates an example graph, specifies the start and end nodes, and calls the bfs function to find the shortest path. */