//
//  pass3_b.cpp
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


int main() {
  int n, m, q;
  std::cin >> n >> m >> q;
  std::map<int, int> problems[m];

  int score[m];
  vector<int> ans;
  for (int i = 0; i < m; i++) score[i] = n;
  for (int i = 0; i < q; i++) {
    int t;
    std::cin >> t;
    if (t == 2) {
      int p, prob;
      std::cin >> p >> prob;
      for (std::map<int, int>::iterator it = problems[prob-1].begin(); it != problems[prob-1].end(); it++) {
        problems[prob-1][it->first] = it->second - 1;
      }
      score[prob-1]--;
      problems[prob-1][p-1] = score[prob-1];
      // std::cout << " score[prob-1] " <<  score[prob-1] << std::endl;
    }
    else if (t == 1) {
      int p; std::cin >> p;
      int s = 0;
      for (int j = 0; j < m; j++) {
        if (problems[j].count(p-1)) {
          s +=  problems[j][p-1];
        }
      }
      ans.push_back(s);
    }
  }
  for (auto u: ans) {
    std::cout << u << std::endl;
  }

  return 0;
}