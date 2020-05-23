//
//  main.cpp
//  learningCplusplus
//
//  Created by Tran Duc Chinh on 2020/03/13.
//  Copyright © 2020 Tran Duc Chinh. All rights reserved.
//

#include <iostream>
#include <cstring>

class string {
    
    
public:
    char* data;
    string(const char* p) {
        size_t size = std::strlen(p) + 1;
        data = new char[size];
        std::memcpy(data, p, size);
    }
    // destructor
    ~string() {
        delete[] data;
    }
    // copy constructor
    string(const string& that) { // & reference to lvalue
        size_t size = std::strlen(that.data) + 1;
        data = new char[size];
        std::memcpy(data, that.data, size);
    }
    // move constructor
    string(string&& that) { // && reference to rvalue
        data = that.data;
        that.data = nullptr;
    }
    // copy assignment operator
    string& operator=(string that) {
        std::swap(data, that.data);
        return *this;
    }
};

//int main(int argc, const char *argv[]) {
//    string str1 = "Hello World\n";
//    string str2 = "then good by\n";
//    string* p = &str1;
//    p = &str2;
//    string a(*p);
//    std::cout << a.data << std::endl;
//    return 0;
//}
