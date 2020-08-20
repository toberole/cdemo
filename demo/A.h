#include <iostream>

class A
{
private:
    int n;

public:
    A();
    ~A();
    void sys();

    A return_this_1();
    A &return_this_2();
};

A::A()
{
    std::cout << "A() ......" << std::endl;
}

void A::sys()
{
    std::cout << "sys() ......" << std::endl;
}

// 返回对象的副本
A A::return_this_1()
{
    return *this;
}

// 返回该对象本身
A &A::return_this_2()
{
    return *this;
}

A::~A()
{
    std::cout << "~A() ......" << std::endl;
}
