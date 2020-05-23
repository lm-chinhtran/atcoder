//
//  water_bottle.cpp
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

  double a, b, x;
  std::cin >> a >> b >> x;
  double tan = (double)a*b*b/(2*x);
  if (x > a*a*b/2) {
    tan = (double)((2*a*a*b-2*x)/(a*a*a));
  }
  double result = atan(tan) * 180 / PI;
  printf("%.9f\n", result);
  return 0;
}
