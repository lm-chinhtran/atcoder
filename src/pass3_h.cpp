//
//  pass3_h.cpp
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
  int n, l;
  std::cin >> n >> l;
  bool x[l+1];
  for (int i=0; i<l+1; i++) {
    x[i] = false;
  }

  for (int i = 0; i < n; i++) {
    int t;
    std::cin >> t;
    x[t] = true;
  }
  ll t1, t2, t3;
  std::cin >> t1 >> t2 >> t3;

  ll dp[l+1];
  dp[0] = 0;

  for (int i = 1; i < l+1; i++) {
    ll act1 = t1;
    if (i==l) act1 = min(act1, t1/2 + t2/2);
    if (x[i-1]) act1 += t3;
    act1 += dp[i-1];

    ll act2 = INF;
    if (i>=2) act2 = t1 + t2;
    if (i==l) act2 = min(act2, t1/2 + t2*3/2);
    if (x[i-2] && i >= 2) act2 += t3;
    act2 += dp[i-2];

    ll act3 = INF;
    if (i>=4) act3 = dp[i-4] + t1 + t2*3;
    if (x[i-4] && i >= 4) act3 += t3;
    if (i==l && l>=3) {
      ll act = dp[i-3] + t1/2 * t2*5/2;
      if(x[i-3]) act += t3;
      act3 = min(act, act3);
    }

    ll t = min(act1, act2);
    dp[i] = min(t, act3);
    // std::cout << "dp[i] = " << dp[i] << std::endl;
  }



  std::cout << dp[l] << std::endl;

  return 0;
}