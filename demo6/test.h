#pragma once

#ifdef _cpluscplus
extern "C"{
#endif

__attribute__ ((visibility("default"))) void test1();

__attribute__ ((visibility("default"))) int test2(int a,int b);

#ifdef _cpluscplus
}
#endif