#include <iostream>

class B
{
private:
    int *p;

public:
    B()
    {
        this->p = nullptr;
        std::cout << "构造函数 1 ......" << std::endl;
    }

    // 构造函数
    B(int *p)
    {
        this->p = p;
        std::cout << "构造函数 2 ......" << std::endl;
    }

    // 拷贝构造函数
    B(const B &other)
    {
        p = other.p;
        std::cout << "拷贝构造函数 ......" << std::endl;
    }

    // C++11 移动拷贝构造函数
    B(B &&other)
    {
        p = other.p;
        other.p = nullptr;
        std::cout << "移动拷贝构造函数 ......" << std::endl;
    }

    // 赋值运算符
    B &operator=(const B &other)
    {
        p = other.p;
        std::cout << "赋值运算符 ......" << std::endl;
        return *this;
    }

    // C++11 移动赋值运算符
    B &operator=(B &&other)
    {
        p = other.p;
        other.p = nullptr;
        std::cout << "移动赋值运算符 ......" << std::endl;
        return *this;
    }

    // 析构函数
    ~B()
    {
        std::cout << "析构函数 ......" << std::endl;
    }
};
