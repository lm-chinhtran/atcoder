//
//  lunlun.cpp
//  learningCplusplus
//
//  Created by Tran Duc Chinh on 2020/04/04.
//  Copyright © 2020 Tran Duc Chinh. All rights reserved.
//

#include <iostream>

int main(int argc, const char* argv[]) {
  int k;
  std::cin >> k;
  long long a[100000];
  int i=0;
  for (i=0; i<9; i++) {
    a[i] = i+1;
  }
  int index = 0;
  while(i<k) {
    // if (a[index]%10 == 9) {
    //   a[i] = a[index]*10 + (a[index]%10 - 1);
    //   a[i+1] = a[index]*10 + (a[index]%10);
    //   i=i+2;
    // }
    // else if (a[index]%10 == 0) {
    //   a[i] = a[index]*10 + (a[index]%10);
    //   a[i+1] = a[index]*10 + (a[index]%10 + 1);
    //   i=i+2;
    // }
    // else {
    //   a[i] = a[index]*10 + (a[index]%10 - 1);
    //   a[i+1] = a[index]*10 + (a[index]%10);
    //   a[i+2] = a[index]*10 + (a[index]%10 + 1);
    //   i=i+3;
    // }
    if (a[index]%10 != 0) {
      a[i] = a[index]*10 + (a[index]%10 - 1);
      i++;
    }
    a[i] = a[index]*10 + (a[index]%10);
    i++;
    if (a[index]%10 != 9) {
      a[i] = a[index]*10 + (a[index]%10 + 1);
      i++;
    }
    index++;
  }

  // for (int i=0; i<k; i++) {
  //   std::cout << a[i] << " ";
  // }
  // std::cout << std::endl;
  // std::cout << "index " << index << std::endl;
  std::cout << a[k-1] << std::endl;
}