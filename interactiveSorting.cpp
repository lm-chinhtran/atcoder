//
//  interactiveSorting.cpp
//  learningCplusplus
//
//  Created by Tran Duc Chinh on 2020/03/23.
//  Copyright © 2020 Tran Duc Chinh. All rights reserved.
//

#include <iostream>
#include <map>
#include <string>

void quicksort(std::string& s, int l, int r, int* index) {
    if (l >= r) {
        return;
    }
    int cnt = l;
    
    char pivot = s[r];
    for (int i = l; i < r; i++) {
        printf("? %c %c\n", s[i], pivot);
        fflush(stdout);
        char ans;
        std::cin >> ans;
        
        if(ans == '<') {
            std::swap(s[cnt], s[i]);
            std::swap(index[cnt], index[i]);
            cnt++;
        }
    }
    std::swap(s[cnt], s[r]);
    std::swap(index[cnt], index[r]);
    quicksort(s, l, cnt - 1, index);
    quicksort(s, cnt + 1, r, index);
}

void group(std::string& s, int n, std::string& temp) {
    int num_half = n / 2;
    for (int i=0; i<num_half; i++) {
        printf("? %c %c\n", s[i*2], s[i*2+1]);
        fflush(stdout);
        char ans;
        std::cin >> ans;
        if(ans == '>') {
            std::swap(s[i*2], s[i*2+1]);
        }
        temp += s[i*2+1];
    }
}

int insertion(std::string& s, int l, int r, char c) {
    int L = l;
    int R = r;
    int m = 0;
    while (L <= R) {
        m = (L + R) / 2;
        printf("? %c %c\n", c, s[m]);
        fflush(stdout);
        char ans;
        std::cin >> ans;
        if (ans == '<') {
            R = m - 1;
        }
        else {
            if (L == R) {
                m = m + 1;
            }
            L = m + 1;
        }
    }
    
    int size = (int)s.size();
    s += s[size-1];
    for (int i=size-1; i>m; i--) {
        s[i] = s[i-1];
    }
    s[m] = c;
    return m;
}
void merge_insertion_sort(std::string& s, int n, std::string& tmp) {
    std::map<int, int> index_mapping; // <group index, index in sorted string>
    
    // group sort n/2 pair of elements
    group(s, n, tmp);
    int group_index [n/2];
    for (int i=0; i<n/2; i++) {
        group_index [i] = i;
    }
    quicksort(tmp, 0, n/2 - 1, group_index);
    
    // insert the element that was paired with the smallest element of tmp
    tmp += tmp[n/2-1];
    for (int i=n/2-1; i>0; i--) {
        tmp[i] = tmp[i-1];
    }
    tmp[0] = s[group_index[0]*2];
    for (int i=1; i<n/2; i++) {
        index_mapping[group_index[i]] = i + 1;
    }
    
    int insert_idx = 0;
    // insert the last unpair if any
    if (n%2 == 1) {
        insert_idx = insertion(tmp, 0, (int)tmp.size() - 1, s[n-1]);
        for (int i=1; i<n/2; i++) {
            if (insert_idx <= index_mapping.at(group_index[i])) {
                index_mapping[group_index[i]]++;
            }
        }
    }
    
    // insert remaining
    for (int i=n/2-1; i>0; i--) {
        insert_idx = insertion(tmp, 0, index_mapping.at(group_index[i]) - 1, s[group_index[i]*2]);
        for (int j=i; j>0; j--) {
            if (insert_idx <= index_mapping.at(group_index[j])) {
                index_mapping[group_index[j]]++;
            }
        }
    }
}


//int main(int argc, const char* argv[]) {
//    int N, Q;
//    std::string balls;
//    std::string sorted_balls;
//    
//    std::cin >> N >> Q;
//    for (int i = 0; i < N; i++) {
//        balls += (char)('A' + i);
//    }
//
//    merge_insertion_sort(balls, N, sorted_balls);
//    printf("! %s\n", sorted_balls.c_str());
//    fflush(stdout);
//    
//}
