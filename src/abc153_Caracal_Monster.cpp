//
//  abc153_Caracal_Monster.cpp
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

  ll h;
  std::cin >> h;
  ll n = 1;
  ll attack = 0;
  while (h > 1) {
    // std::cout << "h " << h << " n " << n << " attack " << attack << std::endl;
    h = h/2;

    attack = attack + n;
    n = n*2;
  }


  std::cout << attack + n << std::endl;

  return 0;
}
