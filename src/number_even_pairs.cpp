//
//  number_even_pairs.cpp
//  learningCplusplus
//
//  Created by Tran Duc Chinh on 2020/04/04.
//  Copyright © 2020 Tran Duc Chinh. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <math.h>
using namespace std;

int main(int argc, const char* argv[]) {
  int n, m;
  std::cin >> n >> m;

  std::cout << n*(n-1)/2 + m*(m-1)/2 << std::endl; // combination of 2 n, and combination of 2 m
}