#include <iostream>
/*
基类的虚构函数必须是虚函数
否则 将子类指针赋值给基类指针的时候 在析构时
只会只会基类的函数，
不会执行子类的析构函数，这样会导致子类资源得不到释放
*/
class Base1
{
private:
public:
    Base1();
    virtual ~Base1();
};

Base1::Base1()
{
    std::cout << "Base1() ......" << std::endl;
}

Base1::~Base1()
{
    std::cout << "~Base1() ......" << std::endl;
}

class E_Base : public Base1
{
private:
public:
    E_Base();
    ~E_Base();
};

E_Base::E_Base()
{
    std::cout << "E_Base() ......" << std::endl;
}

E_Base::~E_Base()
{
    std::cout << "~E_Base() ......" << std::endl;
}

int main(int argc, char const *argv[])
{
    Base1 *p = new Base1();
    delete p;
    std::cout << "*******" << std::endl;
    E_Base *p1 = new E_Base();
    delete p1;
    std::cout << "++++++++" << std::endl;
    Base1 *p2 = new E_Base();
    delete p2;
    return 0;
}
