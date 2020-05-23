//
//  abc167_SkillUp.cpp
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

std::map<int, int> factorization (int n) {
  std::map<int, int> f;
  for (int i = 2; i*i <= n; i++) {
    while (n%i == 0) {
      f[i] += 1;
      n /= i;
    }
  }
  if (n > 1) {
    f[n] += 1;
  }
  return f;
}

ll modpow (int x, int n) {
  if (n==0) return 1%mod;
  ll u = modpow(x, n/2);
  u = (u*u)%mod;
  if (n%2==1) u = (u*x)%mod;
  return u;
}

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

int main() {
  ll n, m, x;
  std::cin >> n >> m >> x;

  std::vector<int> a[n];
  int prices[n];

  for (int i = 0; i < n; i++) {
    std::cin >> prices[i];
    for (int j = 0; j < m; j++) {
      int level;
      std::cin >> level;
      a[i].push_back(level);
    }
  }

  std::priority_queue<int> q;

  for (int b = 1; b < (int)pow(2, n); b++) {
    int total_level[m];
    for (int j = 0; j < m; j++) {
      total_level[j] = 0;
    }
    int total_price = 0;

    for (int i = 0; i < n; i++) {
      int chosen = (b >> i) & 0x1;
      if (chosen == 0) continue;
      total_price += prices[i];
      for (int j = 0; j < m; j++) {
        total_level[j] += a[i][j];
      }
    }
    bool ok = true;
    for (int j = 0; j < m; j++) {
      if (total_level[j] < x) {
        ok = false;
        break;
      }
    }
    if (!ok) continue;
    q.push(-total_price);
  }

  int min = 0;
  if (q.empty()) {
    min = -1;
  }
  else {
    min  = -q.top();
  }
  std::cout << min << std::endl;
  return 0;
}