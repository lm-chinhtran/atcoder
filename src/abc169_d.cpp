//
//  abc169_d.cpp
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

std::map<ll, ll> factorization (ll n) {
  std::map<ll, ll> f;
  for (ll i = 2; i*i <= n; i++) {
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

int main() {
  ll n;
  std::cin >> n;
  std::map<ll, ll> n_factorized;
  n_factorized = factorization(n);

  ll ans = 0;
  for (std::map<ll, ll>::iterator it = n_factorized.begin(); it != n_factorized.end(); it++) {
    ll start = 1;
    while (it->second - start >= 0) {
      ans++;
      it->second -= start;
      start++;
    }
  }
  std::cout << ans << std::endl;

  return 0;
}