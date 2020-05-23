//
//  abc152_low_element.cpp
//  learningCplusplus
//
//  Created by Tran Duc Chinh on 2020/04/04.
//  Copyright © 2020 Tran Duc Chinh. All rights reserved.
//

#include <iostream>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;
typedef long long ll;
ll mod = 1000000007;
ll INF = 1000000007;
#define PI 3.14159265


int main() {
  int n;
  std::cin >> n;
  ll p[n];
  ll sum = 0;
  ll m = INF;

  for (int i = 0; i < n; i++) {
    std::cin >> p[i];

    if (p[i] <= m) {
      sum ++;
    }
    m = min(m, p[i]);
  }

  std::cout << sum << std::endl;
  return 0;
}