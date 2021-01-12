#include "test_warpper_lib1.h"
#include <iostream>

int main(int argc, char const *argv[])
{
    int a = test2_lib1(1, 2);
    std::cout << "a: " << a << std::endl;
    return 0;
}
