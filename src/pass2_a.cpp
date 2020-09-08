//
//  pass2_a.cpp
//  learningCplusplus
//
//  Created by Tran Duc Chinh on 2020/04/04.
//  Copyright © 2020 Tran Duc Chinh. All rights reserved.
//

#include <iostream>
#include <queue>
#include <map>
#include <algorithm>
#include <math.h>
using namespace std;
typedef long long ll;
ll mod = 1000000007;
ll INF = 1000000007;
#define PI 3.14159265

const int MAX = 110000;

ll fac[MAX], finv[MAX], inv[MAX];

std::vector<int> permutations;

int gcd(int a, int b) {
   if (b == 0)
      return a;
   return gcd(b, a % b);
}



int main() {
  std::map<string, int> p;
  p.insert(make_pair("B9", 0));
  p.insert(make_pair("B8", 1));
  p.insert(make_pair("B7", 2));
  p.insert(make_pair("B6", 3));
  p.insert(make_pair("B5", 4));
  p.insert(make_pair("B4", 5));
  p.insert(make_pair("B3", 6));
  p.insert(make_pair("B2", 7));
  p.insert(make_pair("B1", 8));
  p.insert(make_pair("1F", 9));
  p.insert(make_pair("2F", 10));
  p.insert(make_pair("3F", 11));
  p.insert(make_pair("4F", 12));
  p.insert(make_pair("5F", 13));
  p.insert(make_pair("6F", 14));
  p.insert(make_pair("7F", 15));
  p.insert(make_pair("8F", 16));
  p.insert(make_pair("9F", 17));

  string s, t;
  std::cin >> s >> t;

  std::cout << abs(p[s] - p[t]) << std::endl;
  return 0;
}

