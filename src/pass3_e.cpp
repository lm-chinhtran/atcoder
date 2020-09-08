//
//  pass3_e.cpp
//  learningCplusplus
//
//  Created by Tran Duc Chinh on 2020/04/04.
//  Copyright © 2020 Tran Duc Chinh. All rights reserved.
//

#include <iostream>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <math.h>
using namespace std;
typedef long long ll;
ll mod = 998244353;
ll INF = 1000000000000000000;
#define PI 3.14159265

ll limitpow (int x, int n) {
  if (n==0) return 1;
  ll u = limitpow(x, n/2);
  if (u > 1000000000 || u < 0) return -1;
  u = (u*u);
  if (u > 1000000000 || u < 0) return -1;
  if (n%2==1) u = (u*x);
  if (u > 1000000000 || u < 0) return -1;
  return u;
}

int main() {
  int n, m, q;
  std::cin >> n >> m >> q;

  vector<int> adj[n];
  for (int i = 0; i < m; i++) {
    int u, v;
    std::cin >> u >> v;
    u--; v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  int c[n];
  for (int i = 0; i < n; i++) {
    std::cin >> c[i];
  }

  vector<int> ans;
  for (int i = 0; i < q; i++) {
    int s;
    std::cin >> s;
    if (s == 1) {
      int x;
      std::cin >> x;
      x--;
      // std::cout << c[x] << std::endl;
      ans.push_back(c[x]);
      for (auto u: adj[x]) {
        c[u] = c[x];
      }
    }
    else if (s == 2) {
      int x, y;
      std::cin >> x >> y;
      x--;
      // std::cout << c[x] << std::endl;
      ans.push_back(c[x]);
      c[x] = y;
    }
  }

  for (auto u: ans) {
    std::cout << u << std::endl;
  }
  return 0;
}