//
//  trick_or_treat.cpp
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
void dfs(vector<int> A, int n, int m)  {
  if  (A.size() > n) {
    for (int i = 1; i <= n; i++) {
      std::cout << A[i];
    }
    std::cout << std::endl;
    return;
  }
  A.push_back(A.back());
  while (A.back() <= m) {
    dfs(A, n, m);
    A.back()++;
  }
}

int main(int argc, const char* argv[]) {

  int n, k;
  std::cin >> n >> k;
  std::map<int, int> m;

  for (int i = 0; i < k; i++) {
    int d;
    std::cin >> d;
    for (int j = 0; j < d; j++) {
      int snuck;
      std::cin >> snuck;
      m[snuck] = 1;
    }
  }
  int sum = 0;
  for (int i = 1; i <= n; i++) {
    if(m.count(i)==0) {
      sum++;
    }
  }
  std::cout << sum << std::endl;

  return 0;
}
