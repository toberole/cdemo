#ifndef PROJECT_OFFSETOF_H
#define PROJECT_OFFSETOF_H

#define offsetof(TYPE, MEMBER) ((size_t) &((TYPE*)0)->MEMBER)
/*
(TYPE*)0 将零转型成 TYPE 类型指针
((TYPE*)0->MEMBER) 访问结构体中的成员
&((TYPE*)0->MEMBER) 取出数据成员地址，也就是相对于零的偏移量
(size_t) & ((TYPE*)0)->MEMBER) 将结果转换成 size_t 类型。
*/

struct Node {
    char a;
    short b;
    double c;
    int d;
};

#endif //PROJECT_OFFSETOF_H
