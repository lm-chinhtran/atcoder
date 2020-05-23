//
//  abc168_d.cpp
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
ll mod = 1000000007;
ll INF = 1000000007;
#define PI 3.14159265

const int MAX = 110000;

ll fac[MAX], finv[MAX], inv[MAX];

std::vector<int> permutations;

int gcd(int a, int b) {
   if (b == 0)
      return a;
   return gcd(b, a % b);
}



int main() {
  int n, m;
  std::cin >> n >> m;

  vector<int> adj[n];

  for (int i = 0; i < m; i++) {
    int a, b;
    std::cin >> a >> b;
    adj[a-1].push_back(b-1);
    adj[b-1].push_back(a-1);
  }

  //
  priority_queue<pair<int, int> >  q; // (-d, x) current distance to node x is d, using -d to find minimum distance
  bool processed[n];
  int distance[n];
  for (int i=0; i<n; i++) {
    distance[i] = INF;
    processed[i] = false;
  }
  // find from x = 0
  distance[0] = 0;
  q.push({0, 0});

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

  for (int i = 0; i < n; i++) {
    if (distance[i]==INF) {
      std::cout << "No" << std::endl;
      return 0;
    }
  }
  std::cout << "Yes" << std::endl;
  for (int i = 1; i < n; i++) {
    std::cout << distance[i] << std::endl;
  }


  return 0;
}

