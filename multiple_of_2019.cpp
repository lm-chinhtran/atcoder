//
//  multiple_of_2019.cpp
//  learningCplusplus
//
//  Created by Tran Duc Chinh on 2020/04/04.
//  Copyright © 2020 Tran Duc Chinh. All rights reserved.
//

#include <iostream>
#include <map>
using namespace std;
typedef long long ll;
ll mod = 1000000007;


int main(int argc, const char* argv[]) {

  std::string s;
  std::cin >> s;
  int n = s.size();
  std::map<int, int> ma;
  ma[0] = 1;

  int t[n+1];
  t[n] = 0;

  int basemod = 1;
  for (int i=n-1; i>=0; i--) {
    t[i] = (t[i+1] + (s[i] - '0')*basemod) % 2019;
    basemod = (basemod * 10) % 2019;
    ma[t[i]] += 1;

  }
  int sum = 0;
  for (int i=0; i<2019; i++) {
    if (ma.count(i)){
      // std::cout << i << ": " << ma[i] << std::endl;
    }
    sum += ma[i]*(ma[i]-1)/2;
  }
  std::cout << sum << std::endl;

  return 0;
}
