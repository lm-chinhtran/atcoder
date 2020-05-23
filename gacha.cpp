//
//  gacha.cpp
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

  int n;
  std::cin >> n;
  std::map<std::string, int> ma;

  for (int i = 0; i < n; i++) {
    std::string s;
    std::cin >> s;
    ma[s] = i;
  }
  std::cout << ma.size() << std::endl;

  return 0;
}
