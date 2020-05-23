//
//  abc153_Ibis_Monster.cpp
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


int main(int argc, const char* argv[]) {

  ll h, n;
  std::cin >> h >> n;
  std::map<ll, ll> ab;

  for (int i = 0; i < n; i++) {
    ll a, b;
    std::cin >> a >> b;
    if((ab.count(a) && ab[a]>b) || !ab.count(a)) {
      ab[a] = b;
    }
    // std::cout << a << " " << ab[a] << std::endl;
  }
  ll INF = 1000000007;
  ll dp[h+1]; // min magic used to decrease H by i
  dp[0] = 0;
  for (int i = 1; i < h+1; i++) {
    dp[i] = INF;
    for (std::map<ll, ll>::iterator it = ab.begin(); it != ab.end(); it++) {
      ll a = it->first;
      ll b = it->second;
      if (i >= a) {
        dp[i] = min(dp[i], dp[i-a] + b);
        // std::cout << dp[i-a] + b << std::endl;
      }
      else {
        dp[i] = min(dp[i], b);
      }
    }
    // std::cout << "i: " << i << " dp: " << dp[i] << std::endl;
  }
  std::cout << dp[h] << std::endl;

  return 0;
}
