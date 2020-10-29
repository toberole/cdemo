#include <iostream>

/*
    引用传递参数 本质上是传递的实参的地址
 */
void test1(int &i)
{
    i++; // 相当与通过指针操作实参 此处的修改会反应到实参上
}

void test2()
{
    int i = 0;
    test1(i);
    std::cout << "i = " << i << std::endl;
}

int main(int argc, char const *argv[])
{

    test2();

    return 0;
}
