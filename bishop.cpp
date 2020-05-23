//
//  bishop.cpp
//  learningCplusplus
//
//  Created by Tran Duc Chinh on 2020/04/04.
//  Copyright © 2020 Tran Duc Chinh. All rights reserved.
//

#include <iostream>
typedef long long ll;
int main(int argc, const char* argv[]) {
  ll h, w;
  std::cin >> h >> w;

  ll odd_in_row = w / 2 + w % 2;
  ll even_in_row = w - odd_in_row;

  ll odd_in_col = h / 2 + h % 2;
  ll even_in_col = h - odd_in_col;

  ll sum = odd_in_row * odd_in_col + even_in_row * even_in_col;
  if (h == 1 || w == 1) {
    sum = 1;
  }

  std::cout << sum << std::endl;
}