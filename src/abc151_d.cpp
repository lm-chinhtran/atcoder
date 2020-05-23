//
//  abc151_d.cpp
//  learningCplusplus
//
//  Created by Tran Duc Chinh on 2020/04/04.
//  Copyright © 2020 Tran Duc Chinh. All rights reserved.
//

#include <iostream>
#include <queue>
#include <map>
#include <algorithm>
#include <math.h>
using namespace std;
typedef long long ll;
ll mod = 998244353;
ll INF = 1000000007;
#define PI 3.14159265

int dijsktra(int x, int n, vector<int> *adj) {
  priority_queue<pair<int, int> >  q; // (-d, x) current distance to node x is d, using -d to find minimum distance
  bool processed[n];
  int distance[n];
  for (int i=0; i<n; i++) {
    distance[i] = INF;
    processed[i] = false;
  }
  // find from x
  distance[x] = 0;
  q.push({0, x});

  while (!q.empty()) {
    int a = q.top().second;
    q.pop();
    if (processed[a]) continue;;
    processed[a] = true;
    for (auto u: adj[a]) {
      int b = u; // node b
      int w = 1; // distance from a to b is w
      if (distance[b] > distance[a] + w) {
        distance[b] = distance[a] + w;
        q.push({-distance[b], b});
      }
    }
  }

  int l = 0;
  // std::cout << "distance from " << x << std::endl;
  for (int i = 0; i < n; i++) {
    if (distance[i]==INF) continue;
    l = max(l, distance[i]);
    // std::cout << " distance to " << i << ": " << distance[i] << std::endl;
  }

  return l;
}


int main() {
  int h, w;
  std::cin >> h >> w;

  bool s[h][w];
  vector<int> adj[h*w];

  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      char c;
      std::cin >> c;
      if (c == '.') s[i][j] = true;
      else s[i][j] = false;
    }
  }

  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (!s[i][j]) continue;
      if (i > 0 && s[i-1][j]) adj[i*w+j].push_back((i-1)*w+j);
      if (i+1 < h && s[i+1][j]) adj[i*w+j].push_back((i+1)*w+j);
      if (j > 0 && s[i][j-1]) adj[i*w+j].push_back(i*w+j-1);
      if (j+1 < w && s[i][j+1]) adj[i*w+j].push_back(i*w+j+1);
    }
  }

  //dijsktra
  int ans = 0;
  for (int i = 0; i < h*w; i++) {
    ans = max(ans, dijsktra(i, h*w, adj));
  }
  std::cout << ans << std::endl;


  return 0;
}

