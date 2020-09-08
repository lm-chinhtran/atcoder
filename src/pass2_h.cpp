//
//  pass2_h.cpp
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

pair<int, int> dijsktra(int x, char des, int n, vector<pair<int, char> > *adj) {
  priority_queue<pair<pair<int, char>, int> >  q; // (-d, x) current distance to node x is d, using -d to find minimum distance
  bool processed[n];
  pair<int, char> distance[n];
  for (int i=0; i<n; i++) {
    distance[i].first = INF;
    distance[i].second = '0';
    processed[i] = false;
  }
  // find from x
  distance[x] = make_pair(0, '0');
  q.push({distance[x], x});

  while (!q.empty()) {
    int a = q.top().second;
    q.pop();
    if (processed[a]) continue;;
    processed[a] = true;
    for (auto u: adj[a]) {
      int b = u.first; // node b
      char label = u.second;
      int w = 1; // distance from a to b is w
      if (distance[b].first > distance[a].first + w) {
        distance[b] = make_pair(distance[a].first + w, label);
        q.push({{-distance[b].first, label}, b});
      }
    }
  }

  int l = INF;
  int end = 0;
  // std::cout << "distance from " << x << std::endl;
  for (int i = 0; i < n; i++) {
    if (distance[i].first==INF) continue;
    if (distance[i].second == des && distance[i].first < l) {
      l = distance[i].first;
      end = i;
    }
    // std::cout << " distance to " << i << ": " << distance[i] << std::endl;
  }

  return make_pair(l, end);
}


int main() {
  int n, m;
  std::cin >> n >> m;

  int dp[11][n][m];
  vector<pair<int, int> > p[11];
  for (int i = 0; i < 11; i++) {
    for (int r = 0; r < n; r++) {
      for (int c = 0; c < m; c++) {
        dp[i][r][c] = INF;
      }
    }
  }

  for (int i = 0; i < n; i++) {
    string t;
    std::cin >> t;
    for (int j = 0; j < m; j++) {
      if (t[j] == 'S') { p[0].push_back({i, j}); dp[0][i][j] = 0; }
      else if (t[j] == 'G') p[10].push_back({i, j});
      else p[t[j]-'0'].push_back({i, j});
    }
  }

  for (int i = 1; i < 11; i++) {
    for (auto u: p[i]) {
      int ri = u.first;
      int ci = u.second;
      for (auto v: p[i-1]) {
        int ri1 = v.first;
        int ci1 = v.second;
        dp[i][ri][ci] = min(dp[i][ri][ci], abs(ri1-ri) + abs(ci1-ci) + dp[i-1][ri1][ci1]);
      }
    }
  }

  int ans = dp[10][p[10][0].first][p[10][0].second];
  if (ans >= INF) {
    std::cout << -1 << std::endl;
  }
  else {
    std::cout << ans << std::endl;
  }

  return 0;
}