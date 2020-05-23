//
//  replacing_integer.cpp
//  learningCplusplus
//
//  Created by Tran Duc Chinh on 2020/04/04.
//  Copyright © 2020 Tran Duc Chinh. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(int argc, const char* argv[]) {
  int n, k, c;
  string s;
  std::vector<int> work_day;
  std::vector<int> l;
  std::vector<int> r;
  std::vector<int> bounded;
  std::cin >> n >> k >> c;
  std::cin >> s;
  for (int i=0; i<n; i++) {
    if (s[i]=='x') continue;
    work_day.push_back(i+1);
  }

  l.push_back(work_day[0]);
  for (int i=1; i<work_day.size(); i++) {
    if (work_day[i] - l[l.size()-1] > c) {
      l.push_back(work_day[i]);
    }
  }

  r.push_back(work_day[work_day.size()-1]);
  for (int i=work_day.size()-2; i>=0; i--) {
    if (r[r.size()-1] - work_day[i] > c) {
      r.push_back(work_day[i]);
    }
  }

  for (int i = 0; i <k; i++) {
    if (l[i] == r[k-1-i]) {
      std::cout << l[i] << std::endl;
    }
  }
}