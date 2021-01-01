#include "Demo2.h"
#include <iostream>

Demo2::Demo2() {
    std::cout << "默认构造函数" << std::endl;
}

Demo2::Demo2(const Demo2 &demo2) {
    std::cout << "拷贝构造函数" << std::endl;
}

Demo2::Demo2(const Demo2 &&demo2) {
    std::cout << "移动构造函数" << std::endl;
}

Demo2 Demo2::operator=(const Demo2 &demo2) {
    std::cout << "赋值运算符" << std::endl;
}

Demo2::~Demo2() {
    std::cout << "析构函数" << std::endl;
}