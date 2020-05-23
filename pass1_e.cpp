//
//  pass1_e.cpp
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
  int n, q;
  std::cin >> n >> q;
  std::vector<int> followed[n+1];
  std::vector<int> following[n+1];
  std::vector<int> f_following[n+1];

  for (int i = 0; i < q; i++) {
    int s0;
    std::cin >> s0;
    if (s0 == 1) {
      int s1, s2;
      std::cin >> s1 >> s2;
      int a = s1;
      int b = s2;
      followed[b].push_back(a);
      following[a].push_back(b);
      for (auto u: following[b]) {
        if (u != a) f_following[a].push_back(u);
      }
    }
    if (s0 == 2) {
      int s1;
      std::cin >> s1;
      int a = s1;
      for (auto u: followed[a]) {
        following[a].push_back(u);
        followed[u].push_back(a);
      }
    }
    if (s0 == 3) {
      int s1;
      std::cin >> s1;
      int a = s1;
      std::vector<int> n;
      for (auto x: following[a]) {
        for (auto u: following[x]) {
          if (u != a) {
            n.push_back(u);
          }
        }
      }
      for (auto u: n) {
        following[a].push_back(u);
        followed[u].push_back(a);
      }
    }
  }

  for (int a=1; a<=n; a++) {
    for (int i = 1; i <= n; i++) {
      bool founded = false;
      for (auto u: following[a]) {
        if (u==i) founded = true;
      }
      if (!founded) std::cout << "N";
      else std::cout << "Y";
    }
    std::cout << std::endl;
  }
  return 0;
}

