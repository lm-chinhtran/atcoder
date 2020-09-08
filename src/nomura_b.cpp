//
//  nomura_b.cpp
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
  cin >> t;

  string ans;
  for (int i = 0; i < t.length(); i++) {
    if (t[i] == '?') ans += 'D';
    else ans += t[i];
  }

  cout << ans << endl;



  return 0;
}