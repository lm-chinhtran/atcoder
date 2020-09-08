//
//  pass3_d.cpp
//  learningCplusplus
//
//  Created by Tran Duc Chinh on 2020/04/04.
//  Copyright © 2020 Tran Duc Chinh. All rights reserved.
//

#include <iostream>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <math.h>
using namespace std;
typedef long long ll;
ll mod = 998244353;
ll INF = 1000000000000000000;
#define PI 3.14159265

ll limitpow (int x, int n) {
  if (n==0) return 1;
  ll u = limitpow(x, n/2);
  if (u > 1000000000 || u < 0) return -1;
  u = (u*u);
  if (u > 1000000000 || u < 0) return -1;
  if (n%2==1) u = (u*x);
  if (u > 1000000000 || u < 0) return -1;
  return u;
}

int main() {
  int n;
  std::cin >> n;

  std::vector<string> pattern;
  pattern.push_back(".###.#.#.#.#.#.#.###");
  pattern.push_back("..#..##...#...#..###");
  pattern.push_back(".###...#.###.#...###");
  pattern.push_back(".###...#.###...#.###");
  pattern.push_back(".#.#.#.#.###...#...#");
  pattern.push_back(".###.#...###...#.###");
  pattern.push_back(".###.#...###.#.#.###");
  pattern.push_back(".###...#...#...#...#");
  pattern.push_back(".###.#.#.###.#.#.###");
  pattern.push_back(".###.#.#.###...#.###");

  std::string s[5];
  std::vector<int> ans;
  for (int i = 0; i < 5; i++) {
    std::cin >> s[i];
  }

  for (int j = 0; j < n; j++) {
    string t;
    for (int i = 0; i < 5; i++) {
      t += s[i][j*4];
      t += s[i][j*4+1];
      t += s[i][j*4+2];
      t += s[i][j*4+3];
    }
    for (int i = 0; i < 10; i++) {
      if (t == pattern[i]) {
        ans.push_back(i);
      }
    }
  }

  for (auto u: ans) {
    std::cout << u;
  }
  std::cout << std::endl;
  return 0;
}