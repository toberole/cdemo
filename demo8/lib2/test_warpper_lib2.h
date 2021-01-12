#pragma once

#ifdef _cpluscplus
extern "C"{
#endif

__attribute__ ((visibility("default"))) void test1_lib2();

__attribute__ ((visibility("default"))) int test2_lib2(int a,int b);

#ifdef _cpluscplus
}
#endif