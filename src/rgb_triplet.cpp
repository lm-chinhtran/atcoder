//
//  rgb_triplet.cpp
//  learningCplusplus
//
//  Created by Tran Duc Chinh on 2020/04/04.
//  Copyright © 2020 Tran Duc Chinh. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int main(int argc, const char* argv[]) {
  int n;
  std::string s;
  std::cin >> n;
  std::cin >> s;

  int r = 0;
  int g = 0;
  int b = 0;

  for (int i = 0; i < n; i++) {
    if (s[i] == 'R') {
      r++;
    }
    else if (s[i] == 'G') {
      g++;
    }
    else if (s[i] == 'B') {
      b++;
    }
  }

  ll cnt = r*g*b;
  for (int i = 0; i < n; i++) {
    for (int j = i+1; j < n; j++) {
      int k = j + (j-i);
      if (s[i] != s[j] && s[i] != s[k] && s[j] != s[k] && k<n) {
        cnt--;
      }
    }
  }
  std::cout << cnt << std::endl;
  return 0;
}
