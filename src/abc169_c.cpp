//
//  abc169_c.cpp
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
  long double a, b;
  std::cin >> a >> b;

  ll ans = (ll)a*b;
  std::cout << ans << std::endl;

  return 0;
}