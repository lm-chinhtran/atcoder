//
//  pass3_a.cpp
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
  string s, t;
  std::cin >> s >> t;

  bool case_sensitive = false;
  bool different = false;

  for (int i = 0; i < 3; i++) {
    if (abs(s[i] - t[i]) == 32) {
      case_sensitive = true;
    }
    else if (s[i] != t[i]) {
      different = true;
    }
  }

  if (different) std::cout << "different" << std::endl;
  else if (case_sensitive) std::cout << "case-insensitive" << std::endl;
  else std::cout << "same" << std::endl;

  return 0;
}