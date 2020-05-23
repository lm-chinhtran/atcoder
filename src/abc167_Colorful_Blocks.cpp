//
//  abc167_Colorful_Blocks.cpp
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

const int MAX = 510000;

ll fac[MAX], finv[MAX], inv[MAX];

void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i=2; i<MAX; i++) {
        fac[i] = fac[i-1] * i % mod;
        inv[i] = mod - inv[mod%i] * (mod / i) % mod;
        finv[i] = finv[i - 1] * inv[i] % mod;
    }
}

ll COM(int n, int k) {
    if(n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n-k] % mod) % mod;
}

ll HCOM(int n, int k) {
    return (n == 0 && k == 0) ? 1 : COM(n+k-1, k);
}

int main() {
  ll n, m, k;
  std::cin >> n >> m >> k;
  COMinit();

  ll sum = 0;
  for (int i = 0; i <= k; i++) {
    ll ans = (COM(n-1, i) * m) % mod;
    ans = (ans * modpow(m-1, n-1-i)) % mod;
    sum = (sum + ans) % mod;
  }

  std::cout << sum << std::endl;
  return 0;
}