//
//  abc152_compare_strings.cpp
//  learningCplusplus
//
//  Created by Tran Duc Chinh on 2020/04/04.
//  Copyright © 2020 Tran Duc Chinh. All rights reserved.
//

#include <iostream>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;
typedef long long ll;
ll mod = 1000000007;
#define PI 3.14159265


int main() {
  int a, b;
  std::cin >> a >> b;

  if (a>b) {
    for (int i=0; i<a; i++) {
      std::cout << b;
    }
    std::cout << std::endl;
  }
  else {
    for (int i=0; i<b; i++) {
      std::cout << a;
    }
    std::cout << std::endl;
  }
  return 0;
}