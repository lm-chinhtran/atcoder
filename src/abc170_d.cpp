//
//  abc170_d.cpp
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
  cin >> n;
  set<int> s;

  for (int i = 0; i < n; i++) {
    int p;
    cin >> p;
    vector<int> e;
    bool add = true;
    for (auto u: s) {
      if (u%p==0) e.push_back(u);
      if (p%u==0) add = false;
    }
    for (auto u: e) {
      s.erase(u);
    }
    if (add) s.insert(p);
  }

  cout << s.size() << endl;
  return 0;
}