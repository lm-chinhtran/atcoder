//
//  abc152_handstands.cpp
//  learningCplusplus
//
//  Created by Tran Duc Chinh on 2020/04/04.
//  Copyright © 2020 Tran Duc Chinh. All rights reserved.
//

#include <iostream>
#include <queue>
#include <map>
#include <algorithm>
#include <math.h>
using namespace std;
typedef long long ll;
ll mod = 1000000007;
ll INF = 1000000007;
#define PI 3.14159265

int firstDigit(int n)
{
    // Find total number of digits - 1
    int digits = (int)log10(n);

    // Find first digit
    n = (int)(n / pow(10, digits));

    // Return first digit
    return n;
}

int main() {
  int n;
  std::cin >> n;
  int c[10][10];

  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      c[i][j] = 0;
    }
  }

  ll sum = 0;
  for (int i = 1; i <= n; i++) {
    int firstD = firstDigit(i);
    int lastD = i % 10;
    c[firstD][lastD] += 1;
  }

  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      sum += c[i][j]*c[j][i];
    }
  }

  std::cout << sum << std::endl;
  return 0;
}