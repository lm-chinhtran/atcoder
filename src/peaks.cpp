//
//  peaks.cpp
//  learningCplusplus
//
//  Created by Tran Duc Chinh on 2020/04/04.
//  Copyright © 2020 Tran Duc Chinh. All rights reserved.
//

#include <iostream>
#include <queue>
#include <map>
using namespace std;
typedef long long ll;
ll mod = 1000000007;
#define PI 3.14159265
void dfs(vector<int> A, int n, int m)  {
  if  (A.size() > n) {
    for (int i = 1; i <= n; i++) {
      std::cout << A[i];
    }
    std::cout << std::endl;
    return;
  }
  A.push_back(A.back());
  while (A.back() <= m) {
    dfs(A, n, m);
    A.back()++;
  }
}

int main(int argc, const char* argv[]) {

  int n, m;
  std::cin >> n >> m;
  ll h[n];
  std::priority_queue<ll> road[n];

  for (int i = 0; i < n; i++) {
    std::cin >> h[i];
  }
  for (int i = 0; i < m; i++) {
    int a, b;
    std::cin >> a >> b;
    road[a-1].push(h[b-1]);
    road[b-1].push(h[a-1]);
  }

  int sum = 0;
  for (int i = 0; i < n; i++) {
    if (!road[i].empty()) {
      int high = road[i].top();
      if (h[i] > high) {
        sum++;
      }
    }
    else {
      sum++;
    }
  }


  std::cout << sum << std::endl;

  return 0;
}
