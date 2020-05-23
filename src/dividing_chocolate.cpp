//
//  dividing_chocolate.cpp
//  learningCplusplus
//
//  Created by Tran Duc Chinh on 2020/04/04.
//  Copyright © 2020 Tran Duc Chinh. All rights reserved.
//

#include <iostream>
#include <vector>

int solve(const std::vector<std::vector<bool> > v, int startX, int startY, int endX, int endY, int k) {
  int i = startX;
  int j = startY;
  int cnt = 0;
  while (cnt < k) {

  }
}
int main(int argc, const char* argv[]) {
  int h, w, k;
  std::cin >> h >> w >> k;
  std::vector< std::vector<bool> > v;

  int total_white = 0;
  for (int i = 0; i < h; i++) {
    std::string s;
    std::cin >> s;
    std::vector<bool> temp;
    for (int j = 0; j < w; j++) {
      temp.push_back((s[j]) - '0');
      total_white += (s[j]) - '0';
    }
    v.push_back(temp);
  }
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      std::cout << v[i][j];
    }
    std::cout << std::endl;
  }
  std::cout << total_white << std::endl;
}