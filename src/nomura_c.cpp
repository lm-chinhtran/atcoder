//
//  nomura_c.cpp
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
ll mod = 998244353;
ll INF = 1000000007;
#define PI 3.14159265


int main() {
  int n;
  cin >> n;
  ll a[100001];
  ll sum[100001];

  for (int i = 0; i <= n; i++) {
    cin >> a[i];
    if (i>0) sum[i] = sum[i-1] + a[i];
    else sum[i] = a[i];
    if (i==0 && a[i]!=0 && !(a[i]==1 && n==0)) {
      cout << -1 << endl;
      return 0;
    }
  }

  ll ans = 1;
  ll nodes = 1;
  for (int i = 1; i <= n; i++) {
    if (nodes < a[i-1]) {
      std::cout << -1 << std::endl;
      return 0;
    }
    nodes = 2*(nodes - a[i-1]);
    if (nodes < a[i]) {
      std::cout << -1 << std::endl;
      return 0;
    }
    nodes = min(nodes, sum[n]-sum[i-1]);
    ans += nodes;
  }

  cout << ans << endl;
  return 0;
}