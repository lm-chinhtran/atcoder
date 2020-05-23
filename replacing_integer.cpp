//
//  replacing_integer.cpp
//  learningCplusplus
//
//  Created by Tran Duc Chinh on 2020/04/04.
//  Copyright © 2020 Tran Duc Chinh. All rights reserved.
//

#include <iostream>

int main(int argc, const char* argv[]) {
  long long n, k;
  std::cin >> n >> k;
  long long result = n%k;

  if(k - result < result) {
      result = k - result;
  }
  std::cout << result << std::endl;
}