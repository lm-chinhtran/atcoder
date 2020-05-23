//
//  abc151_e.cpp
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
    return fac[n] * (finv[k]* finv[n-k] % mod) % mod;
}

ll HCOM(int n, int k) {
    return (n == 0 && k == 0) ? 1 : COM(n+k-1, k);
}


int main() {
  int n, k;
  std::cin >> n >> k;
  vector<ll> a;

  COMinit();

  for (int i = 0; i < n; i++) {
    ll t;
    std::cin >> t;
    a.push_back(t);
  }
  sort(a.begin(), a.end());

  ll smax = 0;
  for (int i = k-1; i < n; i++) {
    smax = (smax + a[i]*COM(i, k-1)) % mod;
  }

  ll smin = 0;
  for (int i = 0; i < n-k+1; i++) {
    smin = (smin + a[i]*COM(n-1-i, k-1)) % mod;
  }

  std::cout << (smax - smin + mod)%mod << std::endl;
  return 0;
}

