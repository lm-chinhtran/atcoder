//
//  string_formation.cpp
//  learningCplusplus
//
//  Created by Tran Duc Chinh on 2020/04/04.
//  Copyright © 2020 Tran Duc Chinh. All rights reserved.
//

#include <iostream>
#include <string>
#include<algorithm>
typedef long long ll;
int main(int argc, const char* argv[]) {
  std::string s;
  int q;
  std::cin >> s;
  std::cin >> q;

  int reverse_time = 0;

  for (int i=0; i<q; i++) {
    int t;
    int f;
    char c;
    std::cin >> t;
    if (t == 1) {
      // std::reverse(s.begin(), s.end());
      reverse_time += 1;
    }
    else if (t == 2) {
      std::cin >> f;
      std::cin >> c;
      if (f == 1) {
        if (reverse_time % 2 == 0) {
          s.insert(s.begin(), 1, c);
        }
        else {
          s.push_back(c);
        }
      }
      else if (f == 2) {
        if (reverse_time % 2 == 0) {
          s.push_back(c);
        }
        else {
          s.insert(s.begin(), 1, c);
        }
      }
    }

  }
  if (reverse_time % 2 == 1) {
    std::reverse(s.begin(), s.end());
  }
  std::cout << s << std::endl;
}