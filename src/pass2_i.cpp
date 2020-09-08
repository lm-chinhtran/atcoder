//
//  pass2_i.cpp
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
  int n;
  std::cin >> n;
  vector<pair<int, int> > ans;
  vector<pair<int, int> > round[n + 1];

  for (int i = 0; i < pow(2, n); i++) {
    int t;
    std::cin >> t;
    round[0].push_back(make_pair(t, i));
  }

  for (int r = 1; r < n; r++) {
    for (int i = 0; i < pow(2, n - r); i++) {
      if (round[r-1][2*i].first < round[r-1][2*i+1].first) {
        ans.push_back(make_pair(round[r-1][2*i].second, r));
        round[r].push_back(round[r-1][2*i+1]);
      }
      else {
        ans.push_back(make_pair(round[r-1][2*i+1].second, r));
        round[r].push_back(round[r-1][2*i]);
      }
    }
  }
  for (auto u: round[n-1]) {
    ans.push_back(make_pair(u.second, n));
  }
  sort(ans.begin(), ans.end());
  for (auto u: ans) {
    std::cout << u.second << std::endl;
  }
  return 0;
}