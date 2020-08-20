#include "B.h"

int main(int argc, char const *argv[])
{
    int *a = new int;
    *a = 1;
    B b1(a);
    B b2(a);
    // 触发赋值运算符
    b2 = b1;

    B b3(a);
    b3 = std::move(b2);
    return 0;
}
