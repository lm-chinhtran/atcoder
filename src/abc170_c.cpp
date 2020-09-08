//
//  abc170_c.cpp
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
  int x, n;
  cin >> x >> n;
  std::priority_queue<int> q;

  for (int i = 0; i < n; i++) {
    int p;
    cin >> p;
    q.push(p);
  }

  int ans = 1003;
  for (int i = 101; i > -2; i--) {
    if (!q.empty()) {
      if (i == q.top()) {
        q.pop();
        continue;
      }
    }
    if (abs(i-x) <= abs(ans-x)) {
      ans = i;
    }
  }
  cout << ans << endl;
  return 0;
}