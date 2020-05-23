//
//  abc148_d.cpp
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
  int a[n];

  int index = 0;
  int broken = 0;
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
    if (a[i] == index + 1) {
      index++;
    }
    else {
      broken++;
    }
  }

  if (broken == n) {
    std::cout << -1 << std::endl;
  }
  else {
    std::cout << broken << std::endl;
  }

  return 0;
}

