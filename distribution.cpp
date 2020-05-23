//
//  distribution.cpp
//  learningCplusplus
//
//  Created by Tran Duc Chinh on 2020/04/03.
//  Copyright © 2020 Tran Duc Chinh. All rights reserved.
//

#include <iostream>

int main(int argc, const char* argv[]) {
    int n;
    std::cin >> n;
    bool graphMatrix[n][n];
    for (int i=0; i<n; i++) {
      for (int j=0; j<n; j++) {
        graphMatrix[i][j] = 0;
      }
    }
    for (int i=0; i<n-1; i++) {
      int x, y;
      std::cin >> x >> y;
      x--;
      y--;
      graphMatrix[x][y] = 1;
      graphMatrix[y][x] = 1;
    }

    for (int i=0; i<n; i++) {
      for (int j=0; j<n; j++) {
        std::cout << graphMatrix[i][j] << " ";
      }
      std::cout << std::endl;
    }
}
