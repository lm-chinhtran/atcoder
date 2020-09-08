//
//  pass2_e.cpp
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
  int a[n+1];
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }

  vector<int> ans;
  for (int i = 1; i <= n; i++) {
    int j = 1;
    int x = a[i];
    while (x != i) {
      x = a[x];
      j++;
    }
    ans.push_back(j);
  }

  for (auto u: ans) {
    std::cout << u << " ";
  }
  std::cout << std::endl;
  return 0;
}

