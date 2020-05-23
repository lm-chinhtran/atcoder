//
//  homework.cpp
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

  int n, m;
  std::cin >> n >> m;
  int a[m];
  int assignment_day = 0;
  for (int i = 0; i < m ; i++) {
    std::cin >> a[i];
    assignment_day += a[i];
  }
  if (n>=assignment_day) {
    std::cout << n-assignment_day << std::endl;
  }
  else {
    std::cout << -1 << std::endl;
  }

  return 0;
}
