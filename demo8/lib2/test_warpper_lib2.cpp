#include "test_warpper_lib2.h"
#include "test.h"
#include <iostream>

void test1_lib2()
{
    std::cout<<"test1_lib2 ......"<<std::endl;
    test1();
}

int test2_lib2(int a, int b)
{
    std::cout<<"test2_lib2 ......"<<std::endl;
    return test2(a,b);
}