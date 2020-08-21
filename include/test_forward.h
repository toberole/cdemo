#ifndef PROJECT_TEST_FORWARD_H
#define PROJECT_TEST_FORWARD_H


#include<iostream>

using namespace std;

template<typename T>
void print(T &t) {
    cout << "lvalue" << endl;
}

template<typename T>
void print(T &&t) {
    cout << "rvalue" << endl;
}

template<typename T>
void TestForward(T &&v) {
    // 编译错误  不知道是哪个print
    //  print(v);
    print(std::forward<T>(v));
    print(std::move(v));
}

#endif //PROJECT_TEST_FORWARD_H
