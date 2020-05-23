//
//  Knapsack.cpp
//  learningCplusplus
//
//  Created by Tran Duc Chinh on 2020/04/04.
//  Copyright © 2020 Tran Duc Chinh. All rights reserved.
//

#include <iostream>

using namespace std;
typedef long long ll;
const ll mod = 998244353;

ll dp[3010][3010][3010]; // The number of combinations chosen from the first i elements, such that the sum of elements is s

int main(int argc, const char* argv[]) {
  int n, s;
  std::cin >> n >> s;
  int a[n];
  for (int i=0; i<n; i++) {
    std::cin >> a[i];
  }
  ll cnt = 0;
  for (int i=0; i<n; i++) {
    dp[i][i][0] = 1;
    if (a[i] <=s ) {
      (dp[i][i][a[i]] += 1) %= mod;
    }
    // std::cout << i << " " << i << " " << dp[i][i][s] << std::endl;
    (cnt += dp[i][i][s]) %= mod;
    for (int j=i+1; j<n; j++) {
      for (int k=0; k<=s; k++) {
        (dp[i][j][k] += dp[i][j-1][k]) %= mod;
        if (k+a[j]<=s) {
          (dp[i][j][k+a[j]] += dp[i][j-1][k]) %= mod;
        }
      }
      // std::cout << i << " " << j << " " << dp[i][j][s] << std::endl;
      (cnt += dp[i][j][s]) %= mod;
    }
  }

  std::cout << cnt << std::endl;

  // //test
  // dp[0][0][0] = 1;
  // if (a[0] <= s) {
  //   dp[0][a[0]][0] = 1;
  // }

  // for (int i = 1; i <n; i++) {
  //   for (int j=0; j<=s; j++) {
  //     dp[i][j][0] += dp[i-1][j][0];
  //     if (j+a[i]<=s) {
  //       std::cout << a[i] << " " << i << " " << j << " " << dp[i-1][j][0] << std::endl;
  //       std::cout << "before dp[i][j+a[i]][0] " << dp[i][j+a[i]][0] << std::endl;
  //       dp[i][j+a[i]][0] += dp[i-1][j][0];
  //       std::cout << "after dp[i][j+a[i]][0] " << dp[i][j+a[i]][0] << std::endl;
  //     }
  //   }
  // }
  // std::cout << dp[n-1][s][0] << std::endl; // total sequences have sum=s
  return 0;
}
