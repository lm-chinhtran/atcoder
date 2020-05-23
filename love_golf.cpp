//
//  love_golf.cpp
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

  int k, a, b;
  std::cin >> k >> a >> b;
  bool carry = false;

  for (int i = a; i <=b; i++) {
    if (i % k == 0) {
      carry = true;
      break;
    }
  }
  if (carry) {
    std::cout << "OK" << std::endl;
  }
  else {
    std::cout << "NG" << std::endl;
  }
  return 0;
}
