#include "test_warpper_lib1.h"
#include <iostream>

extern void test1();

extern int test2(int a,int b);

void test1_lib1()
{
    std::cout<<"test1_lib1 ......"<<std::endl;
    test1();
}

int test2_lib1(int a, int b)
{
    std::cout<<"test2_lib1 ......"<<std::endl;
    return test2(a,b);
}