//
//  banned.cpp
//  learningCplusplus
//
//  Created by Tran Duc Chinh on 2020/04/04.
//  Copyright © 2020 Tran Duc Chinh. All rights reserved.
//

#include <iostream>
#include <map>
int main(int argc, const char* argv[]) {
  int n;

  std::cin >> n;
  std::map<long long, long long> m;
  long long A[n];
  for (int i = 0; i < n; i++) {
    std::cin >> A[i];
    if (m.find(A[i]) == m.end()) {
      m[A[i]] = 1;
    }
    else {
      m[A[i]] += 1;
    }
  }

  long long cnt = 0;
  for (std::map<long long, long long>::iterator it = m.begin(); it != m.end(); it++) {
    cnt += (it->second-1)*(it->second)/2;
  }

  for (int i = 0; i < n; i++) {
    long long result = cnt - (m[A[i]]-1);
    std::cout << result << std::endl;
  }
}