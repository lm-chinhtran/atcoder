//
//  abc150_e.cpp
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
  int n, m;
  std::cin >> n >> m;
  ll a[n];
  std::cin >> a[0];

  ll x = 2;
  while(a[0]%x == 0) {
    x = x*2;
  }
  x /= 2;
  a[0] /= 2;

  ll lcm = a[0];
  for (int i = 1; i < n; i++) {
    std::cin >> a[i];
    if (a[i]%x!=0 || a[i]%(x*2)==0) {
      std::cout << 0 << std::endl;
      return 0;
    }
    a[i] /= 2;
    lcm = (lcm*a[i]) / gcd(lcm, a[i]);
    if (lcm > m) {
      std::cout << 0 << std::endl;
      return 0;
    }
  }

  ll ans = 0;
  for (int i = lcm; i <= m; i+=2*lcm) {
    ans++;
  }

  // std::cout << lcm << std::endl;
  std::cout << ans << std::endl;
  return 0;
}

