//
//  lucky7.cpp
//  learningCplusplus
//
//  Created by Tran Duc Chinh on 2020/04/04.
//  Copyright © 2020 Tran Duc Chinh. All rights reserved.
//

#include <iostream>

using namespace std;
typedef long long ll;

int main(int argc, const char* argv[]) {
  int n;
  std::cin >> n;

  bool is_7 = false;
  while (n>0) {
    if (n%10 == 7) {
      is_7 = true;
      break;
    }
    n = (n - (n%10)) / 10;
  }

  if (is_7) {
    std::cout << "Yes" << std::endl;
  }
  else {
    std::cout << "No" << std::endl;
  }
  return 0;
}
