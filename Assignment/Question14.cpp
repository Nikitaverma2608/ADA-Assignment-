//Implement Kruskal's algorithm to find the minimum spanning tree of a given graph in c++ ?

/*
Kruskal's algorithm is a greedy algorithm used to find the minimum spanning tree (MST) of a connected, weighted graph. The minimum spanning tree is a tree that spans all the vertices of the graph while minimizing the total weight of the edges.

The algorithm works by sorting all the edges of the graph in non-decreasing order of their weights. Then, starting from the smallest edge, the algorithm checks if adding that edge to the MST creates a cycle. If it doesn't create a cycle, the edge is added to the MST. This process continues until all the vertices are in the MST.

Here's an example of how Kruskal's algorithm works:

Consider the following graph:

      6       5
  A------B-------C
   \     |\      |
 8  \  1 | \  2  | 3
     \   |  \    |
       D------E
         4
The first step is to sort all the edges in non-decreasing order of their weights:



    Edge    Weight
  ---------------
    B-C       3
    D-E       4
    B-E       5
    A-B       6
    B-D       8
    A-D       8
    B-C       9
    C-E      10
    C-D      12
Next, starting from the smallest edge, we check if adding the edge creates a cycle. The first edge is B-C with weight 3, so we add it to the MST:


    B-------C
             |
             |
             |
             |
             |
             |
             |
             |
             |
             |
             |
             |
The next edge is D-E with weight 4, so we add it to the MST:

    B-------C
             |
             |
             |
        D----E
The next edge is B-E with weight 5, so we add it to the MST:


    B-------C
             |
             |
             |
        D----E
             |
             |
             |
             |
             |
             |
             |
The next edge is A-B with weight 6, so we add it to the MST:


    B-------C
    |        |
    |        |
    |        |
  A-|----D---E
The next edge is B-D with weight 8, but adding it would create a cycle, so we skip it.

The next edge is A-D with weight 8, but adding it would also create a cycle, so we skip it.

The next edge is B-C with weight 9, but adding it would create a cycle, so we skip it.

The next edge is C-E with weight 10, so we add it to the MST:


    B-------C
    |        |
    |        |
    |        |
  A-|----D---E
         |
         |
         |
The final edge is C-D with weight 12, but adding it would create a cycle, so we skip it.

The MST for this graph is:


    B-------C
    |        |
    |        |
    |        |
  A-|----D---E
And the total weight of the MST is 30.

Kruskal's Algorithm Complexity:

The time complexity Of Kruskal's Algorithm is: O(E log E)

*/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

#define edge pair<int, int>

class Graph {
   private:
  vector<pair<int, edge> > G;  // graph
  vector<pair<int, edge> > T;  // mst
  int *parent;
  int V;  // number of vertices/nodes in graph
   public:
  Graph(int V);
  void AddWeightedEdge(int u, int v, int w);
  int find_set(int i);
  void union_set(int u, int v);
  void kruskal();
  void print();
};
Graph::Graph(int V) {
  parent = new int[V];

  //i 0 1 2 3 4 5
  //parent[i] 0 1 2 3 4 5
  for (int i = 0; i < V; i++)
    parent[i] = i;

  G.clear();
  T.clear();
}
void Graph::AddWeightedEdge(int u, int v, int w) {
  G.push_back(make_pair(w, edge(u, v)));
}
int Graph::find_set(int i) {
  // If i is the parent of itself
  if (i == parent[i])
    return i;
  else
    // Else if i is not the parent of itself
    // Then i is not the representative of his set,
    // so we recursively call Find on its parent
    return find_set(parent[i]);
}

void Graph::union_set(int u, int v) {
  parent[u] = parent[v];
}
void Graph::kruskal() {
  int i, uRep, vRep;
  sort(G.begin(), G.end());  // increasing weight
  for (i = 0; i < G.size(); i++) {
    uRep = find_set(G[i].second.first);
    vRep = find_set(G[i].second.second);
    if (uRep != vRep) {
      T.push_back(G[i]);  // add to tree
      union_set(uRep, vRep);
    }
  }
}
void Graph::print() {
  cout << "Edge :"
     << " Weight" << endl;
  for (int i = 0; i < T.size(); i++) {
    cout << T[i].second.first << " - " << T[i].second.second << " : "
       << T[i].first;
    cout << endl;
  }
}
int main() {
  Graph g(6);
  g.AddWeightedEdge(0, 1, 4);
  g.AddWeightedEdge(0, 2, 4);
  g.AddWeightedEdge(1, 2, 2);
  g.AddWeightedEdge(1, 0, 4);
  g.AddWeightedEdge(2, 0, 4);
  g.AddWeightedEdge(2, 1, 2);
  g.AddWeightedEdge(2, 3, 3);
  g.AddWeightedEdge(2, 5, 2);
  g.AddWeightedEdge(2, 4, 4);
  g.AddWeightedEdge(3, 2, 3);
  g.AddWeightedEdge(3, 4, 3);
  g.AddWeightedEdge(4, 2, 4);
  g.AddWeightedEdge(4, 3, 3);
  g.AddWeightedEdge(5, 2, 2);
  g.AddWeightedEdge(5, 4, 3);
  g.kruskal();
  g.print();
  return 0;
}