//
//  dfs.cpp
//  learningCplusplus
//
//  Created by Tran Duc Chinh on 2020/04/04.
//  Copyright © 2020 Tran Duc Chinh. All rights reserved.
//

#include <iostream>
#include <list>

using namespace std;
// graph using adjacency list
class graph {
  int n; // number of vertices
  list<int>* adj; // pointer to array of adjacency list
  void dfsUtil(int v, bool visited[]);

  public:
  graph(int v); //constructor
  void addEdge(int v, int w);
  void dfs(int v); // depth first search
};

graph::graph(int n) {
  this->n = n;
  adj = new list<int>[n];
}

void graph::addEdge(int v, int w) {
  adj[v].push_back(w); // add w to v's list
  adj[w].push_back(v); // add v to w's list
}

void graph::dfsUtil(int v, bool visited[]) {
  // mark the current vertex as visited
  visited[v] = true;
  cout << "visited " << v << endl;
  // recur for all adjacent vertices
  for (list<int>::iterator i=adj[v].begin(); i!=adj[v].end(); i++) {
    if (!visited[*i]) {
      dfsUtil(*i, visited);
    }
  }
}

void graph::dfs(int v) {
  // mark all vertices as not visited
  bool *visited = new bool[n];
  for (int i=0; i<v; i++) {
    visited[i] = false;
  }

  dfsUtil(v, visited);
}

int main(int argc, const char* argv[]) {
  // Create a graph given in the above diagram
  graph g(5);
  g.addEdge(0, 1);
  g.addEdge(1, 2);
  g.addEdge(2, 3);
  g.addEdge(2, 4);

  cout << "Following is Depth First Traversal"
          " (starting from vertex 2) \n";
  g.dfs(1);
  return 0;
}
