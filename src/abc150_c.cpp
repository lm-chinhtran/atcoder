//
//  abc150_c.cpp
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

void permute(int *a, int l, int r)
{
    // Base case
    if (l == r) {
      int number=0;
      for (int i = 0; i <= r; i++) {
        number = number*10 + a[i];
      }
      permutations.push_back(number);
    }
    else
    {
        // Permutations made
        for (int i = l; i <= r; i++)
        {

            // Swapping done
            swap(a[l], a[i]);

            // Recursion called
            permute(a, l+1, r);

            //backtrack
            swap(a[l], a[i]);
        }
    }
}


int main() {
  int n;
  std::cin >> n;
  int p=0;
  int q=0;
  int a[n];

  for (int i = 0; i < n; i++) {
    int t;
    std::cin >> t;
    p = p*10 + t;
  }
  for (int i = 0; i < n; i++) {
    int t;
    std::cin >> t;
    q = q*10 + t;
  }
  for (int i = 0; i < n; i++) {
    a[i] = i+1;
  }


  permute(a, 0, n-1);
  sort(permutations.begin(), permutations.end());

  int x = 0;
  int y = 0;
  int i = 0;
  for (auto u: permutations) {
    if (u == p) {
      x = i;
    }
    if (u == q) {
      y = i;
    }
    i++;
  }

  std::cout << abs(x-y) << std::endl;

  return 0;
}

