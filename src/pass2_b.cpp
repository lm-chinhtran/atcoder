//
//  pass2_b.cpp
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
  string s;
  std::cin >> s;

  int a = 0;
  int b = 0;
  int c = 0;

  for (int i = 0; i < s.length(); i++) {
    if (s[i] == 'a') {
      a++;
    }
    else if (s[i] == 'b') {
      b++;
    }
    else if (s[i] == 'c') {
      c++;
    }
  }
  if (a > b && a > c) {
    std::cout << "a" << std::endl;
  }
  if (b > a && b > c) {
    std::cout << "b" << std::endl;
  }
  if (c > a && c > b) {
    std::cout << "c" << std::endl;
  }
  return 0;
}

