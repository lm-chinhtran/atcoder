//
//  bfs.cpp
//  learningCplusplus
//
//  Created by Tran Duc Chinh on 2020/04/04.
//  Copyright © 2020 Tran Duc Chinh. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;
typedef long long ll;
ll mod = 1000000007;


int main(int argc, const char* argv[]) {

  int n = 5;

  vector<int> adj[n];
  adj[0].push_back(1);
  adj[1].push_back(0);

  adj[1].push_back(2);
  adj[2].push_back(1);

  adj[2].push_back(3);
  adj[3].push_back(2);

  adj[2].push_back(4);
  adj[4].push_back(2);

  adj[3].push_back(4);
  adj[4].push_back(3);

  adj[4].push_back(1);
  adj[1].push_back(4);

  queue<int> q;
  bool visited[n];
  int distance[n];

  int x = 0;
  visited[x] = true;
  q.push(x);
  distance[x] = 0;

  while (!q.empty()) {
    int s = q.front();
    q.pop();
    // process node
    for (auto u: adj[s]) {
      if (visited[u]) continue;
      visited[u] = true;
      distance[u] = distance[s] + 1;
      std::cout << "distance to node " << u << ": " << distance[u] << std::endl;
      q.push(u);
    }
  }
  return 0;
}
