//
//  pass2_k.cpp
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
ll INF = 1000000000000000000;
#define PI 3.14159265


int main() {
  int n;
  std::cin >> n;
  string s;
  std::cin >> s;
  ll c[n], d[n];
  for (int i = 0; i < n; i++) {
    std::cin >> c[i];
  }
  for (int i = 0; i < n; i++) {
    std::cin >> d[i];
  }

  ll dp[s.size()][s.size()+1];
  for (int i = 0; i < s.size()+1; i++) {
    dp[0][i] = INF;
  }
  if (s[0] == ')') {
    dp[0][0] = d[0];
    dp[0][1] = c[0];
  }
  else {
    dp[0][0] = d[0];
    dp[0][1] = 0;
  }

  for (int i = 1; i < s.size(); i++) {
    for (int j = 0; j < s.size()+1; j++) {
      if (s[i] == ')') { // -1
        ll keep = INF; // keep
        ll remove = dp[i-1][j] + d[i]; // remove
        ll change = INF; // change
        if (j>0) change = dp[i-1][j-1] + c[i];
        if (j+1<s.size()+1) keep = dp[i-1][j+1];
        ll t = min (keep, remove);
        dp[i][j] = min(t, change);
      }
      else if (s[i] == '(') {
        ll keep = INF; // keep
        ll remove = dp[i-1][j] + d[i]; // remove
        ll change = INF; // change
        if (j>0) keep = dp[i-1][j-1];
        if (j+1<s.size()+1) change = dp[i-1][j+1] + c[i];
        ll t = min (keep, remove);
        dp[i][j] = min(t, change);
      }
    }
  }

  std::cout << dp[s.size()-1][0] << std::endl;
  // priority_queue<int> open;
  // priority_queue<int> close;
  // vector<int> vo;
  // vector<int> vc;

  // for (int i = 0; i < s.length(); i++) {
  //   if (s[i] == '(') open.push(i);
  //   if (s[i] == ')') {
  //     if (!open.empty()) {
  //       open.pop();
  //     }
  //     else {
  //       close.push(i);
  //     }
  //   }
  // }

  // ll ans1 = 0;
  // if (!open.empty()) {
  //   while (!open.empty()) {
  //     vo.push_back(open.top());
  //     open.pop();
  //   }
  //   sort(vo.begin(), vo.end());
  //   ll dpo[vo.size()][vo.size()+1];
  //   for (int i = 0; i < vo.size()+1; i++) {
  //     dpo[0][i] = INF;
  //   }
  //   dpo[0][vo.size()] = 0; // keep
  //   dpo[0][vo.size()-1] = d[vo[0]]; // delete
  //   dpo[0][vo.size()-2] = c[vo[0]]; // change
  //   for (int i = 1; i < vo.size(); i++) {
  //     for (int j = 0; j < vo.size()+1; j++) {
  //       ll dpojp1 = INF;
  //       ll dpojp2 = INF;
  //       if (j+1 < vo.size()+1) dpojp1 = dpo[i-1][j+1];
  //       if (j+2 < vo.size()+1) dpojp2 = dpo[i-1][j+2];
  //       ll t = min(dpo[i-1][j], dpojp1 + d[vo[i]]);
  //       dpo[i][j] = min(t, dpojp2 + c[vo[i]]);
  //     }
  //   }
  //   ans1 = dpo[vo.size()-1][0];
  // }

  // ll ans2  = 0;
  // if (!close.empty()) {
  //   while (!close.empty()) {
  //     vc.push_back(close.top());
  //     close.pop();
  //   }
  //   sort(vc.begin(), vc.end());
  //   ll dpc[vc.size()][vc.size()+1];
  //   for (int i = 0; i < vc.size()+1; i++) {
  //     dpc[0][i] = INF;
  //   }
  //   dpc[0][vc.size()] = 0; // keep
  //   dpc[0][vc.size()-1] = d[vc[0]]; // delete
  //   dpc[0][vc.size()-2] = c[vc[0]]; // change
  //   for (int i = 1; i < vc.size(); i++) {
  //     for (int j = 0; j < vc.size()+1; j++) {
  //       ll dpcjp1 = INF;
  //       ll dpcjp2 = INF;
  //       if (j+1 < vc.size()+1) dpcjp1 = dpc[i-1][j+1];
  //       if (j+2 < vc.size()+1) dpcjp2 = dpc[i-1][j+2];
  //       ll t = min(dpc[i-1][j], dpcjp1 + d[vc[i]]);
  //       dpc[i][j] = min(t, dpcjp2 + c[vc[i]]);
  //     }
  //   }
  //   ans2 = dpc[vc.size()-1][0];
  // }
  // std::cout << ans1 + ans2 << std::endl;


  return 0;
}