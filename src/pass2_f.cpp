//
//  pass2_f.cpp
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
vector<vector<int> > v;
void dfs(vector<int> A, int n, int m)  {
  if  (A.size() > n) {
    vector<int> t;
    bool valid = false;
    bool s_valid = true;
    for (int i = 1; i <= n; i++) {
      t.push_back(A[i]);
      if (A[i] != 1) valid = true;
      if (A[i] == 1 & i!=1 && i!=n && A[1]!=1 && A[n]!=1) s_valid = false;
    }
    if (valid & s_valid) v.push_back(t);
    return;
  }
  A.push_back(1);
  while (A.back() <= m) {
    dfs(A, n, m);
    A.back()++;
  }
}

int main() {
  int n;
  std::cin >> n;
  std::map<int, std::vector<int> > m;
  std::priority_queue<int> q;
  std::priority_queue<int> qa[n];

  for (int i = 0; i < n; i++) {
    int a, b;
    std::cin >> a >> b;
    m[a].push_back(b);
  }

  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (m.count(i+1)) {
      for (auto j: m[i+1]) {
        q.push(j);
      }
    }
    ans += q.top();
    q.pop();
    std::cout << ans << std::endl;
  }

  return 0;
}

