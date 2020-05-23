//
//  abc153_Fennec_Monster.cpp
//  learningCplusplus
//
//  Created by Tran Duc Chinh on 2020/04/04.
//  Copyright © 2020 Tran Duc Chinh. All rights reserved.
//

#include <iostream>
#include <queue>
#include <map>
using namespace std;
typedef long long ll;
ll mod = 1000000007;
#define PI 3.14159265


int main(int argc, const char* argv[]) {

  ll h, k;
  std::cin >> h >> k;
  std::priority_queue<ll> q;
  ll sum = 0;

  for (int i = 0; i < h; i++) {
    ll a;
    std::cin >> a;
    sum += a;
    q.push(a);

  }
  for (int i = 0; i < k; i++) {
    if (!q.empty()) {
      ll top = q.top();
      q.pop();
      sum -= top;
    }
  }

  std::cout << sum << std::endl;

  return 0;
}
