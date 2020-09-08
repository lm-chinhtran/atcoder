//
//  abc169_e.cpp
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

ll modpow (int x, int n) {
  if (n==0) return 1%mod;
  ll u = modpow(x, n/2);
  u = (u*u)%mod;
  if (n%2==1) u = (u*x)%mod;
  return u;
}

int main() {
  int n;
  std::cin >> n;
  std::vector<pair<ll, ll> > v;

  for (int i = 0; i < n; i++) {
    ll a, b;
    std::cin >> a >> b;
    v.push_back(make_pair(a, b));
  }

  if (n%2==1) {
    std::cout << v[(n+1)/2-1].second - v[(n+1)/2-1].first + 1 << std::endl;
    return 0;
  }

  ll ans = v[(n/2)+1-1].second + v[n/2-1].second - v[(n/2)+1-1].first - v[n/2-1].first + 1;
  std::cout << ans << std::endl;

  return 0;
}