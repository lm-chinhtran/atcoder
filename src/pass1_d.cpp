//
//  pass1_d.cpp
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
  int n;
  std::cin >> n;
  std::map<int, int> m;
  for (int i = 0; i < n; i++) {
    int a;
    std::cin >> a;
    m[a]++;
  }

  int missing = 0;
  int redundant = 0;
  for (int i = 1; i<=n; i++) {
    if(m.count(i)==0) {
      missing = i;
    }
    if(m[i]==2) {
      redundant = i;
    }
  }


  if (missing == 0 && redundant == 0) {
    std::cout << "Correct" << std::endl;
  }
  else {
    std::cout << redundant << " " << missing << std::endl;
  }
  return 0;
}

