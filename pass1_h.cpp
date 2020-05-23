//
//  pass1_h.cpp
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
  std::map<ll, ll> c;

  ll minC = INF;
  ll minC_odd = INF;
  for (int i = 1; i <= n; i++) {
     ll t;
     std::cin >> t;
     c[i] = t;
     minC = min(minC, t);
     if (i%2==1) minC_odd = min(minC_odd, t);
  }

  int q;
  std::cin >> q;

  ll ans = 0;
  ll minusC = 0;
  ll minusC_odd = 0;
  for (int i = 1; i <= q; i++) {
     int s, x, a;
     std::cin >> s;

    if (s == 1) {
      std::cin >> x >> a;

      ll cx = c[x]-minusC;
      if (x%2==1) cx -= minusC_odd;
      if (cx >= a) {
        c[x] -= a;
        cx -= a;
        ans += a;
        minC = min(minC, cx);
        if (x%2==1) minC_odd = min(minC_odd, cx);
      }
    }
    if (s == 2) {
      std::cin >> a;
      if (minC_odd >= a) {
        minC_odd -= a;
        ll card = (n+1)/2;
        ans += a*card;
        minusC_odd += a;
        minC = min(minC, minC_odd);
      }
    }
    if (s == 3) {
      std::cin >> a;
      if (minC >= a) {
        minC -= a;
        ans += a*n;
        minusC += a;
        minC_odd -= a;
      }
    }
  }

  std::cout << ans << std::endl;

  return 0;
}

