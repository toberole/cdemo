#include <memory>
#include "A.h"
#include <iostream>

class A2;
class A1
{
private:
    std::shared_ptr<A2> sp;

public:
    A1(A2 *p)
    {
        sp = std::shared_ptr<A2>(p);
        std::cout << "A1 ......" << std::endl;
    }
    ~A1()
    {
        std::cout << "~A1 ......" << std::endl;
    }
};

class A2
{
private:
    // A1 A2 存在循环引用
    // std::shared_ptr<A1> sp;
    // 使用weak_ptr 解决A1 A2 循环引用 在A1和A2中任意一个使用std::weak_ptr都可以
    std::weak_ptr<A1> wp;

public:
    A2(A1 *p)
    {
        wp = std::shared_ptr<A1>(p);
        std::cout << "A2 ......" << std::endl;
    }

    ~A2()
    {
        std::cout << "~A2 ......" << std::endl;
    }
};

int main(int argc, char const *argv[])
{
    std::cout << "test ptr ......" << std::endl;

    // auto_ptr
    std::auto_ptr<A> a1(new A());
    a1->sys();
    // a1 失去所有权 后续如果再使用a1会出现不确定性
    std::auto_ptr<A> a2 = a1;
    a2->sys();
    // 会出现不确定性
    // a1->sys();

    // unique_ptr
    std::unique_ptr<A> a3(new A());
    // error
    // std::unique_ptr<A> a4 = a3;
    // a3 所有权转移到 a4,后续不建议再使用a3
    std::unique_ptr<A> a4 = std::move(a3);
    a4->sys();
    // 不要再使用a3 会出现不确定问题
    // a3->sys();

    // shared_ptr
    std::shared_ptr<A> a5(new A());
    std::shared_ptr<A> a6 = a5;
    a5->sys();
    a6->sys();

    // weak_ptr
    // 用于解决share_ptr 循环引用导致的问题
    std::shared_ptr<A> a7(new A());
    std::weak_ptr<A> a8 = a7;
    if (!a8.expired())
    {
        std::shared_ptr<A> a9 = a8.lock();
        a9->sys();
    }
    else
    {
        std::cout << "对象已经销毁了 ......" << std::endl;
    }

    //

    return 0;
}
