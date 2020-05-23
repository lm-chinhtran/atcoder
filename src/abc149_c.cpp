//
//  abc149_c.cpp
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
  int x;
  std::cin >> x;

  int sieve[2*x];

  for (int i = 2; i < x*2; i++) {
    if (sieve[i] == 1) continue;
    sieve[i] = 0;
    for (int j = 2*i; j < x*2; j+=i) {
      sieve[j] = 1;
    }
  }
  for (int i = x; i < x*2; i++) {
    if (sieve[i] == 0) {
      std::cout << i << std::endl;
      return 0;
    }
  }
  return 0;
}

