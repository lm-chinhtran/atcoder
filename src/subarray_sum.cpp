//
//  subarray_sum.cpp
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

  int n;
  std::cin >> n;

  int a[n];

  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  int best = 0;
  int sum = 0;
  for (int i = 0; i < n; i++) {
    sum = max(a[i], sum + a[i]);
    best = max(best, sum);
  }
  std::cout << best << std::endl;

  return 0;
}
