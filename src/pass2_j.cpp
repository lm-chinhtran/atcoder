//
//  pass2_j.cpp
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
  string t;
  std::cin >> t;
  priority_queue<int> open;
  vector<pair<int, int> > v;
  vector<string> s;
  s.push_back(t);

  for (int i = 0; i < s[0].length(); i++) {
    if (s[0][i] == '(') open.push(i);
    if (s[0][i] == ')') {
      int o = open.top(); open.pop();
      v.push_back(make_pair(o, i));
    }
  }

  for (int i = 0; i < v.size(); i++) {
    string t;
    if (v[i].first > 0) for (int j = 0; j < v[i].first; j++) t.push_back(s[i][j]);
    if (v[i].second > v[i].first + 1) for (int j = v[i].first + 1; j < v[i].second; j++) t.push_back(s[i][j]);
    if (v[i].second > v[i].first + 1) for (int j = v[i].second - 1; j > v[i].first; j--) t.push_back(s[i][j]);
    if (s[i].size() > v[i].second + 1) for (int j = v[i].second + 1; j < s[i].size(); j++) t.push_back(s[i][j]);
    s.push_back(t);

    int inc = s[i+1].size() - s[i].size();
    for (int j = i+1; j < v.size(); j++) {
      if (v[j].first > v[i].first) v[j].first += inc;
      v[j].second += inc;
    }
  }
  std::cout << s[v.size()] << std::endl;
  return 0;
}