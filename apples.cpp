//
//  apples.cpp
//  learningCplusplus
//
//  Created by Tran Duc Chinh on 2020/04/02.
//  Copyright © 2020 Tran Duc Chinh. All rights reserved.
//

#include <iostream>
#include <queue>

int main(int argc, const char* argv[]) {
    int x, y, a, b, c;
    std::cin >> x >> y >> a >> b >> c;
    std::priority_queue<int> qa, qb, qc;

    for (int i=0; i<a; i++) {
        int in;
        std::cin >> in;
        qa.push(in);
    }
    for (int i=0; i<b; i++) {
        int in;
        std::cin >> in;
        qb.push(in);
    }
    for (int i=0; i<c; i++) {
        int in;
        std::cin >> in;
        qc.push(in);
    }
    
    for (int i=0; i<x; i++) {
        qc.push(qa.top());
        qa.pop();
    }
    for (int i=0; i<y; i++) {
        qc.push(qb.top());
        qb.pop();
    }
    
    long result = 0;
    for (int i=0; i<x+y; i++) {
        result += qc.top();
        qc.pop();
    }
    
    std::cout << result << std::endl;
}
