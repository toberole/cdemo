#pragma once

#ifdef _cpluscplus
extern "C"{
#endif

__attribute__ ((visibility("default"))) void test1_lib1();

__attribute__ ((visibility("default"))) int test2_lib1(int a,int b);

#ifdef _cpluscplus
}
#endif