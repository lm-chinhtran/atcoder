//
//  abc167_Registrations.cpp
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
  std::string s, t;
  std::cin >> s >> t;

  s.push_back(t[t.size()-1]);
  if (s == t) {
    std::cout << "Yes" << std::endl;
  }
  else {
    std::cout << "No" << std::endl;
  }

  return 0;
}