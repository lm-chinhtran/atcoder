//
//  pass3_c.cpp
//  learningCplusplus
//
//  Created by Tran Duc Chinh on 2020/04/04.
//  Copyright © 2020 Tran Duc Chinh. All rights reserved.
//

#include <iostream>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <math.h>
using namespace std;
typedef long long ll;
ll mod = 998244353;
ll INF = 1000000000000000000;
#define PI 3.14159265

ll limitpow (int x, int n) {
  if (n==0) return 1;
  ll u = limitpow(x, n/2);
  if (u > 1000000000 || u < 0) return -1;
  u = (u*u);
  if (u > 1000000000 || u < 0) return -1;
  if (n%2==1) u = (u*x);
  if (u > 1000000000 || u < 0) return -1;
  return u;
}

int main() {
  ll a, r, n;
  std::cin >> a >> r >> n;

  ll lim = limitpow (r, n-1);
  if (lim < 0 || a*lim > 1000000000) {
    std::cout << "large" << std::endl;
  }
  else {
    std::cout << a*lim << std::endl;
  }

  return 0;
}