//
//  sum_of_large_number.cpp
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


int main(int argc, const char* argv[]) {

  int n, k;
  std::cin >> n >> k;

  // ll C[n+2];

  // C[0] = 1;  // nC0 is 1
  // C[1] = n+1;

  //   for (int i = 2; i < n+1; i++)
  //   {
  //       C[i] = (((n - i + 2) * C[i-1] / i)) % mod;
  //   }
  // C[n+1] = 1;
  // ll sum = 0;
  // for (int i = k; i <= n+1; i++) {
  //   int repeat = ((n+1) / i) - 1;
  //   sum = (sum + C[i] - repeat + mod) % mod;
  // }
  // std::cout << sum << std::endl;
  ll sum = 0;
  for (ll i=k; i<=n+1; i++) {
    ll smallest = (i*(i-1)/2) ;
    ll largest = ((n-i+1+n)*i/2) ;
    (sum += (largest - smallest + 1)) %= mod;
  }
  std::cout << sum << std::endl;

  return 0;
}
