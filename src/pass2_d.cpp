//
//  pass2_d.cpp
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
vector<vector<int> > v;
void dfs(vector<int> A, int n, int m)  {
  if  (A.size() > n) {
    vector<int> t;
    bool valid = false;
    bool s_valid = true;
    for (int i = 1; i <= n; i++) {
      t.push_back(A[i]);
      if (A[i] != 1) valid = true;
      if (A[i] == 1 & i!=1 && i!=n && A[1]!=1 && A[n]!=1) s_valid = false;
    }
    if (valid & s_valid) v.push_back(t);
    return;
  }
  A.push_back(1);
  while (A.back() <= m) {
    dfs(A, n, m);
    A.back()++;
  }
}

int main() {
  string s;
  std::cin >> s;
  std::map<string, int> m;

  int max_length = min(3, (int)s.length());

  vector<int> A(1,1);

  dfs(A, max_length, 3);

  for (int i = 0; i < s.length() - max_length + 1; i++) {
    string t[max_length];
    for (int j = 0; j < max_length; j++) {
      t[j] = "?.";
      t[j] += s[i+j];
    }
    for (auto u: v) {
      string x;
      for (int j = 0; j < max_length; j++) {
        if (u[j]-1 == 0) continue;
        // std::cout << t[j][u[j]-1];
        x += t[j][u[j]-1];
      }
      // std::cout << std::endl;
      m[x] += 1;
    }
  }

  int ans = 0;
  for (std::map<string, int>::iterator it = m.begin(); it != m.end(); it++) {
    ans += 1;
  }

  // for (auto i: v) {
  //   for (auto j: i) {
  //     std::cout << j;
  //   }
  //   std::cout << std::endl;

  // }

  std::cout << ans << std::endl;
  return 0;
}

