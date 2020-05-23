//
//  spy.cpp
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

  ll n;

  std::cin >> n;
  std::map<ll, ll> m;
  ll a[n];

  for (int i = 0; i < n; i++) {
    std::cin >> a[i];

    m[i+a[i]] += 1;
  }

  ll sum = 0;
  for (int i = 0; i < n; i++) {
    if (i > a[i]) {
      if (m.count(i-a[i])) {
        sum += m[i-a[i]];
        // std::cout << i-a[i] << " " << m[i-a[i]] << std::endl;
      }
    }
  }
  // for (std::map<ll, ll>::iterator it = m.begin(); it != m.end(); it++) {
  //   sum += it->second - 1;
  //   std::cout << it->first << " " << it->second << std::endl;
  // }

  std::cout << sum << std::endl;


  return 0;
}
