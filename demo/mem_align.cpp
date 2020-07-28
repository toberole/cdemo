#include <iostream>

// 注意内存对齐系数一般与平台的对应的位数相关
// 比如64位 对齐系数默认是8
// 32位默认对齐系数是4
// #pragma pack(16) // 自定义设定对齐系数为16

struct Test {
    char x1;
    double x2;
    short x3;
    float x4;
    char x5;
};

int main() {
    std::cout << "double size: " << sizeof(double) << std::endl;
    std::cout << "short size: " << sizeof(short) << std::endl;
    std::cout << "float size: " << sizeof(float) << std::endl;
    std::cout << "Test size: " << sizeof(Test) << std::endl;
    return 0;
}