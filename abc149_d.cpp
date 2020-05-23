//
//  abc149_d.cpp
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
  int n, k;
  ll pt[3];
  std::cin >> n >> k;
  std::cin >> pt[0] >> pt[2] >> pt[1];

  string t;
  std::cin >> t;
  std::map<char, ll> m;
  int hands[n];
  m['r'] = 0;
  m['p'] = 1;
  m['s'] = 2;

  ll ans = 0;
  for (int i = 0; i < n; i++) {
    int win = (m[t[i]] + 1) % 3;
    int cur_hand = win;
    if (i-k >= 0) {
      int last_hand = hands[i-k];
      if (cur_hand == last_hand) {
        cur_hand = (cur_hand + 1) % 3;
        if (i+k < n) {
          int next_win = (m[t[i+k]] + 1) % 3;
          if (cur_hand == next_win) cur_hand = (cur_hand + 1) % 3;
        }
      }
    }
    // std::cout << cur_hand;
    if (cur_hand == win) ans += pt[win];

    hands[i] = cur_hand;
  }
  std::cout << std::endl;
  std::cout << ans << std::endl;
  return 0;
}

