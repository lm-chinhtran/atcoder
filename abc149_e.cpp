//
//  abc149_e.cpp
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

  std::priority_queue<ll> left, right;
  ll temp;
  int state = 0;

  for (int i = 0; i < n; i++) {
    ll a;
    std::cin >> a;
    left.push(a);
    right.push(a);
  }

  ll ans = 0;
  ll l = 0;
  ll r = 0;
  while (m>0) {
    if (state == 0) {
      l = left.top();
      left.pop();
      r = right.top();
      right.pop();
      temp = l;
      state = 1;
    }
    else if (state == 1) {
      l = left.top();
      r = temp;
      state = 2;
    }
    else if (state == 2) {
      l = temp;
      r = right.top();

      state = 0;
    }
    std::cout << l << " " << r << std::endl;
    ans += l + r;
    m--;
  }

  std::cout << ans << std::endl;
  return 0;
}

