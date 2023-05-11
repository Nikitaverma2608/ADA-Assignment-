//Implement the Dijkstra algorithm to find the shortest path between two vertices in a graph IN C++ ?

/*
Dijkstra's algorithm is a popular shortest-path algorithm that is used to find the shortest path between two vertices in a graph. The algorithm works by maintaining a set of visited vertices and their distances from the source vertex, and repeatedly selecting the unvisited vertex with the smallest distance to add to the visited set.

Here's an example to illustrate how Dijkstra's algorithm works:

Suppose we have the following undirected graph, where the numbers on the edges represent the weights:

       7
   A-------B
   | \     | \
  3|  2\   |  \4
   |    \  |   \
   C------D----E
       5
Suppose we want to find the shortest path from vertex A to vertex E. We can use Dijkstra's algorithm as follows:

Initialize the distances to all vertices to infinity, except for the starting vertex A, whose distance is set to 0. Also, create a set of unvisited vertices and add all the vertices to it.

A:0 B:inf C:inf D:inf E:inf

Select the unvisited vertex with the smallest distance (in this case, A) and add it to the visited set.

visited: {A}
unvisited: {B, C, D, E}

Update the distances of the neighbors of the newly visited vertex, if the new path through the current vertex is shorter than their current distance.

A:0 B:7 C:3 D:inf E:inf
Repeat steps 2 and 3 until the destination vertex E is added to the visited set.

visited: {A, C, B, D, E}
unvisited: {}
The shortest path from A to E is the sum of the weights of the edges in the path, which is 7 (A -> B -> E).

Dijkstra's algorithm is guaranteed to find the shortest path in a non-negative weighted graph, as long as there are no negative weight cycles. The time complexity of Dijkstra's algorithm is O(V^2) using an adjacency matrix or O(E+VlogV) using a min-heap priority queue with an adjacency list, where V is the number of vertices and E is the number of edges in the graph.
*/



#include <limits.h>
#include <iostream>

using namespace std;

// Wrapper class for storing a graph
class Graph {
 public:
    int vertexNum;
    int **edges;

    // Constructs a graph with V vertices and E edges
    Graph(const int V) {
        // initializes the array edges.
        this->edges = new int *[V];
        for (int i = 0; i < V; i++) {
            edges[i] = new int[V];
        }

        // fills the array with zeros.
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                edges[i][j] = 0;
            }
        }

        this->vertexNum = V;
    }

    // Adds the given edge to the graph
    void addEdge(int src, int dst, int weight) {
        this->edges[src][dst] = weight;
    }
};
// Utility function to find minimum distance vertex in mdist
int minDistance(int mdist[], bool vset[], int V) {
    int minVal = INT_MAX, minInd = 0;
    for (int i = 0; i < V; i++) {
        if (!vset[i] && (mdist[i] < minVal)) {
            minVal = mdist[i];
            minInd = i;
        }
    }

    return minInd;
}

// Utility function to print distances
void print(int dist[], int V) {
    cout << "\nVertex  Distance" << endl;
    for (int i = 0; i < V; i++) {
        if (dist[i] < INT_MAX)
            cout << i << "\t" << dist[i] << endl;
        else
            cout << i << "\tINF" << endl;
    }
}

// The main function that finds the shortest path from given source
// to all other vertices using Dijkstra's Algorithm.It doesn't work on negative
// weights
void Dijkstra(Graph graph, int src) {
    int V = graph.vertexNum;
    int mdist[V];  // Stores updated distances to vertex
    bool vset[V];  // vset[i] is true if the vertex i included
    // in the shortest path tree

    // Initialise mdist and vset. Set distance of source as zero
    for (int i = 0; i < V; i++) {
        mdist[i] = INT_MAX;
        vset[i] = false;
    }

    mdist[src] = 0;

    // iterate to find shortest path
    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(mdist, vset, V);

        vset[u] = true;

        for (int v = 0; v < V; v++) {
            if (!vset[v] && graph.edges[u][v] &&
                mdist[u] + graph.edges[u][v] < mdist[v]) {
                mdist[v] = mdist[u] + graph.edges[u][v];
            }
        }
    }

    print(mdist, V);
}

// Driver Function
int main() {
    int V, E, gsrc;
    int src, dst, weight;
    cout << "Enter number of vertices: ";
    cin >> V;
    cout << "Enter number of edges: ";
    cin >> E;
    Graph G(V);
    for (int i = 0; i < E; i++) {
        cout << "\nEdge " << i + 1 << "\nEnter source: ";
        cin >> src;
        cout << "Enter destination: ";
        cin >> dst;
        cout << "Enter weight: ";
        cin >> weight;

        // makes sure source and destionation are in the proper bounds.
        if (src >= 0 && src < V && dst >= 0 && dst < V) {
            G.addEdge(src, dst, weight);
        } else {
            cout << "source and/or destination out of bounds" << endl;
            i--;
            continue;
        }
    }
    cout << "\nEnter source:";
    cin >> gsrc;
    Dijkstra(G, gsrc);

    return 0;
}

/*


The time complexity of Dijkstra's algorithm is O((|E| + |V|) log |V|) using a priority queue, where |V| and |E| are the number of vertices and edges in the graph, respectively. The space complexity is O(|V|) for the distance vector and the priority queue.  */