//
//  abc149_b.cpp
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
  ll a, b, k;
  std::cin >> a >> b >> k;

  if (a >= k) {
    a -= k;
  }
  else {
    k -= a;
    a = 0;
    if (b >= k) {
      b -= k;
    }
    else {
      k -= b;
      b = 0;
    }
  }

  std::cout << a << " " << b << std::endl;
  return 0;
}

