//
//  popular_vote.cpp
//  learningCplusplus
//
//  Created by Tran Duc Chinh on 2020/04/04.
//  Copyright © 2020 Tran Duc Chinh. All rights reserved.
//

#include <iostream>

int main(int argc, const char* argv[]) {
  int m, n;
  std::cin >> n >> m;
  int a[n];
  int sum = 0;
  for (int i=0; i<n; i++) {
    std::cin >> a[i];
    sum += a[i];
  }

  int num_of_popular = 0;
  for (int i=0; i<n; i++) {
    if (a[i]*(4*m) >= sum) {
      num_of_popular++;
    }
  }
  if (num_of_popular >= m) {
    std::cout << "Yes" << std::endl;
  }
  else {
    std::cout << "No" << std::endl;
  }
}