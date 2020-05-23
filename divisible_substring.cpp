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

ll dp[200000][10000]; // The number of combinations chosen from the first i elements, such that the sum of elements is s

int main(int argc, const char* argv[]) {
  std::string s;
  int n, p;
  std::cin >> n >> p;
  std::cin >> s;

  //test
  dp[0][0] = 1;
  dp[0][(int)(s[0] - '0') % p] = 1;

  for (int i = 1; i <n; i++) {
    int d = (int)(s[i] - '0');
    for (int j=0; j<=p; j++) {
      dp[i][j] += dp[i-1][j];
      dp[i][(j+d)%p] += dp[i-1][j];
    }
  }
  std::cout << dp[n-1][0] << std::endl; // total sequences have sum=s
  return 0;
}
