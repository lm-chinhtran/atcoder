//
//  discount_ticket.cpp
//  learningCplusplus
//
//  Created by Tran Duc Chinh on 2020/04/04.
//  Copyright © 2020 Tran Duc Chinh. All rights reserved.
//

#include <iostream>
#include <queue>
#include <math.h>
using namespace std;
typedef long long ll;
ll mod = 1000000007;
#define PI 3.14159265

int main(int argc, const char* argv[]) {

  double n, m;
  std::cin >> n >> m;
  std::priority_queue<ll> q;
  ll sum = 0;
  for (int i = 0; i < n; i++) {
    ll a;
    std::cin >> a;
    q.push(a);
    sum += a;
  }

  while (m>0) {
    ll a = q.top();
    // std::cout << " " << a << std::endl;
    q.pop();
    sum -= (a+2-1)/2;
    q.push(a/2);
    m -= 1;
  }

  std::cout << sum << std::endl;
  return 0;
}
