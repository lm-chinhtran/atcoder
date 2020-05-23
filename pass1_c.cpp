//
//  pass1_c.cpp
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
  std::priority_queue<int> q;
  for (int i = 0; i < 6; i++) {
    int x;
    std::cin >> x;
    q.push(x);
  }
  q.pop();
  q.pop();
  int ans = q.top();

  std::cout << ans << std::endl;
  return 0;
}

