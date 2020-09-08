//
//  pass2_c.cpp
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
  int n;
  std::cin >> n;
  char s[n][2*n-1];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 2*n-1; j++) {
      std::cin >> s[i][j];
    }
  }

  for (int i = n-2; i >= 0; i--) {
    for (int j = 1; j < 2*n-2; j++) {
      if (s[i][j] == '#') {
        if (s[i+1][j-1] == 'X' || s[i+1][j] == 'X' || s[i+1][j+1] == 'X') {
          s[i][j] = 'X';
        }
      }
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 2*n-1; j++) {
      std::cout << s[i][j];
    }
    std::cout << std::endl;
  }
  return 0;
}

