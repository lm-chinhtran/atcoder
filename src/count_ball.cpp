//
//  count_ball.cpp
//  learningCplusplus
//
//  Created by Tran Duc Chinh on 2020/04/04.
//  Copyright © 2020 Tran Duc Chinh. All rights reserved.
//

#include <iostream>
#include <math.h>
typedef long long ll;
int main(int argc, const char* argv[]) {
  ll n, a, b;
  std::cin >> n >> a >> b;

  ll total = 0;
  if (a!=0 || b!=0) {
    ll blue_time = n/(a+b);
    total = blue_time * a;
    if (n%(a+b) < a) {
      total += n%(a+b);
    }
    else {
      total += a;
    }
  }

  std::cout << total << std::endl;
}