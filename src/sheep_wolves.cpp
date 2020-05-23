//
//  sheep_wolves.cpp
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

  int s, w;
  std::cin >> s >> w;

  if (w >= s) {
    std::cout << "unsafe" << std::endl;
  }
  else {
    std::cout << "safe" << std::endl;
  }

  return 0;
}
