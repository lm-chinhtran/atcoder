//
//  active_infants.cpp
//  learningCplusplus
//
//  Created by Tran Duc Chinh on 2020/04/04.
//  Copyright © 2020 Tran Duc Chinh. All rights reserved.
//

#include <iostream>
#include <math.h>
#include <queue>
#include <map>
using namespace std;
typedef long long ll;
ll mod = 1000000007;


int main(int argc, const char* argv[]) {

  int n;
  std::cin >> n;
  std::priority_queue<ll> qa;
  std::map<ll, std::priority_queue<int, std::vector<int>, std::greater<int> > > ma;
  for (int i=0; i<n; i++) {
    ll in;
    std::cin >> in;
    qa.push(in);
    ma[in].push(i+1);
  }
  ll sum = 0;
  int min = 1;
  int max = n;
  for (int i=0; i<n; i++) {
    ll activeness = qa.top();
    qa.pop();
    int index = ma[activeness].top();
    ma[activeness].pop();
    std::cout << "activeness " << activeness << " ma[activeness] " << index << std::endl;
    if (index - min > max - index) {
      sum += activeness*(index - min);
      min++;
    }
    else {
      sum += activeness*(max - index);
      max--;
    }
  }
  std::cout << sum << std::endl;

  return 0;
}
