//
//  dijkstra.cpp
//  learningCplusplus
//
//  Created by Tran Duc Chinh on 2020/04/04.
//  Copyright © 2020 Tran Duc Chinh. All rights reserved.
//

#include <iostream>
#include <queue>
#include <utility>
using namespace std;
typedef long long ll;
ll mod = 1000000007;


int main(int argc, const char* argv[]) {

  int n = 5;

  vector<pair<int, int> > adj[n];
  adj[0].push_back({1, 5});
  adj[1].push_back({0, 5});

  adj[1].push_back({2, 2});
  adj[2].push_back({1, 2});

  adj[2].push_back({3, 6});
  adj[3].push_back({2, 6});

  adj[0].push_back({3, 9});
  adj[3].push_back({0, 9});

  adj[3].push_back({4, 2});
  adj[4].push_back({3, 2});

  adj[4].push_back({0, 1});
  adj[0].push_back({4, 1});

  priority_queue<pair<int, int> >  q; // (-d, x) current distance to node x is d, using -d to find minimum distance
  bool processed[n];
  int distance[n];
  int INF = 1000;
  for (int i=0; i<n; i++) {
    distance[i] = INF;
  }
  // find from 0
  int x = 0;
  distance[x] = 0;
  q.push({0, x});

  while (!q.empty()) {
    int a = q.top().second;
    q.pop();
    if (processed[a]) continue;;
    processed[a] = true;
    for (auto u: adj[a]) {
      int b = u.first; // node b
      int w = u.second; // distance from a to b is w
      if (distance[b] > distance[a] + w) {
        distance[b] = distance[a] + w;
        std::cout << "distance to " << b << ": " << distance[b] << std::endl;
        q.push({-distance[b], b});
      }
    }
  }

  for (int i = 0; i < n; i++) {
    std::cout << " distance to " << i << ": " << distance[i] << std::endl;
  }
  return 0;
}
