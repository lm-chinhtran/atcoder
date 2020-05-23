//
//  battle.cpp
//  learningCplusplus
//
//  Created by Tran Duc Chinh on 2020/04/04.
//  Copyright © 2020 Tran Duc Chinh. All rights reserved.
//

#include <iostream>
#include <math.h>
using namespace std;
typedef long long ll;
ll mod = 1000000007;


int main(int argc, const char* argv[]) {

  int a, b, c, d;
  std::cin >> a >> b >> c >> d;

  bool takahashi = true;

  while (c > 0 & a > 0) {
    if (takahashi) {
      c = c - b;
    }
    else {
      a = a - d;
    }
    takahashi = !takahashi;
  }


  if (a > 0) {
    std::cout << "Yes" << std::endl;
  }
  else {
    std::cout << "No" << std::endl;
  }

  return 0;
}
