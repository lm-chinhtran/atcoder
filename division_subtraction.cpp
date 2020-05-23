//
//  division_subtraction.cpp
//  learningCplusplus
//
//  Created by Tran Duc Chinh on 2020/04/04.
//  Copyright © 2020 Tran Duc Chinh. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <math.h>
using namespace std;

int countDivisors(const long n) {
  int cnt = 0;
  for (int i = 1; i <= sqrt(n); i++) {
    if (n%i == 0) {
      if (n / i == i) {
        cnt++;
        // std::cout << "i=i" << i << std::endl;
      }
      else {
        cnt = cnt + 2;
        // std::cout << i << std::endl;
        // std::cout << n/i << std::endl;
      }
    }
  }
  cnt--; // exclude 1
  return cnt;
}
int intlog(double base, double x) {
    return (int)(log(x) / log(base)) - 1;
}

int main(int argc, const char* argv[]) {
  long n;
  std::cin >> n;

  int cnt = countDivisors(n-1); // count the numer of k which n%k=1, n
  // std::cout << "n " << n << std::endl;
  for (long i = 2; i <= sqrt(n); i++) {
    if (n % i == 0) {
      long next_n = n / i;
        // std::cout << "i " << i << " next_n " << next_n << " n " << n/i << std::endl;
      while (next_n % i == 0) {
        next_n = next_n / i;
        // std::cout << "i " << i << " next_n " << next_n << std::endl;
      }
      if (next_n % i == 1) {
        // std::cout << "i " << i << " next_n " << next_n << std::endl;
        cnt++;
      }
    }
  }
  cnt++;
  std::cout << cnt << std::endl;
}