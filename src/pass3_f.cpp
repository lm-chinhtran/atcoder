//
//  pass3_f.cpp
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
  int n;
  std::cin >> n;

  vector<string> a;

  for (int i = 0; i < n; i++) {
    std::string t;
    std::cin >> t;
    a.push_back(t);
  }

  string s;
  for (int i = 0; i < n/2; i++) {
    bool found = false;
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < n; k++) {
        if (a[i][j] == a[n-i-1][k]) {
          s += a[i][j];
          found = true;
          break;
        }
      }
      if (found) break;
    }
    if (!found) {
      std::cout << -1 << std::endl;
      return 0;
    }
  }

  std::string ans;
  for (int i = 0; i < s.size(); i++) {
    ans += s[i];
  }
  if (n%2 == 1) {
    ans += a[(n-1)/2][0];
  }
  for (int i = s.size()-1; i >= 0; i--) {
    ans += s[i];
  }

  std::cout << ans << std::endl;
  return 0;
}