//
//  abc153_Serval_Monster.cpp
//  learningCplusplus
//
//  Created by Tran Duc Chinh on 2020/04/04.
//  Copyright © 2020 Tran Duc Chinh. All rights reserved.
//

#include <iostream>
#include <queue>
#include <map>
using namespace std;
typedef long long ll;
ll mod = 1000000007;
#define PI 3.14159265


int main(int argc, const char* argv[]) {

  int h, a;
  std::cin >> h >> a;

  int sum = (h + a - 1) / a;
  std::cout << sum << std::endl;


  return 0;
}
