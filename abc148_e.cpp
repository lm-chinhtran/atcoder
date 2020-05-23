//
//  abc148_e.cpp
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

std::vector<int> permutations;

int gcd(int a, int b) {
   if (b == 0)
      return a;
   return gcd(b, a % b);
}

int main() {
  ll n;
  std::cin >> n;
  if (n%2 == 1) {
    std::cout << 0 << std::endl;
    return 0;
  }

  ll divisor = 10;
  ll ans = 0;
  ll acc = n/divisor;
  while (acc > 0) {
    ans += acc;
    divisor *= 5;
    acc = n/divisor;
  }
  std::cout << ans << std::endl;
  return 0;
}

