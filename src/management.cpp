//
//  management.cpp
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
    a[i] = 0;
  }
  for (int i = 1; i < n; i++) {
    int tmp;
    std::cin >> tmp;
    a[tmp-1] += 1;
  }

  for (int i = 0; i < n; i++) {
    std::cout << a[i] << std::endl;
  }

  return 0;
}
