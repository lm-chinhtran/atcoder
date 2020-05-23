//
//  abc152_Flatten.cpp
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
typedef unsigned long long ll;
ll mod = 1000000007;
ll INF = 1000000007;
#define PI 3.14159265

std::map<int, int> factorization (int n) {
  std::map<int, int> f;
  for (int i = 2; i*i <= n; i++) {
    while (n%i == 0) {
      f[i] += 1;
      n /= i;
    }
  }
  if (n > 1) {
    f[n] += 1;
  }
  return f;
}

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

  std::map<int, int> lcm;
  std::vector<std::map<int, int> > a_factorized;
  int a[n];

  for (int i = 0; i < n; i++) {

    std::cin >> a[i];
    std::map<int, int> f = factorization(a[i]);
    a_factorized.push_back(f);
    for (std::map<int, int>::iterator it = f.begin(); it != f.end(); it++) {
      if (lcm.count(it->first)) {
        lcm[it->first] = max(lcm[it->first], it->second);
      }
      else {
        lcm[it->first] = it->second;
      }
    }
  }

  ll lcm_mod = 1;
  for (std::map<int, int>::iterator it = lcm.begin(); it != lcm.end(); it++) {
    lcm_mod = (lcm_mod * modpow(it->first, it->second));
  }

  ll sum = 0;
  for (int i = 0; i < n; i++) {
    sum = (sum + lcm_mod/a[i]) % mod;
  }


  std::cout << sum << std::endl;

  return 0;
}