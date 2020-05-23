//
//  abc151_c.cpp
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
  int n, m;
  std::cin >> n >> m;

  std::vector<string> p[n+1];

  for (int i = 0; i < m; i++) {
    int t;
    string s;
    std::cin >> t;
    std::cin >> s;

    int size = p[t].size();
    if (size > 0) {
      string last = p[t][size-1];
      if (last.compare("AC")) {
        p[t].push_back(s);
      }
    }
    else {
      p[t].push_back(s);
    }
  }

  int pen = 0;
  int ac = 0;
  for (int i = 1; i <= n; i++) {
    int size = p[i].size();
    if (size > 0) {
      string last = p[i][p[i].size()-1];
      if (last.compare("AC") == 0) {
        ac += 1;
        pen += size - 1;
      }
    }
  }

  std::cout << ac << " " << pen << std::endl;

  return 0;
}