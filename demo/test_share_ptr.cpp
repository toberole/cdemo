#include "A.h"
#include "my_share_ptr.cpp"

int main(int argc, char const *argv[])
{
    // 系统的智能指针
    A *a = new A();
    std::shared_ptr<A> pa = std::shared_ptr<A>(a);
    pa->sys();
    std::cout << "*************" << std::endl;
    // Shared_ptr
    A *a1 = new A();
    Shared_ptr<A> sp(a1);
    sp->sys();
    return 0;
}
