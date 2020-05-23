//
//  string_palindrome.cpp
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

bool palindrome(const std::string s, int l, int r) {
  int numHalf = (l + r) / 2;
  bool is_palindrome = true;
  for (int i = 0; i <= numHalf; i++) {
    if (s[i] != s[r-i]) {
      is_palindrome = false;
    }
  }
  return is_palindrome;
}

int main(int argc, const char* argv[]) {
  std::string s;
  std::cin >> s;
  if (s.size() % 2 == 0) {
    exit(1);
  }
  // std::cout << palindrome(s, 0, s.size()-1) << std::endl;
  // std::cout << palindrome(s, 0, (s.size()-2)/2) << std::endl;
  // std::cout << palindrome(s, (s.size()+2)/2, s.size()-1) << std::endl;
  if (palindrome(s, 0, s.size()-1) && palindrome(s, 0, (s.size()-2)/2) && palindrome(s, (s.size()+2)/2, s.size()-1)) {
    std::cout << "Yes" << std::endl;
  }
  else {
    std::cout << "No" << std::endl;
  }

}