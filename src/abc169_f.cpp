//
//  abc169_f.cpp
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
  int n, s;
  std::cin >> n >> s;
  int a[n];
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  ll dp[n][s+1];

  for (int i = 0; i < s+1; i++) {
    dp[0][i] = 0;
  }
  dp[0][a[0]] = 1;
  dp[0][0] = 1;

  for (int i = 1; i < n; i++) {
    for (int j = 0; j < s+1; j++) {
      dp[i][j] = (dp[i-1][j]*2) % mod;
      if (j-a[i] > 0) dp[i][j] = (dp[i][j] + dp[i-1][j-a[i]]) % mod;
      else if (j-a[i] == 0) dp[i][j] = (dp[i][j] + modpow(2, i)) % mod;
    }
  }

  // ll ans = 0;
  // for (int i = 0; i < n; i++) {
  //   ans = (ans + COM(i+1, dp[i][s])) %mod;
  // }

  // std::cout << ans << std::endl;
  std::cout << dp[n-1][s] << std::endl;

  return 0;
}