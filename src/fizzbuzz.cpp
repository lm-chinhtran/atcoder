//
//  fizzbuzz.cpp
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

  ll cnt = 0;
  for (int i = 0; i < n; i++) {
    if ((i+1) % 3 != 0 && (i+1) % 5 != 0) {
      cnt += i+1;
    }
  }
  std::cout << cnt << std::endl;
  return 0;
}
