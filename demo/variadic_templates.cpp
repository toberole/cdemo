#include <iostream>

// 可变参数模版
template<class... T>
void f(T... args) {
    // 打印变参的个数
    std::cout << sizeof...(args) << std::endl;
}

void test1_vt(){
    f();
    f(1);
    f(1, 2);
}

int main() {

    return 0;
}