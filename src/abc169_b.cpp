//
//  abc169_b.cpp
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
  ll n;
  std::cin >> n;
  long double a[n];
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    if (a[i] == 0) {
      std::cout << 0 << std::endl;
      return 0;
    }
  }

  long double ans = 1;
  for (int i = 0; i < n; i++) {
    long double new_a = ans*a[i];
    if (new_a <= 1000000000000000000) ans = new_a;
    else {ans = -1; break;}
  }


  std::cout << (ll)ans << std::endl;

  return 0;
}