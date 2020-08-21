//
// Created by Apple on 2020/8/21.
//

#ifndef PROJECT_EMPTY_CLASS_H
#define PROJECT_EMPTY_CLASS_H

/**
 * 在 C++ 中规定类的大小不为 0，空类大小为 1，
 * 当类不包含虚函数和非静态成员时，其对象大小也为 1。
 * 若存在虚函数，则需要存储一个虚函数指针大小，在 32 位上为 4 字节。
 */
class EmptyClass {
public:
    // 静态成员
    static int n;

};

int EmptyClass::n = 0;

#endif //PROJECT_EMPTY_CLASS_H
