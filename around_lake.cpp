//
//  around_lake.cpp
//  learningCplusplus
//
//  Created by Tran Duc Chinh on 2020/04/01.
//  Copyright © 2020 Tran Duc Chinh. All rights reserved.
//

#include <iostream>

//int main(int argc, const char* argv[]) {
//    int k, n;
//    std::cin >> k >> n;
//    int a[n];
//    
//    if (k<2 || k>1000000) {
//        std::cout << "invalid number of K" << std::endl;
//        exit(1);
//    }
//    
//    if (n<2 || n>200000) {
//        std::cout << "invalid number of N" << std::endl;
//        exit(1);
//    }
//    
//    for (int i=0; i<n; i++) {
//        std::cin >> a[i];
//        if ((i==0 && a[i]<0) || (i>0 && a[i]<a[i-1])) {
//            std::cout << "invalid number of A" << std::endl;
//            exit(1);
//        }
//    }
//    int biggest_distance = a[0] + k - a[n-1];
//    for (int i=1; i<n; i++) {
//        int distance = a[i] - a[i-1];
//        if (biggest_distance < distance) {
//            biggest_distance = distance;
//        }
//    }
//    std::cout << k-biggest_distance << std::endl;
//}
