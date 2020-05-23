//
//  abc151_b.cpp
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
  int n, k, m;
  std::cin >> n >> k >> m;

  int pt = 0;
  for (int i = 0; i < n-1; i++) {
    int a;
    std::cin >> a;
    pt += a;
  }

  int score = m*n - pt;
  if (score < 0) { score = 0; }
  if (score > k) { score = -1; }

  std::cout << score << std::endl;


  return 0;
}