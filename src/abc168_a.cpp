//
//  abc168_a.cpp
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
  ll n;
  std::cin >> n;

  if (n%10 == 2 || n%10 == 4 || n%10 == 5 || n%10 == 7 || n%10 == 9) {
    std::cout << "hon" << std::endl;
  }
  else if (n%10 == 0 || n%10 == 1 || n%10 == 6 || n%10 == 8) {
    std::cout << "pon" << std::endl;
  }
  else if (n%10 == 3) {
    std::cout << "bon" << std::endl;
  }
  return 0;
}

