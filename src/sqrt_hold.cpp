//
//  sqrt_hold.cpp
//  learningCplusplus
//
//  Created by Tran Duc Chinh on 2020/04/04.
//  Copyright © 2020 Tran Duc Chinh. All rights reserved.
//

#include <iostream>
#include <math.h>
typedef long long ll;
int main(int argc, const char* argv[]) {
  ll a, b, c;
  std::cin >> a >> b >> c;

  ll l = 4*a*b;
  ll r = (c-a-b)*(c-a-b);
  if (c-a-b < 0) {
    r = -(c-a-b)*(c-a-b);
  }
    if (l < r) {
      std::cout << "Yes" << std::endl;
    }
    else {
      std::cout << "No" << std::endl;
    }

}