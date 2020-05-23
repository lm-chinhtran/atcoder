//
//  sum_gcd.cpp
//  learningCplusplus
//
//  Created by Tran Duc Chinh on 2020/04/04.
//  Copyright © 2020 Tran Duc Chinh. All rights reserved.
//

#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

int gcd(int a, int b) {
   if (b == 0)
      return a;
   return gcd(b, a % b);
}

int main(int argc, const char* argv[]) {
  int n;
  std::cin >> n;

  ll cnt = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < n; k++) {
        cnt += gcd(gcd(i+1, j+1), k+1);
      }
    }
  }
  std::cout << cnt << std::endl;
  return 0;
}
