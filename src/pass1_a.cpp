//
//  pass1_a.cpp
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
  int n;
  std::cin >> n;
  ll a[n];
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
    if (i > 0) {
      ll x = a[i] - a[i - 1];
      if (x == 0) {
        std::cout << 'stay' << std::endl;
      }
      else if (x > 0) {
        std::cout << "up " << x << std::endl;
      }
      else {
        std::cout << "down " << -x << std::endl;
      }
    }
  }
  return 0;
}

