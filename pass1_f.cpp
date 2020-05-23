//
//  pass1_f.cpp
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
  std::string s;
  std::cin >> s;
  std::vector<std::string> ans;
  std::vector<pair<int, int> > v;

  int begin = 0;
  int end = 1;
  while (end < s.size()) {
    if (isupper(s[end])) {
      v.push_back(make_pair(begin, end));
      begin = end + 1;
      end++;
    }
    end++;
  }
  for (auto p: v) {
    string t;
    for (int i=p.first; i<p.second; i++) {
      t.push_back(s[i]);
    }
    t.push_back(s[p.second]+32);
    ans.push_back(t);
    // std::cout << t << std::endl;
  }
  sort(ans.begin(), ans.end());
  for (auto t: ans) {
    for(int i=0; i < t.size()-1; i++) {
      std::cout << t[i];
    }
    char c = t[t.size()-1]-32;
    std::cout << c;
  }
  std::cout << std::endl;
  return 0;
}

