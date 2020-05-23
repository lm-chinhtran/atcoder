//
//  count_ball.cpp
//  learningCplusplus
//
//  Created by Tran Duc Chinh on 2020/04/04.
//  Copyright © 2020 Tran Duc Chinh. All rights reserved.
//

#include <iostream>
#include <math.h>
typedef long long ll;
int main(int argc, const char* argv[]) {
  int a, b;
  std::cin >> a >> b;

  int price_before8 = a * 100 / 8;
  int price_before10 = b * 100 / 10;

  int min = 0;
  int max = 0;
  if (price_before8 <= price_before10) {
    min = price_before8;
    max = price_before10;
  }
  else {
    min = price_before10;
    max = price_before8;
  }

  int result = -1;
  for (int i=min; i<=max+1; i++) {
    int tax8 = i * 8 / 100;
    int tax10 = i / 10 ;
    if (tax8 == a && b == tax10) {
      result = i;
      break;
    }
  }

  std::cout << result << std::endl;
}