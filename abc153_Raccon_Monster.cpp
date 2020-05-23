//
//  abc153_Raccon_Monster.cpp
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

  ll h, n;
  std::cin >> h >> n;

  ll sum = 0;
  for (int i = 0; i < n; i++) {
    ll a;
    std::cin >> a;
    sum += a;
  }

  if (sum >= h) {
    std::cout << "Yes" << std::endl;
  }
  else {
    std::cout << "No" << std::endl;
  }

  return 0;
}
