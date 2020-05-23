//
//  floor_function.cpp
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

  ll a, b, n;
  std::cin >> a >> b >> n;

  ll x = b - 1;
  if (x > n) {
    x = n;
  }
  ll first = (a*x)/b;
  ll second = x/b;
  ll result = first - a * second;


  std::cout << result << std::endl;
  return 0;
}
