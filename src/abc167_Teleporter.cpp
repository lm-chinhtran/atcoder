//
//  abc167_Teleporter.cpp
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
typedef unsigned long long ll;
ll mod = 1000000007;
ll INF = 1000000007;
#define PI 3.14159265

std::map<int, int> factorization (int n) {
  std::map<int, int> f;
  for (int i = 2; i*i <= n; i++) {
    while (n%i == 0) {
      f[i] += 1;
      n /= i;
    }
  }
  if (n > 1) {
    f[n] += 1;
  }
  return f;
}

ll modpow (int x, int n) {
  if (n==0) return 1%mod;
  ll u = modpow(x, n/2);
  u = (u*u)%mod;
  if (n%2==1) u = (u*x)%mod;
  return u;
}

int main() {
  ll n, k;
  std::cin >> n >> k;
  ll a[n+1];

  ll pos[n+1];

  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }


  int start_loop = 0;
  int end_loop = 0;
  bool visited[n+1];
  bool get_end_loop = false;
  for (int i = 1; i <= n; i++) {visited[i] = false;}
  pos[0] = 1;
  pos[1] = a[1];
  visited[1] = true;
  for (int i = 2; i <= n; i++) {
    pos[i] = a[pos[i-1]];

    if (visited[pos[i]] && !get_end_loop) {
      end_loop = i;
      get_end_loop = true;
    }
    visited[pos[i-1]] = true;
  }

  for (int i = 1; i < end_loop; i++) {
    if (pos[i] == pos[end_loop]) {
      start_loop = i;
      break;
    }
  }
  if (k > n) {
    std::cout << pos[(k-start_loop)%(end_loop-start_loop) + start_loop] << std::endl;
  }
  else {
    std::cout << pos[k] << std::endl;
  }

  return 0;
}