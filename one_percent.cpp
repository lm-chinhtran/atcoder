//
//  one_percent.cpp
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

  long double x;
  std::cin >> x;

  int n = ceil((long double)log((long double)(x/100)) / (long double)log((long double)1.01));

  int year = 0;
  ll money = 100;
  for (int i = 1; i < 2*n; i++) {
    money += money / 100;
    if (money >= x) {
      year = i;
      break;
    }
  }
  std::cout << year << std::endl;
  return 0;
}
