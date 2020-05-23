//
//  many_requirement.cpp
//  learningCplusplus
//
//  Created by Tran Duc Chinh on 2020/04/04.
//  Copyright © 2020 Tran Duc Chinh. All rights reserved.
//

#include <iostream>
#include <queue>
#include <math.h>
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

  ll n, m, q;
  std::cin >> n >> m >> q;
  int a[m+1];

  vector<int> A(1,1);

  dfs(A, n, m);
  return 0;
}
