//
//  pass2_g.cpp
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


int main() {
  int q;
  std::cin >> q;
  std::vector<pair<char, ll> > v;

  int v_index = 0;
  std::vector<ll> results;
  for (int i = 0; i < q; i++) {
    ll t, d, x;
    char c;
    std::cin >> t;
    if (t == 1) {
      std::cin >> c >> x;
      pair<char, ll> p = make_pair(c, x);
      if (i > 1 && p.first == v[v.size()-1].first) {
        v[v.size()-1].second += p.second;
      }
      else {
        v.push_back(p);
      }
    }
    if (t == 2) {
      std::cin >> d;
      std::map<char, ll> m;
      while (d>0 && v_index < v.size()) {
        ll u = d - v[v_index].second;
        if (u >= 0) { m[v[v_index].first] += v[v_index].second; v_index++; }
        if (u < 0) { v[v_index].second -= d; m[v[v_index].first] += d; }
        d = u;
      }
      ll ans = 0;
      for (std::map<char, ll>::iterator it = m.begin(); it != m.end(); it++) {
        ans += it->second * it->second;
      }
      results.push_back(ans);
    }
  }

  for (auto u: results) {
    std::cout << u << std::endl;
  }
  return 0;
}

