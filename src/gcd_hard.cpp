//
//  gcd_hard.cpp
//  learningCplusplus
//
//  Created by Tran Duc Chinh on 2020/04/04.
//  Copyright © 2020 Tran Duc Chinh. All rights reserved.
//

#include <iostream>
#include <math.h>
using namespace std;
typedef long long ll;
ll mod = 1000000007;

ll solve(int n, int k) { // find number of sequence has max divisor: 1
  ll no_of_sequence = pow(k, n);
  for (int j=2; j<=k; j++) {
    no_of_sequence -= solve(n, k/j);
  }
  return no_of_sequence;
}

ll pow_mod(ll x, ll y) {
  // return x^y % mod
  if (y == 0) return 1;
  ll a = pow_mod(x, y/2);
  a = (a * a) % mod;
  if (y & 1) a = (a * x) % mod;
  return a;
}

int main(int argc, const char* argv[]) {

  int n, k;
  std::cin >> n >> k;
  ll dp[k+1];
  // dp[1] = 1;
  // for (int i=2; i<=k; i++) {
  //   ll total_sequence = pow_mod(i, n);
  //   for (int j=2; j<=i; j++) {
  //     total_sequence -= dp[i/j];
  //   }
  //   dp[i] = total_sequence;
  // }
  ll cnt = 0;
  // for (int i=1; i<=k; i++) {
  //   int number_divisible_by_i = k / i;
  //   // std::cout << "total sequance has max divisor " << i << ": " << dp[number_divisible_by_i] << std::endl;
  //   (cnt += i*dp[number_divisible_by_i]) %= mod;
  // }

  for (int i=k; i>0; i--) {
    ll total_sequence = pow_mod(k/i, n); // devides by i
    int j = 2;
    while(i*j <= k) {
      total_sequence = (total_sequence - dp[j*i] + mod) % mod;
      j++;
    }

    dp[i] = total_sequence;
    (cnt += i*total_sequence) %= mod;
  }

  std::cout << cnt << std::endl;
  return 0;
}
