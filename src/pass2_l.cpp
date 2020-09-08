//
//  pass2_l.cpp
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
  int n, k, d;
  std::cin >> n >> k >> d;
  int a[n];
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  if ((k-1)*d + 1 > n) {
    std::cout << -1 << std::endl;
    return 0;
  }

  vector<pair<int, int> > ans;
  std::set<pair<int, int> > s;

  for (int i = 0; i < n-(k-1)*d; i++) {
    s.insert(make_pair(a[i], i));
  }

  int left_ptr = 0;
  int right_ptr = n-(k-1)*d;

  for (int i = 0; i < k; i++) {
    ans.emplace_back(*s.begin());
    if (i == k-1) break;

    //insert next d elements
    for (int j = 0; j < d; j++) {
      s.insert(make_pair(a[right_ptr], right_ptr));
      right_ptr++;
    }
    //delete left of s.begin()
    while (left_ptr < ans.back().second + d && left_ptr < n) {
      s.erase(make_pair(a[left_ptr], left_ptr));
      left_ptr++;
    }
  }

  for (auto u: ans) {
    std::cout << u.first << " ";
  }
  std::cout << std::endl;

  return 0;
}